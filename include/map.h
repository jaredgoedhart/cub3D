/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:29:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 18:53:48 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include "_common.h"

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                                MAP PARSING                                 */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////

/**
 * Deallocates all memory associated with the map structure.
 * Frees the 2D grid and all its rows.
 *
 * @param[in] map Map structure to be freed
 */
void			free_map(const t_map *map);

///////////////////////////////////////////////////////////////////////////////

/**
 * Allocates memory for the map structure and initializes grid.
 * Creates a 2D char array of size MAX_MAP_HEIGHT x MAX_MAP_WIDTH.
 *
 * @param[out] map Map structure to allocate memory for
 * @return int 1 on successful allocation, 0 on failure
 */
int				allocate_map(t_map *map);

///////////////////////////////////////////////////////////////////////////////

/**
 * Fills the map structure with data from the input file.
 * Processes file content and sets map dimensions.
 *
 * @param[in] fd File descriptor of the input file
 * @param[out] map Map structure to fill
 */
void			fill_map(const int fd, t_map *map);

///////////////////////////////////////////////////////////////////////////////

/**
 * Validates the map content for game requirements.
 * Checks map dimensions, player count, and map boundaries.
 *
 * @param[in,out] map Map structure to validate
 * @return int 1 if map is valid, 0 if validation fails
 */
int				validate_map_content(t_map *map);

///////////////////////////////////////////////////////////////////////////////

/**
 * Parses and validates the map file.
 * Main function for map processing that coordinates all map-related operations.
 *
 * @param[in] file_path Path to the map file
 * @param[out] cub3d Main game structure to store the map
 * @return int EXIT_SUCCESS on success, FAILURE on error
 */
int				parse_map(const char *file_path, t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
* Removes newline and carriage return characters from a line.
* Calculates clean line length without line endings.
*
* @param[in] line String to clean
* @return int Length of cleaned line
*/
int				clean_line(const char *line);

///////////////////////////////////////////////////////////////////////////////

/**
* Processes a single line of the map file.
* Copies line content to map grid with proper padding.
*
* @param[out] map Map structure to update
* @param[in] line Line content to process
* @param[in] line_len Length of line to process
* @param[in] y Vertical position in map grid
*/
void			process_map_line(const t_map *map, const char *line,
					const uint16_t line_len, const uint16_t y);

///////////////////////////////////////////////////////////////////////////////

/**
* Reads and frees remaining lines from file.
* Ensures all file content is properly handled.
*
* @param[in] fd File descriptor to read from
*/
void			clean_remaining_lines(const int fd);

///////////////////////////////////////////////////////////////////////////////

/**
* Updates maximum width and processes current map line.
* Coordinates line processing and map dimension tracking.
*
* @param[in,out] map Map structure to update
* @param[in] line Current line to process
* @param[in] info Line information structure
*/
void			update_max_and_process(const t_map *map, const char *line,
					const t_line_info *info);

///////////////////////////////////////////////////////////////////////////////

/**
* Processes all lines from file to build map.
* Main parsing function for map file content.
*
* @param[in] fd File descriptor to read from
* @param[out] map Map structure to fill
* @param[out] max_width Pointer to track maximum line width
*/
void			process_file_lines(const int fd, t_map *map,
					uint16_t *max_width);

///////////////////////////////////////////////////////////////////////////////

/**
* Checks if the map contains any sprite characters ('2').
* Scans through entire map grid to find sprites.
*
* @param[in] map Map structure to check for sprites
* @return bool true if sprites found, false otherwise
*/
bool			has_sprites_in_map(const t_map *map);

///////////////////////////////////////////////////////////////////////////////

/**
* Determines if a line contains map configuration elements.
* Checks for texture identifiers and color settings.
*
* @param[in] line Line to check for configuration elements
* @return bool true if line is a config line, false otherwise
*/
bool			is_config_line(const char *line);

///////////////////////////////////////////////////////////////////////////////

/**
* Checks if a line contains a wall character ('1').
* Used to validate map boundaries.
*
* @param[in] line Line to check for wall characters
* @param[in] len Length of the line to check
* @return bool true if wall found, false otherwise
*/
bool			has_wall_in_line(const char *line, const int len);

///////////////////////////////////////////////////////////////////////////////

/**
* Determines if a line should be skipped during map parsing.
* Checks for configuration lines and empty lines before map start.
*
* @param[in] map_started Flag indicating if map parsing has begun
* @param[in] line Current line being processed
* @param[in] line_len Length of the current line
* @return bool true if line should be skipped, false otherwise
*/
bool			should_skip_line(const bool map_started, const char *line,
					const int line_len);

///////////////////////////////////////////////////////////////////////////////

/**
* Validates if a character is allowed in the map.
* Checks for walls, spaces, sprites and player positions.
*
* @param[in] c Character to validate
* @return int 1 if character is valid, 0 otherwise
*/
int				is_valid_char(const char c);

///////////////////////////////////////////////////////////////////////////////

/**
* Validates map content position in file.
* Ensures map is the last element and has no empty lines.
*
* @param[in] file_path Path to map file
* @return int 1 if map position is valid, 0 otherwise
*/
int				validate_last_char(const char *file_path);

///////////////////////////////////////////////////////////////////////////////

/**
* Checks surrounding cells of a position.
* Validates map boundaries around a given coordinate.
*
* @param[in] map Map structure to check
* @param[in] x X-coordinate to check
* @param[in] y Y-coordinate to check
* @return int 1 if surroundings are valid, 0 otherwise
*/
int				check_surroundings(const t_map *map, const int x, const int y);

///////////////////////////////////////////////////////////////////////////////

/**
* Validates a specific position in the map.
* Checks for valid placement of walls, spaces and player.
*
* @param[in] map Map structure to check
* @param[in] x X-coordinate to check
* @param[in] y Y-coordinate to check
* @param[in] current Current character at position
* @return int 1 if position is valid, 0 otherwise
*/
int				check_position(const t_map *map, const int x, const int y,
					const char current);

///////////////////////////////////////////////////////////////////////////////

/**
* Processes a single cell in the map.
* Updates player count and position if player character found.
*
* @param[in,out] map Map structure to update
* @param[in] y Y-coordinate of cell
* @param[in,out] player_count Pointer to player count
* @return int 1 if cell is valid, 0 otherwise
*/
int				process_cell(t_map *map, int y, int *player_count);

///////////////////////////////////////////////////////////////////////////////

#endif
