/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:49:11 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:49:11 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/params.h"

int	parse_resolution(const char *line, t_ctx **ctx)
{
	uint8_t	count;
	char	**split;

	while (*line == ' ' || *line == '\t')
		line++;
	split = ft_split(line + 1, ' ');
	if (split == NULL)
		return (ft_putstr_fd(RESOLUTION_MALLOC_ERROR, 2), FAILURE);
	count = 0;
	while (split[count])
		++count;
	if (count != 2)
		return (ft_free_split(split),
			ft_putstr_fd(INVALID_RESOLUTION_ERROR, 2), FAILURE);
	(*ctx)->window_width = ft_atoi(split[0]);
	(*ctx)->window_height = ft_atoi(split[1]);
	if (validate_resolution(ctx) == FAILURE)
		return (ft_free_split(split), FAILURE);
	ft_free_split(split);
	return (EXIT_SUCCESS);
}

int	parse_textures(const char *line, t_ctx **ctx)
{
	static uint8_t	texture_set[5] = {0};
	char			*path;
	mlx_texture_t	**texture_ptr;

	texture_ptr = get_texture_pointer(line, ctx, texture_set);
	if (texture_ptr == NULL && !ft_strncmp(line, "S ", 2))
		return (EXIT_SUCCESS);
	if (texture_ptr == NULL)
		return (ft_putstr_fd(INVALID_TEXTURE_ID_ERROR, 2), FAILURE);
	if (parse_texture_path(line, &path) == FAILURE)
		return (ft_putstr_fd(TEXTURE_PARSE_ERROR, 2), FAILURE);
	if (load_texture(texture_ptr, path) == FAILURE)
		return (free(path), FAILURE);
	free(path);
	return (EXIT_SUCCESS);
}

int	parse_color(const char *line, uint32_t *color)
{
	char	**rgb;
	uint8_t	rgb_values[3];

	while (*line == 'F' || *line == 'C' || *line == ' ' || *line == '\t')
		++line;
	if (check_trailing_comma(line) == FAILURE)
		return (FAILURE);
	rgb = ft_split(line, ',');
	if (rgb == NULL)
		return (ft_putstr_fd(RGB_MALLOC_ERROR, 2), FAILURE);
	if (check_empty_values(rgb) == FAILURE)
		return (ft_free_split(rgb), FAILURE);
	if (check_rgb_values(rgb_values, rgb) == FAILURE)
		return (ft_free_split(rgb), FAILURE);
	*color = (rgb_values[0] << 24) | (rgb_values[1] << 16)
		| (rgb_values[2] << 8) | 0xFF;
	ft_free_split(rgb);
	return (EXIT_SUCCESS);
}

int	process_line(const char *line, t_ctx **ctx)
{
	char	*trimmed_line;

	while (*line == ' ' || *line == '\t')
		++line;
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "S ", 2) == 0)
	{
		trimmed_line = ft_strtrim(line, " \t\n\r");
		if (parse_textures(trimmed_line, ctx) == FAILURE)
			return (free(trimmed_line), FAILURE);
		free(trimmed_line);
	}
	else if (*line == 'R' && parse_resolution(line, ctx) == FAILURE)
		return (FAILURE);
	else if (*line == 'F' && parse_color(line,
			&(*ctx)->floor_color) == FAILURE)
		return (FAILURE);
	else if (*line == 'C' && parse_color(line,
			&(*ctx)->ceiling_color) == FAILURE)
		return (FAILURE);
	return (EXIT_SUCCESS);
}

int	initialize_parameters(const char *cub_file_path, t_ctx **ctx)
{
	int		fd;
	char	*line;

	if (validate_and_open_file(cub_file_path, &fd) == FAILURE)
		return (FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (process_line(line, ctx) == FAILURE)
			return (free(line), close(fd), FAILURE);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if ((*ctx)->floor_color == 0 || (*ctx)->ceiling_color == 0)
		return (ft_putstr_fd(MISSING_COLOURS_ERROR, 2), FAILURE);
	return (check_textures(ctx));
}
