/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:47:38 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:47:38 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"

float	normalize_angle(float angle)
{
	while (angle > M_PI)
		angle -= 2.0f * M_PI;
	while (angle < -M_PI)
		angle += 2.0f * M_PI;
	return (angle);
}

void	calculate_sprite_position(t_sprite *sprite, const int x,
	const int y)
{
	sprite->x = x + 0.5f;
	sprite->y = y + 0.5f;
}

void	calculate_sprite_angles(t_sprite *sprite, const t_ctx *ctx,
		const float player_angle)
{
	float	dx;
	float	dy;
	float	relative_angle;

	dx = sprite->x - ctx->player.x;
	dy = sprite->y - ctx->player.y;
	sprite->angle = atan2(dy, dx);
	sprite->distance = sqrt(dx * dx + dy * dy);
	relative_angle = normalize_angle(sprite->angle - player_angle);
	sprite->in_fov = fabs(relative_angle) < (FOV * M_PI / 180.0f);
}

void	init_ray_vars(t_ray_vars *vars, const float ray_angle,
	const t_player player)
{
	vars->ray_x = player.x;
	vars->ray_y = player.y;
	vars->cos_a = cos(ray_angle * M_PI / 180.0f);
	vars->sin_a = sin(ray_angle * M_PI / 180.0f);
	vars->delta_dist_x = fabs(1 / vars->cos_a);
	vars->delta_dist_y = fabs(1 / vars->sin_a);
	if (vars->cos_a >= 0)
		vars->step_x = 1;
	else
		vars->step_x = -1;
	if (vars->sin_a >= 0)
		vars->step_y = 1;
	else
		vars->step_y = -1;
	vars->map_x = (int)vars->ray_x;
	vars->map_y = (int)vars->ray_y;
}

void	set_tex_and_wall_x(t_ray *ray, const t_ray_vars *vars)
{
	if (ray->wall_hit_side == 0)
	{
		if (vars->step_x > 0)
			ray->tex_num = 2;
		else
			ray->tex_num = 3;
		ray->wall_x = vars->ray_y + ray->distance * vars->sin_a;
	}
	else
	{
		if (vars->step_y > 0)
			ray->tex_num = 1;
		else
			ray->tex_num = 0;
		ray->wall_x = vars->ray_x + ray->distance * vars->cos_a;
	}
	ray->wall_x -= floor(ray->wall_x);
}
