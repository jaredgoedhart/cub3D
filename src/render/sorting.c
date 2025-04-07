/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:48:30 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:48:30 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"

void	sort_sprites(t_sprite *sprites, const int count)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (sprites[j].distance < sprites[j + 1].distance)
			{
				temp = sprites[j];
				sprites[j] = sprites[j + 1];
				sprites[j + 1] = temp;
			}
			++j;
		}
		++i;
	}
}

mlx_texture_t	*get_wall_texture(const t_ctx *ctx,
	const int tex_num)
{
	if (tex_num == 0)
		return (ctx->textures.north);
	else if (tex_num == 1)
		return (ctx->textures.south);
	else if (tex_num == 2)
		return (ctx->textures.east);
	return (ctx->textures.west);
}

int	process_map_row(const t_ctx *ctx, t_sprite *sprites,
		const int y, const float player_angle)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (x < ctx->map->width)
	{
		if (ctx->map->grid[y][x] == '2')
		{
			calculate_sprite_position(&sprites[count], x, y);
			calculate_sprite_angles(&sprites[count], ctx, player_angle);
			count++;
		}
		++x;
	}
	return (count);
}

void	calc_wall_props(t_ray *ray, const t_ray_vars *vars,
	const float ray_angle, const t_ctx *ctx)
{
	float	angle_diff;

	if (ray->wall_hit_side == 0)
		ray->distance = vars->side_dist_x - vars->delta_dist_x;
	else
		ray->distance = vars->side_dist_y - vars->delta_dist_y;
	angle_diff = (ray_angle - ctx->player.angle) * M_PI / 180.0f;
	ray->distance *= cos(angle_diff);
	ray->wall_height = (int)((ctx->window_height / ray->distance) * 1.0f);
	set_tex_and_wall_x(ray, vars);
}

void	draw_sprites_for_ray(const t_ctx *ctx, const t_sprite *sprites,
	const int sprite_count, const t_ray_casting *rc)
{
	int	i;

	i = 0;
	while (i < sprite_count)
	{
		if (sprites[i].in_fov && sprites[i].distance < rc->wall_distance)
			draw_sprite(ctx, &sprites[i], rc->x, rc->ray_angle);
		++i;
	}
}
