/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:48:19 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:48:19 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render.h"

void	calc_side_dist(t_ray_vars *vars)
{
	if (vars->step_x > 0)
		vars->side_dist_x = (1.0f - (vars->ray_x - vars->map_x))
			* vars->delta_dist_x;
	else
		vars->side_dist_x = (vars->ray_x - vars->map_x) * vars->delta_dist_x;
	if (vars->step_y > 0)
		vars->side_dist_y = (1.0f - (vars->ray_y - vars->map_y))
			* vars->delta_dist_y;
	else
		vars->side_dist_y = (vars->ray_y - vars->map_y) * vars->delta_dist_y;
}

void	set_wall_distance(const t_ray *ray, const t_ray_vars *vars,
	float *wall_distance)
{
	if (ray->wall_hit_side == 0)
		*wall_distance = vars->side_dist_x - vars->delta_dist_x;
	else
		*wall_distance = vars->side_dist_y - vars->delta_dist_y;
}

void	update_dda_vars(t_ray_vars *vars, t_ray *ray)
{
	if (vars->side_dist_x < vars->side_dist_y)
	{
		vars->side_dist_x += vars->delta_dist_x;
		vars->map_x += vars->step_x;
		ray->wall_hit_side = 0;
	}
	else
	{
		vars->side_dist_y += vars->delta_dist_y;
		vars->map_y += vars->step_y;
		ray->wall_hit_side = 1;
	}
}

int	check_wall_hit(const t_ray_vars *vars, const t_map *map)
{
	if (vars->map_x < 0 || vars->map_x >= map->width
		|| vars->map_y < 0 || vars->map_y >= map->height)
		return (0);
	return (map->grid[vars->map_y][vars->map_x] == '1');
}

void	perform_dda(t_ray_vars *vars, t_ray *ray, const t_map *map,
	float *wall_distance)
{
	*wall_distance = INFINITY;
	while (!vars->hit && vars->map_x >= 0 && vars->map_x < map->width
		&& vars->map_y >= 0 && vars->map_y < map->height)
	{
		update_dda_vars(vars, ray);
		if (check_wall_hit(vars, map))
		{
			vars->hit = 1;
			set_wall_distance(ray, vars, wall_distance);
		}
	}
}
