/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _structs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:00:34 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 19:03:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCTS_H

# define _STRUCTS_H

# include <stdint.h>

/* Fix assumption of parent/MLX42 */
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_ray_vars
{
	float	ray_x;
	float	ray_y;
	float	cos_a;
	float	sin_a;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		hit;
}	t_ray_vars;

typedef struct s_ray_casting
{
	int		sprite_count;
	float	ray_angle;
	int		x;
	float	wall_distance;
}	t_ray_casting;

typedef struct s_draw_info
{
	float	tex_x;
	int		start_y;
	int		height;
	int		x;
}	t_draw_info;

typedef struct s_wall
{
	int	start;
	int	end;
	int	tex_x;
	int	x;
}	t_wall;

typedef struct s_line_info
{
	uint16_t	line_len;
	uint16_t	*max_width;
	uint16_t	*y;
}	t_line_info;

typedef struct s_ray
{
	float		distance;
	float		wall_x;
	uint16_t	wall_height;
	uint8_t		tex_num;
	uint8_t		wall_hit_side;
}			t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
}	t_player;

typedef struct s_sprite
{
	float	x;
	float	y;
	float	distance;
	float	angle;
	bool	in_fov;
}	t_sprite;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	*sprite;
	uint16_t		tex_width;
	uint16_t		tex_height;
}	t_textures;

typedef struct s_map
{
	char		**grid;
	uint16_t	width;
	uint16_t	height;
	char		player_dir;
	uint16_t	player_x;
	uint16_t	player_y;
}	t_map;

typedef struct s_ctx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	uint32_t	*img_data;
	uint16_t	window_width;
	uint16_t	window_height;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	t_map		*map;
	t_player	player;
	t_textures	textures;
}	t_ctx;

#endif
