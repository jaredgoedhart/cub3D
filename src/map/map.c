/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:11:43 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 19:11:43 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/map.h"

void	free_map(const t_map *map)
{
	int	i;

	i = 0;
	while (i < MAX_MAP_HEIGHT)
		free(map->grid[i++]);
	free(map->grid);
}

int	allocate_map(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * (MAX_MAP_HEIGHT));
	if (map->grid == NULL)
		return (0);
	i = 0;
	while (i < MAX_MAP_HEIGHT)
	{
		map->grid[i] = malloc(sizeof(char) * (MAX_MAP_WIDTH + 1));
		if (map->grid[i] == NULL)
		{
			while (--i >= 0)
				free(map->grid[i]);
			free(map->grid);
			return (0);
		}
		ft_memset(map->grid[i], ' ', MAX_MAP_WIDTH);
		map->grid[i][MAX_MAP_WIDTH] = '\0';
		++i;
	}
	return (1);
}

void	fill_map(const int fd, t_map *map)
{
	uint16_t	max_width;

	max_width = 0;
	process_file_lines(fd, map, &max_width);
	map->width = max_width;
	clean_remaining_lines(fd);
}

int	validate_map_content(t_map *map)
{
	int		player_count;
	int		y;

	player_count = 0;
	y = 0;
	if (map->height < 3 || map->width < 3)
		return (ft_putstr_fd(INVALID_MIN_MAP_SIZE_ERROR, 2), 0);
	if (map->height > MAX_MAP_HEIGHT || map->width > MAX_MAP_WIDTH)
		return (ft_putstr_fd(INVALID_MAX_MAP_SIZE_ERROR, 2), 0);
	while (y < map->height)
	{
		if (!process_cell(map, y, &player_count))
			return (0);
		++y;
	}
	if (player_count != 1)
		return (ft_putstr_fd(INVALID_PLAYER_COUNT_ERROR, 2), 0);
	return (1);
}

int	parse_map(const char *file_path, t_ctx *ctx)
{
	int		fd;
	t_map	map;

	if (!validate_last_char(file_path))
		return (ft_putstr_fd(MAP_POSITION_ERROR, 2), FAILURE);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd(FILE_OPEN_ERROR, 2), FAILURE);
	if (!allocate_map(&map))
		return (close(fd), ft_putstr_fd(MALLOC_ERROR, 2), FAILURE);
	fill_map(fd, &map);
	close(fd);
	if (map.height == 0)
		return (free_map(&map), ft_putstr_fd(INVALID_MAP_ERROR, 2), FAILURE);
	if (!validate_map_content(&map))
		return (free_map(&map), ft_putstr_fd(INVALID_MAP_ERROR, 2), FAILURE);
	if (has_sprites_in_map(&map) && ctx->textures.sprite == NULL)
		return (free_map(&map), ft_putstr_fd(SPRITE_ERROR, 2), FAILURE);
	ctx->map = malloc(sizeof(t_map));
	if (ctx->map == NULL)
		return (free_map(&map), ft_putstr_fd(MALLOC_ERROR, 2), FAILURE);
	*ctx->map = map;
	return (EXIT_SUCCESS);
}
