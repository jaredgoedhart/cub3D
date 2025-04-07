/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:49:49 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:49:49 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map.h"

bool	has_sprites_in_map(const t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '2')
				return (true);
			++x;
		}
		++y;
	}
	return (false);
}

bool	is_config_line(const char *line)
{
	if (!line)
		return (false);
	return (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0
		|| ft_strncmp(line, "R ", 2) == 0
		|| ft_strncmp(line, "S ", 2) == 0);
}

bool	has_wall_in_line(const char *line, const int len)
{
	int	i;

	i = 0;
	while (i < len)
		if (line[i++] == '1')
			return (true);
	return (false);
}

bool	should_skip_line(const bool map_started, const char *line,
	const int line_len)
{
	if (!map_started && (is_config_line(line) || !line_len
			|| !has_wall_in_line(line, line_len)))
		return (true);
	return (false);
}
