/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:47:50 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 19:10:39 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXIT_H

# define _EXIT_H

# include "_exceptions.h"
# include "_structs.h"
# include "_consts.h"

# include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/*                                    EXIT                                    */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////

/**
* Deallocates map structure and its grid.
* Frees all memory associated with map data.
*
* @param[in] map Map structure to be freed
*/
void			free_map_struct(t_map *map);

///////////////////////////////////////////////////////////////////////////////

/**
* Frees all MLX texture resources.
* Deletes all wall and sprite textures.
*
* @param[in] ctx Game structure containing textures
*/
void			free_mlx_textures(const t_ctx *ctx);

///////////////////////////////////////////////////////////////////////////////

/**
* Main cleanup function for the program.
* Frees all allocated resources and terminates MLX.
*
* @param[in] ctx Main game structure to clean up
*/
void			quit_ctx(t_ctx *ctx);

///////////////////////////////////////////////////////////////////////////////

#endif
