/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:10:18 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 19:10:18 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/_exit.h"

void	free_map_struct(t_map *map)
{
	int	i;

	i = 0;
	while (i < MAX_MAP_HEIGHT)
		free(map->grid[i++]);
	free(map->grid);
	free(map);
}

void	free_mlx_textures(const t_ctx *ctx)
{
	if (ctx->textures.north)
		mlx_delete_texture(ctx->textures.north);
	if (ctx->textures.south)
		mlx_delete_texture(ctx->textures.south);
	if (ctx->textures.east)
		mlx_delete_texture(ctx->textures.east);
	if (ctx->textures.west)
		mlx_delete_texture(ctx->textures.west);
}

void	quit_ctx(t_ctx *ctx)
{
	if (!ctx)
		return ;
	free_mlx_textures(ctx);
	if (ctx->img_ptr)
		mlx_delete_image(ctx->mlx_ptr, ctx->img_ptr);
	if (ctx->mlx_ptr)
		mlx_terminate(ctx->mlx_ptr);
	if (ctx->map)
		free_map_struct(ctx->map);
	free(ctx);
}
