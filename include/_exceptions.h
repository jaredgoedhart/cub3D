/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exceptions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:24:38 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 18:57:06 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EXCEPTIONS_H

# define _EXCEPTIONS_H

# define MALLOC_ERROR "Error\nMemory allocation failed.\n"
# define FILE_OPEN_ERROR "Error\nFailed to open file\n"
# define RGB_FMT_ERROR "Error\nInvalid RGB format\n"
# define RGB_VALUE_ERROR "Error\nInvalid RGB values\n"
# define IMAGE_CREATION_ERROR "Error\nFailed to create image\n"
# define EMPTY_RGB_VALUES_ERROR "Error\nEmpty RGB value\n"
# define INVALID_MAP_ERROR "Error\nInvalid map configuration\n"
# define IMAGE_TO_WINDOW_ERROR "Error\nFailed to add image to window\n"
# define INVALID_FILE_FORMAT_ERROR "Error\nInvalid file format\n"
# define SPRITE_LOAD_ERROR "Error\nSprite texture failed to load\n"
# define MLX_INIT_ERROR "Error\nFailed to init MLX: mlx_ptr is NULL\n"
# define PLAYER_DIRECTION_ERROR "Error\nInvalid player direction\n"
# define INVALID_PLAYER_COUNT_ERROR "Error\nInvalid player count\n"
# define TEXTURE_PARSE_ERROR "Error\nFailed to parse texture path\n"
# define MLX_LOOP_HOOK_ERROR "Error\nFailed to set game loop hook\n"
# define PARAMETER_INIT_ERROR "Error\nMissing required parameters\n"
# define WINDOW_DIMENSIONS_ERROR "Error\nInvalid window dimensions\n"
# define INVALID_RESOLUTION_ERROR "Error\nInvalid resolution format\n"
# define INVALID_MIN_MAP_SIZE_ERROR "Error\nInvalid minimum map size\n"
# define INVALID_MAX_MAP_SIZE_ERROR "Error\nInvalid maximum map size\n"
# define INVALID_TEXTURE_ID_ERROR "Error\nInvalid texture identifier\n"
# define MISSING_COLOURS_ERROR "Error\nMissing floor or ceiling color\n"
# define MAP_POSITION_ERROR "Error\nMap must be the last element in file\n"
# define TRAILING_COMMA_ERROR "Error\nInvalid RGB format: trailing comma\n"
# define FORMAT_INPUT_ERROR "Error\nExpected: ./cub3D <path/to/file.cub>\n"
# define RGB_MALLOC_ERROR "Error\nMemory allocation failed in RGB parsing\n"
# define RESOLUTION_MALLOC_ERROR "Error\nalloc failed in resolution parsing\n"
# define SPRITE_ERROR "Error\nMap contains sprites but no sprite texture is \
defined\n"
# define VALIDATE_CHAR_FILE_ERROR "Error\nCannot open file in \
validate_last_char.\n"

/* WARNING (not error) */
# define RESOLUTION_WARNING "Warning: Window size must be either 800 x 600 \
or 1920 x 1080\n"

#endif
