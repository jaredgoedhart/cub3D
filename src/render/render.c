/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:15:13 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 19:15:13 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"

int	collect_sprites(const t_ctx *ctx, t_sprite *sprites)
{
	int		sprite_count;
	int		y;
	float	player_angle;

	sprite_count = 0;
	y = 0;
	player_angle = ctx->player.angle * M_PI / 180.0f;
	while (y < ctx->map->height)
	{
		sprite_count += process_map_row(ctx, &sprites[sprite_count],
				y, player_angle);
		++y;
	}
	sort_sprites(sprites, sprite_count);
	return (sprite_count);
}

void	draw_textured_wall(const t_ctx *ctx, const t_ray ray, const int x)
{
	t_wall			wall;
	mlx_texture_t	*current_tex;

	wall.start = (ctx->window_height - ray.wall_height) / 2;
	if (wall.start < 0)
		wall.start = 0;
	wall.end = wall.start + ray.wall_height;
	if (wall.end >= ctx->window_height)
		wall.end = ctx->window_height - 1;
	current_tex = get_wall_texture(ctx, ray.tex_num);
	wall.tex_x = (int)(ray.wall_x * current_tex->width);
	wall.x = x;
	draw_wall_slice(ctx, ray, current_tex, wall);
}

void	cast_rays(const t_ctx *ctx)
{
	t_sprite		sprites[MAX_MAP_WIDTH * MAX_MAP_HEIGHT];
	t_ray_vars		vars;
	t_ray			ray;
	t_ray_casting	rc;

	rc.sprite_count = collect_sprites(ctx, sprites);
	rc.ray_angle = ctx->player.angle - (FOV / 2.0f);
	rc.x = 0;
	while (rc.x < ctx->window_width)
	{
		init_ray_vars(&vars, rc.ray_angle, ctx->player);
		calc_side_dist(&vars);
		vars.hit = 0;
		perform_dda(&vars, &ray, ctx->map, &rc.wall_distance);
		calc_wall_props(&ray, &vars, rc.ray_angle, ctx);
		draw_textured_wall(ctx, ray, rc.x);
		draw_sprites_for_ray(ctx, sprites, rc.sprite_count, &rc);
		rc.ray_angle += (float)FOV / ctx->window_width;
		++rc.x;
	}
}

void	render_frame(const t_ctx *ctx)
{
	int	x;
	int	y;

	y = 0;
	while (y < ctx->window_height)
	{
		x = 0;
		while (x < ctx->window_width)
		{
			if (y < ctx->window_height / 2)
				mlx_put_pixel(ctx->img_ptr, x, y, ctx->ceiling_color);
			else
				mlx_put_pixel(ctx->img_ptr, x, y, ctx->floor_color);
			++x;
		}
		++y;
	}
	cast_rays(ctx);
}

int	start_simulation(const t_ctx *ctx)
{
	render_frame(ctx);
	mlx_loop(ctx->mlx_ptr);
	return (EXIT_SUCCESS);
}
