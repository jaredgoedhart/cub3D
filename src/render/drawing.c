/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:48:05 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:48:05 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"

uint32_t	get_pixel_color(const mlx_texture_t *tex, const int tex_x,
	const int tex_y)
{
	uint8_t		*pixel;

	pixel = &tex->pixels[(tex_y * tex->width + tex_x) * 4];
	return ((pixel[0] << 24) | (pixel[1] << 16)
		| (pixel[2] << 8) | pixel[3]);
}

void	draw_wall_slice(const t_ctx *ctx, const t_ray ray,
	const mlx_texture_t *tex, const t_wall wall)
{
	int			y;
	int			tex_y;
	double		pos;

	y = wall.start;
	while (y < wall.end)
	{
		pos = (y - wall.start) / (double)ray.wall_height;
		tex_y = (int)(pos * tex->height);
		mlx_put_pixel(ctx->img_ptr, wall.x,
			y, get_pixel_color(tex, wall.tex_x, tex_y));
		++y;
	}
}

uint32_t	get_sprite_color(const mlx_texture_t *tex, const int pixel_x,
	const int pixel_y)
{
	uint8_t	*pixel;

	pixel = &tex->pixels[(pixel_y * tex->width + pixel_x) * 4];
	if (pixel[3] == 0)
		return (0);
	return ((pixel[0] << 24) | (pixel[1] << 16)
		| (pixel[2] << 8) | pixel[3]);
}

void	draw_sprite_stripe(const t_ctx *ctx, const t_draw_info *info)
{
	int			y;
	float		tex_y;
	int			pixel_x;
	int			pixel_y;
	uint32_t	color;

	y = 0;
	while (y < info->height && y + info->start_y < ctx->window_height)
	{
		if (info->start_y + y < 0)
		{
			++y;
			continue ;
		}
		tex_y = y / (float)info->height;
		pixel_x = (int)(info->tex_x * ctx->textures.sprite->width);
		pixel_y = (int)(tex_y * ctx->textures.sprite->height);
		color = get_sprite_color(ctx->textures.sprite, pixel_x, pixel_y);
		if (color != 0)
			mlx_put_pixel(ctx->img_ptr, info->x, info->start_y + y, color);
		++y;
	}
}

void	draw_sprite(const t_ctx *ctx, const t_sprite *sprite,
		const int x, const float ray_angle)
{
	t_draw_info	info;
	float		delta_angle;
	int			sprite_size;
	int			sprite_screen_x;

	if (sprite->distance < 0.1f)
		return ;
	delta_angle = normalize_angle(sprite->angle - (ray_angle * M_PI / 180.0f));
	sprite_size = (int)(ctx->window_height / sprite->distance);
	info.height = sprite_size;
	sprite_screen_x = (int)(ctx->window_width / 2.0f
			* (1.0f + delta_angle / (FOV * M_PI / 360.0f)));
	info.start_y = (ctx->window_height - info.height) / 2;
	info.tex_x = (x - (sprite_screen_x - sprite_size / 2.0f))
		/ (float)sprite_size;
	info.x = x;
	if (info.tex_x < 0.0f || info.tex_x > 1.0f)
		return ;
	draw_sprite_stripe(ctx, &info);
}
