/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:49:27 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/06 13:49:27 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/params.h"

int	validate_resolution(t_ctx **ctx)
{
	if (!((*ctx)->window_width == 800 && (*ctx)->window_height == 600)
		&& !((*ctx)->window_width == 1920 && (*ctx)->window_height == 1080))
	{
		ft_putstr_fd(RESOLUTION_WARNING, 2);
		(*ctx)->window_width = 800;
		(*ctx)->window_height = 600;
	}
	if ((*ctx)->window_width <= 0 || (*ctx)->window_height <= 0)
		return (ft_putstr_fd(WINDOW_DIMENSIONS_ERROR, 2), FAILURE);
	return (EXIT_SUCCESS);
}

int	check_rgb_values(uint8_t *rgb_values, char **rgb)
{
	int	temp[3];

	temp[0] = ft_atoi(rgb[0]);
	temp[1] = ft_atoi(rgb[1]);
	temp[2] = ft_atoi(rgb[2]);
	if (temp[0] < 0 || temp[0] > 255
		|| temp[1] < 0 || temp[1] > 255
		|| temp[2] < 0 || temp[2] > 255)
		return (ft_putstr_fd(RGB_VALUE_ERROR, 2), FAILURE);
	rgb_values[0] = (uint8_t)temp[0];
	rgb_values[1] = (uint8_t)temp[1];
	rgb_values[2] = (uint8_t)temp[2];
	return (EXIT_SUCCESS);
}

int	check_empty_values(char **rgb)
{
	uint8_t		count;
	const char	*trim;

	count = 0;
	while (rgb[count])
	{
		trim = rgb[count];
		while (*trim == ' ' || *trim == '\t')
			trim++;
		if (*trim == '\0')
			return (ft_putstr_fd(EMPTY_RGB_VALUES_ERROR, 2), FAILURE);
		++count;
	}
	if (count != 3)
		return (ft_putstr_fd(RGB_FMT_ERROR, 2), FAILURE);
	return (EXIT_SUCCESS);
}

int	check_trailing_comma(const char *line)
{
	const char	*temp;

	temp = line + ft_strlen(line) - 1;
	while (temp > line && (*temp == ' ' || *temp == '\n' || *temp == '\r'))
		--temp;
	if (*temp == ',')
		return (ft_putstr_fd(TRAILING_COMMA_ERROR, 2), FAILURE);
	return (EXIT_SUCCESS);
}

int	check_textures(t_ctx **ctx)
{
	if ((*ctx)->textures.north == NULL || (*ctx)->textures.south == NULL
		|| (*ctx)->textures.east == NULL || (*ctx)->textures.west == NULL)
	{
		ft_putstr_fd((char *)mlx_strerror(MLX_INVFILE), 2);
		return (FAILURE);
	}
	if (((*ctx)->textures.sprite != NULL)
		&& (*ctx)->textures.sprite == NULL)
	{
		ft_putstr_fd(SPRITE_LOAD_ERROR, 2);
		return (FAILURE);
	}
	return (EXIT_SUCCESS);
}
