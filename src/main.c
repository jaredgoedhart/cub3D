/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:17:06 by lgoddijn          #+#    #+#             */
/*   Updated: 2025/01/03 19:17:06 by lgoddijn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	on_tick(void *param)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)param;
	if (!ctx || !ctx->mlx_ptr)
		return ;
	handle_keyboard_input(ctx);
	render_frame(ctx);
}

int	main(const int argc, const char **argv)
{
	t_ctx	*ctx;

	ctx = NULL;
	if (argc != 2)
		return (ft_putstr_fd(FORMAT_INPUT_ERROR, 2), EXIT_FAILURE);
	ctx = initialize_struct();
	if (ctx == NULL)
		return (EXIT_FAILURE);
	if (initialize_parameters(argv[1], &ctx) == FAILURE)
		return (quit_ctx(ctx), EXIT_FAILURE);
	if (parse_map(argv[1], ctx) == FAILURE)
		return (quit_ctx(ctx), EXIT_FAILURE);
	initialize_player_direction(ctx);
	if (initialize_simulation(&ctx, on_tick) == FAILURE)
		return (quit_ctx(ctx), EXIT_FAILURE);
	if (start_simulation(ctx) == FAILURE)
		return (quit_ctx(ctx), EXIT_FAILURE);
	quit_ctx(ctx);
	return (EXIT_SUCCESS);
}
