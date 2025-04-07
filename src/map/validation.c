/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:50:40 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:50:40 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map.h"

int	is_valid_char(const char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W');
}

int	validate_last_char(const char *file_path)
{
	int		fd;
	char	*line;
	int		found_map;
	int		found_empty;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(VALIDATE_CHAR_FILE_ERROR, 2), 0);
	found_map = 0;
	found_empty = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if ((line[0] == '\n' || line[0] == '\0') && found_map)
			found_empty = 1;
		else if ((line[0] == '1' || line[0] == '0' || line[0] == '2')
			&& found_empty)
			return (free(line), close(fd), 0);
		else if (line[0] == '1' || line[0] == '0' || line[0] == '2')
			found_map = 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (!found_empty);
}

int	check_surroundings(const t_map *map, const int x, const int y)
{
	int		dx;
	int		dy;
	char	neighbor;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if (dx == 0 && dy == 0)
			{
				++dx;
				continue ;
			}
			neighbor = map->grid[y + dy][x + dx];
			if (neighbor == ' ')
				return (0);
			++dx;
		}
		++dy;
	}
	return (1);
}

int	check_position(const t_map *map, const int x, const int y,
	const char current)
{
	if ((current == '0' || ft_strchr("NSEW", current))
		&& (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1))
		return (0);
	if (current == '0' || ft_strchr("NSEW", current))
		if (!check_surroundings(map, x, y))
			return (0);
	return (1);
}

int	process_cell(t_map *map, int y, int *player_count)
{
	int		x;
	char	current;

	x = 0;
	while (x < map->width)
	{
		current = map->grid[y][x];
		if (current != ' ' && !is_valid_char(current))
			return (0);
		if (ft_strchr("NSEW", current))
		{
			(*player_count)++;
			map->player_dir = current;
			map->player_x = x;
			map->player_y = y;
		}
		if (!check_position(map, x, y, current))
			return (0);
		++x;
	}
	return (1);
}
