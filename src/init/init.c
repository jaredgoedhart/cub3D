/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:52:21 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 18:52:21 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/init.h"

t_ctx	*initialize_struct(void)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)malloc(sizeof(t_ctx));
	if (ctx == NULL)
		return (ft_putstr_fd(MALLOC_ERROR, 2), NULL);
	ctx->mlx_ptr = NULL;
	ctx->win_ptr = NULL;
	ctx->img_ptr = NULL;
	ctx->img_data = NULL;
	ctx->map = NULL;
	ctx->textures.north = NULL;
	ctx->textures.south = NULL;
	ctx->textures.east = NULL;
	ctx->textures.west = NULL;
	ctx->textures.sprite = NULL;
	ctx->window_width = 0;
	ctx->window_height = 0;
	ctx->floor_color = 0;
	ctx->ceiling_color = 0;
	return (ctx);
}

void	initialize_player_direction(t_ctx *ctx)
{
	if (ctx->map->player_dir == 'N')
		ctx->player.angle = 270.0f;
	else if (ctx->map->player_dir == 'S')
		ctx->player.angle = 90.0f;
	else if (ctx->map->player_dir == 'E')
		ctx->player.angle = 0.0f;
	else if (ctx->map->player_dir == 'W')
		ctx->player.angle = 180.0f;
	else
	{
		ft_putstr_fd(PLAYER_DIRECTION_ERROR, 2);
		return ;
	}
	ctx->player.x = ctx->map->player_x + 0.5f;
	ctx->player.y = ctx->map->player_y + 0.5f;
}

int	initialize_mlx42(t_ctx *ctx)
{
	ctx->mlx_ptr = mlx_init(ctx->window_width, ctx->window_height, \
		"ctx", true);
	if (ctx->mlx_ptr == NULL)
		return (ft_putstr_fd(MLX_INIT_ERROR, 2), FAILURE);
	ctx->img_ptr = mlx_new_image(ctx->mlx_ptr, \
		ctx->window_width, ctx->window_height);
	if (ctx->img_ptr == NULL)
		return (ft_putstr_fd(IMAGE_CREATION_ERROR, 2), FAILURE);
	if (mlx_image_to_window(ctx->mlx_ptr, ctx->img_ptr, 0, 0) == -1)
		return (ft_putstr_fd(IMAGE_TO_WINDOW_ERROR, 2), FAILURE);
	return (EXIT_SUCCESS);
}

int	initialize_simulation(t_ctx **ctx, void (*f)(void *))
{
	if (initialize_mlx42(*ctx) == FAILURE)
		return (FAILURE);
	if (!mlx_loop_hook((*ctx)->mlx_ptr, f, *ctx))
		return (ft_putstr_fd(MLX_LOOP_HOOK_ERROR, 2), FAILURE);
	return (EXIT_SUCCESS);
}
