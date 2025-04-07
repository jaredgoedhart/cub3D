/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:11:35 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 19:11:35 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/movement.h"

int	is_valid_position(const t_ctx *ctx,
	const float x, const float y)
{
	const float	buffer = 0.2f;
	int			points[4][2];
	int			i;

	points[0][0] = (int)(x - buffer);
	points[0][1] = (int)(y - buffer);
	points[1][0] = (int)(x + buffer);
	points[1][1] = (int)(y - buffer);
	points[2][0] = (int)(x - buffer);
	points[2][1] = (int)(y + buffer);
	points[3][0] = (int)(x + buffer);
	points[3][1] = (int)(y + buffer);
	i = 0;
	while (i < 4)
	{
		if (points[i][0] < 0 || points[i][0] >= ctx->map->width
			|| points[i][1] < 0 || points[i][1] >= ctx->map->height
			|| ctx->map->grid[points[i][1]][points[i][0]] == '1')
			return (VALID_POSITION);
		++i;
	}
	return (INVALID_POSITION);
}

void	handle_rotation(t_ctx *ctx)
{
	if (mlx_is_key_down(ctx->mlx_ptr, MLX_KEY_LEFT))
	{
		ctx->player.angle -= ROTATION_SPEED;
		if (ctx->player.angle < 0.0f)
			ctx->player.angle += 360.0f;
	}
	if (mlx_is_key_down(ctx->mlx_ptr, MLX_KEY_RIGHT))
	{
		ctx->player.angle += ROTATION_SPEED;
		if (ctx->player.angle >= 360.0f)
			ctx->player.angle -= 360.0f;
	}
}

void	move_forward_back(t_ctx *ctx, float *new_x, float *new_y)
{
	if (mlx_is_key_down(ctx->mlx_ptr, MLX_KEY_W))
	{
		*new_x = ctx->player.x + cos(ctx->player.angle * M_PI / 180.0f) \
			* MOVE_SPEED;
		*new_y = ctx->player.y + sin(ctx->player.angle * M_PI / 180.0f) \
			* MOVE_SPEED;
		if (is_valid_position(ctx, *new_x, *new_y))
		{
			ctx->player.x = *new_x;
			ctx->player.y = *new_y;
		}
	}
	if (mlx_is_key_down(ctx->mlx_ptr, MLX_KEY_S))
	{
		*new_x = ctx->player.x - cos(ctx->player.angle * M_PI / 180.0f) \
			* MOVE_SPEED;
		*new_y = ctx->player.y - sin(ctx->player.angle * M_PI / 180.0f) \
			* MOVE_SPEED;
		if (is_valid_position(ctx, *new_x, *new_y))
		{
			ctx->player.x = *new_x;
			ctx->player.y = *new_y;
		}
	}
}

void	move_left_right(t_ctx *ctx, float *new_x, float *new_y)
{
	if (mlx_is_key_down(ctx->mlx_ptr, MLX_KEY_A))
	{
		*new_x = ctx->player.x + cos((ctx->player.angle - 90.0f) \
			* M_PI / 180.0f) * MOVE_SPEED;
		*new_y = ctx->player.y + sin((ctx->player.angle - 90.0f) \
			* M_PI / 180.0f) * MOVE_SPEED;
		if (is_valid_position(ctx, *new_x, *new_y))
		{
			ctx->player.x = *new_x;
			ctx->player.y = *new_y;
		}
	}
	if (mlx_is_key_down(ctx->mlx_ptr, MLX_KEY_D))
	{
		*new_x = ctx->player.x + cos((ctx->player.angle + 90.0f) \
			* M_PI / 180.0f) * MOVE_SPEED;
		*new_y = ctx->player.y + sin((ctx->player.angle + 90.0f) \
			* M_PI / 180.0f) * MOVE_SPEED;
		if (is_valid_position(ctx, *new_x, *new_y))
		{
			ctx->player.x = *new_x;
			ctx->player.y = *new_y;
		}
	}
}

void	handle_keyboard_input(t_ctx *ctx)
{
	float	new_x;
	float	new_y;

	move_forward_back(ctx, &new_x, &new_y);
	move_left_right(ctx, &new_x, &new_y);
	handle_rotation(ctx);
	if (mlx_is_key_down(ctx->mlx_ptr, MLX_KEY_ESCAPE))
	{
		quit_ctx(ctx);
		exit(EXIT_SUCCESS);
	}
}
