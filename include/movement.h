/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:42:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 18:53:56 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H

# define MOVEMENT_H

# include "_common.h"

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                                MOVEMENT                                    */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////

/**
* Checks if a position is valid for player movement.
* Validates position against walls and map boundaries.
*
* @param[in] cub3d Game structure with map data
* @param[in] x X-coordinate to check
* @param[in] y Y-coordinate to check
* @return int VALID_POSITION if valid, INVALID_POSITION otherwise
*/
int				is_valid_position(const t_ctx *cub3d,
					const float x, const float y);

///////////////////////////////////////////////////////////////////////////////

/**
* Handles player rotation input.
* Processes left/right arrow keys for camera rotation.
*
* @param[in,out] cub3d Game structure with player data
*/
void			handle_rotation(t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
* Handles forward/backward movement.
* Processes W/S keys for player movement.
*
* @param[in,out] cub3d Game structure with player data
* @param[out] new_x New x-coordinate after movement
* @param[out] new_y New y-coordinate after movement
*/
void			move_forward_back(t_ctx *cub3d, float *new_x, float *new_y);

///////////////////////////////////////////////////////////////////////////////

/**
* Handles lateral movement.
* Processes A/D keys for sideways movement.
*
* @param[in,out] cub3d Game structure with player data
* @param[out] new_x New x-coordinate after movement
* @param[out] new_y New y-coordinate after movement
*/
void			move_left_right(t_ctx *cub3d, float *new_x, float *new_y);

///////////////////////////////////////////////////////////////////////////////

/**
 * Processes keyboard input for player movement and game controls.
 * Handles WASD movement, arrow key rotation, and ESC to quit.
 *
 * @param[in,out] cub3d Game structure containing player data
 */
void			handle_keyboard_input(t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

#endif
