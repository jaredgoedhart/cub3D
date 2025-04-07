/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:49:04 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:49:04 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/params.h"

int	parse_texture_path(const char *line, char **path)
{
	char	*newline;
	char	*carriage;
	char	*clean_path;

	while (*line == ' ' || *line == '\t')
		++line;
	line += 2;
	while (*line == ' ' || *line == '\t')
		++line;
	if (*line == '.')
		line += 2;
	clean_path = ft_strdup(line);
	if (clean_path == NULL)
		return (FAILURE);
	newline = ft_strchr(clean_path, '\n');
	if (newline)
		*newline = '\0';
	carriage = ft_strchr(clean_path, '\r');
	if (carriage)
		*carriage = '\0';
	*path = clean_path;
	return (EXIT_SUCCESS);
}

mlx_texture_t	**set_texture(mlx_texture_t **texture, uint8_t *is_set,
	char *name)
{
	if (*is_set)
	{
		ft_putstr_fd("Error: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" already set\n", 2);
		return (NULL);
	}
	*is_set = 1;
	return (texture);
}

mlx_texture_t	**get_texture_pointer(const char *line, t_ctx **ctx,
	uint8_t *already_set)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (set_texture(&(*ctx)->textures.north, &already_set[0],
				"North texture"));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (set_texture(&(*ctx)->textures.south, &already_set[1],
				"South texture"));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (set_texture(&(*ctx)->textures.west, &already_set[2],
				"West texture"));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (set_texture(&(*ctx)->textures.east, &already_set[3],
				"East texture"));
	if (ft_strncmp(line, "S ", 2) == 0)
		return (set_texture(&(*ctx)->textures.sprite, &already_set[4],
				"Sprite texture"));
	return (NULL);
}

int	load_texture(mlx_texture_t **texture_ptr, const char *path)
{
	*texture_ptr = mlx_load_png(path);
	if (*texture_ptr == NULL)
		return (ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2), FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_and_open_file(const char *cub_file_path, int *fd)
{
	char	*trimmed_path;

	if (ft_strrchr(cub_file_path, '.') == NULL
		|| ft_strncmp(ft_strrchr(cub_file_path, '.'), ".cub", 4))
	{
		ft_putstr_fd(INVALID_FILE_FORMAT_ERROR, 2);
		return (FAILURE);
	}
	trimmed_path = ft_strtrim(cub_file_path, " \t\n\r");
	*fd = open(trimmed_path, O_RDONLY);
	free(trimmed_path);
	if (*fd < 0)
	{
		ft_putstr_fd(FILE_OPEN_ERROR, 2);
		return (FAILURE);
	}
	return (EXIT_SUCCESS);
}
