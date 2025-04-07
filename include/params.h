/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:39:08 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 18:54:05 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H

# define PARAMS_H

# include "_common.h"

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                                PARAMETERS                                  */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////

/**
* Main parameter initialization function.
* Processes the configuration file and sets up game parameters.
*
* @param[in] cub_file_path Path to configuration file
* @param[out] cub3d Game structure to initialize
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				initialize_parameters(const char *cub_file_path,
					t_ctx **cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
* Processes a single line from the configuration file.
* Handles texture, resolution, and color parsing.
*
* @param[in] line Current line to process
* @param[out] cub3d Main game structure to update
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				process_line(const char *line, t_ctx **cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
* Validates and opens the configuration file.
* Checks file extension and accessibility.
*
* @param[in] cub_file_path Path to configuration file
* @param[out] fd Pointer to store file descriptor
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				validate_and_open_file(const char *cub_file_path, int *fd);

///////////////////////////////////////////////////////////////////////////////

/**
* Parses texture information from config file.
* Sets up each texture (north, south, east, west) and sprite.
*
* @param[in] line Line containing texture information
* @param[out] cub3d Main game structure to store textures
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				parse_textures(const char *line, t_ctx **cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
* Extracts and cleans texture path from configuration line.
* Removes whitespace and line endings.
*
* @param[in] line Line containing texture path
* @param[out] path Pointer to store cleaned path
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				parse_texture_path(const char *line, char **path);

///////////////////////////////////////////////////////////////////////////////

/**
* Parses color information for floor and ceiling.
* Validates and converts RGB values to uint32_t format.
*
* @param[in] line Line containing color information
* @param[out] color Pointer to store final color value
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				parse_color(const char *line, uint32_t *color);

///////////////////////////////////////////////////////////////////////////////

/**
* Parses resolution settings from config file.
* Validates and sets window dimensions.
*
* @param[in] line Line containing resolution information
* @param[out] cub3d Main game structure to store dimensions
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				parse_resolution(const char *line, t_ctx **cub3d);

/**
* Sets texture pointer and tracks if already set.
* Prevents duplicate texture definitions.
*
* @param[in,out] texture Texture pointer to set
* @param[in,out] is_set Flag indicating if texture is already set
* @param[in] name Texture name for error messages
* @return mlx_texture_t** Pointer to texture or NULL if error
*/
mlx_texture_t	**set_texture(mlx_texture_t **texture, uint8_t *is_set,
					char *name);

///////////////////////////////////////////////////////////////////////////////

/**
* Gets appropriate texture pointer based on identifier.
* Maps NO/SO/WE/EA/S to corresponding texture pointers.
*
* @param[in] line Line containing texture identifier
* @param[out] cub3d Game structure containing textures
* @param[in,out] already_set Array tracking set textures
* @return mlx_texture_t** Pointer to appropriate texture or NULL
*/
mlx_texture_t	**get_texture_pointer(const char *line, t_ctx **cub3d,
					uint8_t *already_set);

///////////////////////////////////////////////////////////////////////////////

/**
* Loads texture from file using MLX42.
* Handles PNG loading and error checking.
*
* @param[out] texture_ptr Pointer to store loaded texture
* @param[in] path Path to texture file
* @return int EXIT_SUCCESS if successful, FAILURE otherwise
*/
int				load_texture(mlx_texture_t **texture_ptr, const char *path);

///////////////////////////////////////////////////////////////////////////////

/**
* Validates window resolution settings.
* Ensures dimensions are within acceptable ranges.
*
* @param[in,out] cub3d Game structure containing window dimensions
* @return int EXIT_SUCCESS if valid, FAILURE otherwise
*/
int				validate_resolution(t_ctx **cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
* Validates RGB color values.
* Ensures each component is between 0 and 255.
*
* @param[out] rgb_values Array to store validated values
* @param[in] rgb Array of string RGB values
* @return int EXIT_SUCCESS if valid, FAILURE otherwise
*/
int				check_rgb_values(uint8_t *rgb_values, char **rgb);

///////////////////////////////////////////////////////////////////////////////

/**
* Checks for empty RGB value entries.
* Ensures all three RGB components are present.
*
* @param[in] rgb Array of RGB value strings
* @return int EXIT_SUCCESS if valid, FAILURE otherwise
*/
int				check_empty_values(char **rgb);

///////////////////////////////////////////////////////////////////////////////

/**
* Checks for trailing commas in RGB format.
* Ensures proper RGB string formatting.
*
* @param[in] line Line containing RGB values
* @return int EXIT_SUCCESS if valid, FAILURE otherwise
*/
int				check_trailing_comma(const char *line);

///////////////////////////////////////////////////////////////////////////////

/**
* Validates presence and loading of all required textures.
* Checks for missing or improperly loaded textures.
*
* @param[in] cub3d Game structure containing textures
* @return int EXIT_SUCCESS if valid, FAILURE otherwise
*/
int				check_textures(t_ctx **cub3d);

#endif
