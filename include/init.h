/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:27:12 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 18:53:35 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H

# define INIT_H

# include "_common.h"

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                               INITIALIZE                                   */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////

/**
 * Initializes and allocates memory for the main game structure.
 * Sets all pointers to NULL and initializes all values to 0.
 *
 * @return t_ctx* Pointer to the initialized structure,
 * NULL if allocation fails
 */
t_ctx			*initialize_struct(void);

///////////////////////////////////////////////////////////////////////////////

/**
 * Sets the initial player direction and position based on map configuration.
 * Converts N/S/E/W map character to corresponding angle value.
 *
 * @param[out] cub3d Game structure containing player and map data
 */
void			initialize_player_direction(t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
 * Parses and validates the .cub file configuration.
 * Initializes textures, window dimensions, and colors.
 *
 * @param[in] cub_file_path Path to the .cub configuration file
 * @param[out] cub3d Pointer to the game structure to initialize
 * @return int EXIT_SUCCESS on success, FAILURE on error
 */
int				initialize_parameters(const char *cub_file_path,
					t_ctx **cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
* Sets up the graphics window and creates image for rendering.
* Creates a window and sets up everything needed to start displaying graphics.
*
* @param[out] cub3d Main game struct that will store window and image info
* @return int EXIT_SUCCESS if everything works, FAILURE if something goes wrong
*/
int				initialize_mlx42(t_ctx *cub3d);

///////////////////////////////////////////////////////////////////////////////

/**
 * Initializes the MLX window and graphics components.
 * Creates window, images, and sets up the game loop hook.
 *
 * @param[in,out] cub3d Pointer to game structure
 * @return int EXIT_SUCCESS on success, FAILURE on error
 */
int				initialize_simulation(t_ctx **ctx, void (*f)(void *));

///////////////////////////////////////////////////////////////////////////////

#endif
