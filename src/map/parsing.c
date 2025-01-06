/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:50:24 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:50:24 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map.h"

int	clean_line(const char *line)
{
	int	line_len;

	line_len = (int)ft_strlen(line);
	if (line_len > 0)
	{
		if (line[line_len - 1] == '\n')
			--line_len;
		if (line_len > 0 && line[line_len - 1] == '\r')
			--line_len;
	}
	return (line_len);
}

void	process_map_line(const t_map *map, const char *line,
	const uint16_t line_len, const uint16_t y)
{
	int	i;

	ft_memset(map->grid[y], ' ', MAX_MAP_WIDTH);
	map->grid[y][MAX_MAP_WIDTH] = '\0';
	i = 0;
	while (i < line_len && i < MAX_MAP_WIDTH)
	{
		map->grid[y][i] = line[i];
		++i;
	}
}

void	clean_remaining_lines(const int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	update_max_and_process(const t_map *map, const char *line,
	const t_line_info *info)
{
	if (info->line_len > *(info->max_width))
		*(info->max_width) = info->line_len;
	process_map_line(map, line, info->line_len, *(info->y));
	++(*(info->y));
}

void	process_file_lines(const int fd, t_map *map, uint16_t *max_width)
{
	uint16_t		y;
	char			*line;
	uint16_t		line_len;
	bool			map_started;
	t_line_info		info;

	y = 0;
	map_started = false;
	line = get_next_line(fd);
	while (line != NULL && y < MAX_MAP_HEIGHT)
	{
		line_len = clean_line(line);
		if (should_skip_line(map_started, line, line_len))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		map_started = true;
		info = (t_line_info){line_len, max_width, &y};
		update_max_and_process(map, line, &info);
		free(line);
		line = get_next_line(fd);
	}
	map->height = y;
}
