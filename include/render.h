/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:46:07 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 18:54:12 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H

# define RENDER_H

# include "_common.h"

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                                 RENDER                                     */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////
/**
 * Collects and processes sprite information from the map.
 * Identifies, positions, and sorts sprites for rendering.
 *
 * @param[in] cub3d Game structure containing map data
 * @param[in,out] sprites Array to store sprite information
 * @return int Number of sprites found in the map
 */
int				collect_sprites(const t_ctx *cub3d, t_sprite *sprites);

///////////////////////////////////////////////////////////////////////////////

/**
 * Draws a textured wall slice for a specific ray.
 * Calculates wall slice position and applies appropriate texture.
 *
 * @param[in] cub3d Game structure with rendering context
 * @param[in] ray Ray information for wall rendering
 * @param[in] x Screen x-coordinate for wall slice
 */
void			draw_textured_wall(const t_ctx *cub3d, const t_ray ray,
					const int x);

///////////////////////////////////////////////////////////////////////////////

/**
 * Implements raycasting algorithm for 3D rendering.
 * The core of the program.
 * Projects walls and sprites based on player position and direction.
 *
 * @param[in] cub3d Game structure containing map and player data
 */
void			cast_rays(const t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
 * Renders a single frame of the game.
 * Draws floor/ceiling colors and calls raycasting for walls.
 *
 * @param[in] cub3d Game structure containing rendering data
 */
void			render_frame(const t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
 * Starts the main game loop.
 * Continuously renders frames until game exit.
 *
 * @param[in] cub3d Game structure
 * @return int EXIT_SUCCESS on normal exit, FAILURE on error
 */
int				start_simulation(const t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                      RENDER_UTILS_CALCULATIONS                             */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////
/**
 * Normalizes an angle to be within the range -π to π.
 * Ensures angle wraps correctly for trigonometric calculations.
 *
 * @param[in] angle Angle to normalize in radians
 * @return float Normalized angle
 */
float			normalize_angle(float angle);
///////////////////////////////////////////////////////////////////////////////

/**
 * Sets sprite's position to the center of its map grid cell.
 * Adjusts raw grid coordinates to precise world coordinates.
 *
 * @param[in,out] sprite Sprite object to update
 * @param[in] x X-coordinate of sprite in map grid
 * @param[in] y Y-coordinate of sprite in map grid
 */
void			calculate_sprite_position(t_sprite *sprite, const int x,
					const int y);
///////////////////////////////////////////////////////////////////////////////

/**
 * Calculates sprite's angle, distance, and visibility relative to player.
 * Determines if sprite is within the player's field of view.
 *
 * @param[in,out] sprite Sprite object to update
 * @param[in] cub3d Game structure containing player information
 * @param[in] player_angle Current player angle in radians
 */
void			calculate_sprite_angles(t_sprite *sprite, const t_ctx *cub3d,
					const float player_angle);
///////////////////////////////////////////////////////////////////////////////

/**
 * Initializes ray traversal variables for raycasting.
 * Sets up initial ray position, direction, and grid tracking parameters.
 *
 * @param[out] vars Ray traversal variables to initialize
 * @param[in] ray_angle Current ray's angle
 * @param[in] player Player position and orientation
 */
void			init_ray_vars(t_ray_vars *vars, const float ray_angle,
					const t_player player);
///////////////////////////////////////////////////////////////////////////////

/**
 * Determines wall texture and horizontal texture coordinate.
 * Calculates which wall texture to use based on ray hit direction.
 *
 * @param[in,out] ray Ray object to update with texture information
 * @param[in] vars Ray traversal variables
 */
void			set_tex_and_wall_x(t_ray *ray, const t_ray_vars *vars);

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                        RENDER_UTILS_DRAWING                                */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////
/**
 * Extracts pixel color from a texture at specific coordinates.
 * Converts texture pixel data to a 32-bit RGBA color value.
 *
 * @param[in] tex Texture containing pixel data
 * @param[in] tex_x X-coordinate within texture
 * @param[in] tex_y Y-coordinate within texture
 * @return uint32_t Pixel color in RGBA format
 */
uint32_t		get_pixel_color(const mlx_texture_t *tex, const int tex_x,
					const int tex_y);

///////////////////////////////////////////////////////////////////////////////

/**
 * Draws a vertical slice of a textured wall.
 * Renders a single column of wall texture onto the screen.
 *
 * @param[in] cub3d Game structure with rendering context
 * @param[in] ray Ray information for wall rendering
 * @param[in] tex Wall texture to apply
 * @param[in] wall Wall slice rendering parameters
 */
void			draw_wall_slice(const t_ctx *cub3d, const t_ray ray,
					const mlx_texture_t *tex, const t_wall wall);

///////////////////////////////////////////////////////////////////////////////
/**
 * Retrieves pixel color from sprite texture with transparency handling.
 * Extracts RGBA color, ignoring fully transparent pixels.
 *
 * @param[in] tex Sprite texture containing pixel data
 * @param[in] pixel_x X-coordinate within texture
 * @param[in] pixel_y Y-coordinate within texture
 * @return uint32_t Pixel color in RGBA format, 0 if fully transparent
 */
uint32_t		get_sprite_color(const mlx_texture_t *tex, const int pixel_x,
					const int pixel_y);
///////////////////////////////////////////////////////////////////////////////

/**
 * Draws a vertical stripe of a sprite texture.
 * Renders a single column of sprite with transparency support.
 *
 * @param[in] cub3d Game structure with rendering context
 * @param[in] info Sprite drawing information
 */
void			draw_sprite_stripe(const t_ctx *cub3d,
					const t_draw_info *info);
///////////////////////////////////////////////////////////////////////////////

/**
 * Draws a sprite at its calculated screen position.
 * Handles sprite rendering, position, and visibility calculations.
 *
 * @param[in] cub3d Game structure with rendering context
 * @param[in] sprite Sprite object to render
 * @param[in] x Screen x-coordinate for sprite
 * @param[in] ray_angle Current ray angle for perspective calculation
 */
void			draw_sprite(const t_ctx *cub3d, const t_sprite *sprite,
					const int x, const float ray_angle);

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                     RENDER_UTILS_RAYCASTING                                */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////

/**
 * Calculates the side distances for ray traversal.
 * Determines initial ray distances to next grid lines.
 *
 * @param[in,out] vars Ray traversal variables
 */
void			calc_side_dist(t_ray_vars *vars);

///////////////////////////////////////////////////////////////////////////////

/**
 * Sets the wall distance based on ray hit side.
 * Calculates precise wall distance for rendering.
 *
 * @param[in] ray Ray information
 * @param[in] vars Ray traversal variables
 * @param[out] wall_distance Pointer to store calculated wall distance
 */
void			set_wall_distance(const t_ray *ray, const t_ray_vars *vars,
					float *wall_distance);

///////////////////////////////////////////////////////////////////////////////

/**
 * Updates ray traversal variables for Digital Differential Analysis (DDA).
 * Moves ray to next grid line and determines wall hit side.
 *
 * @param[in,out] vars Ray traversal variables
 * @param[in,out] ray Ray information
 */
void			update_dda_vars(t_ray_vars *vars, t_ray *ray);

///////////////////////////////////////////////////////////////////////////////

/**
 * Checks if current map position contains a wall.
 * Validates map boundaries and wall presence.
 *
 * @param[in] vars Ray traversal variables
 * @param[in] map Map structure
 * @return int 1 if wall is hit, 0 otherwise
 */
int				check_wall_hit(const t_ray_vars *vars, const t_map *map);

///////////////////////////////////////////////////////////////////////////////

/**
 * Performs Digital Differential Analysis (DDA) for ray traversal.
 * Traces ray through grid until wall is hit or map boundary is reached.
 *
 * @param[in,out] vars Ray traversal variables
 * @param[in,out] ray Ray information
 * @param[in] map Map structure
 * @param[out] wall_distance Pointer to store calculated wall distance
 */
void			perform_dda(t_ray_vars *vars, t_ray *ray, const t_map *map,
					float *wall_distance);

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                       RENDER_UTILS_SORTING                                 */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////

/**
 * Sorts sprites in descending order of distance from player.
 * Uses bubble sort algorithm to order sprites for correct rendering.
 *
 * @param[in,out] sprites Array of sprites to sort
 * @param[in] count Number of sprites in the array
 */
void			sort_sprites(t_sprite *sprites, const int count);

///////////////////////////////////////////////////////////////////////////////

/**
 * Retrieves the appropriate wall texture based on hit side.
 * Maps texture number to corresponding texture pointer.
 *
 * @param[in] cub3d Game structure containing textures
 * @param[in] tex_num Texture number to retrieve
 * @return mlx_texture_t* Pointer to the selected texture
 */
mlx_texture_t	*get_wall_texture(const t_ctx *cub3d, const int tex_num);

///////////////////////////////////////////////////////////////////////////////

/**
 * Processes a single row of the map to collect sprite information.
 * Identifies and catalogs sprites in the current map row.
 *
 * @param[in] cub3d Game structure containing map data
 * @param[in,out] sprites Array to store sprite information
 * @param[in] y Current row (y-coordinate) being processed
 * @param[in] player_angle Current player angle in radians
 * @return int Number of sprites found in this row
 */
int				process_map_row(const t_ctx *cub3d, t_sprite *sprites,
					const int y, const float player_angle);

///////////////////////////////////////////////////////////////////////////////

/**
 * Calculates wall properties for a specific ray.
 * Computes wall distance, height, and texture mapping details.
 *
 * @param[in,out] ray Ray object to update with wall information
 * @param[in] vars Ray traversal variables
 * @param[in] ray_angle Current ray's angle
 * @param[in] cub3d Game structure
 */
void			calc_wall_props(t_ray *ray, const t_ray_vars *vars,
					const float ray_angle, const t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////
/**
 * Draws sprites visible for the current ray.
 * Renders sprites within the ray's field of view.
 *
 * @param[in] cub3d Game structure
 * @param[in] sprites Array of sprite information
 * @param[in] sprite_count Total number of sprites
 * @param[in] rc Ray casting information
 */
void			draw_sprites_for_ray(const t_ctx *cub3d,
					const t_sprite *sprites, const int sprite_count,
					const t_ray_casting *rc);

///////////////////////////////////////////////////////////////////////////////

#endif
