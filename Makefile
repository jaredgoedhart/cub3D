# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgoddijn <lgoddijn@student.codam.nl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:34:30 by lgoddijn          #+#    #+#              #
#    Updated: 2025/01/06 13:34:30 by lgoddijn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc

CFLAGS		= -Wall -Wextra -Werror -Wstrict-prototypes		\
			  -Wmissing-prototypes -Wpedantic -std=gnu17	\
			  -fstack-protector-strong -O3 -g -I./include

HEADERS		= -I . -I ../MLX42/include -I libft -I get_next_line

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

LIBS		= MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS 		= src/main.c					\
			  src/init/init.c				\
			  src/movement/movement.c		\
			  src/params/parameters.c		\
			  src/params/parsing.c			\
			  src/params/validation.c		\
			  src/map/map.c					\
			  src/map/validation.c			\
			  src/map/parsing.c				\
			  src/map/check.c				\
			  src/render/render.c			\
			  src/render/calculations.c		\
			  src/render/drawing.c			\
			  src/render/raycasting.c		\
			  src/render/sorting.c			\
			  src/exit/exit.c				\
			  get_next_line/get_next_line.c \
			  get_next_line/get_next_line_utils.c

OBJDIR 		= obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: libmlx $(NAME)

libmlx:
	@(cd MLX42 && cmake -B build && make all -C build)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C ./MLX42/build
	@rm -rf ./MLX42/build
	@make clean -C $(LIBFT_DIR)
	@echo Removed libft object files
	@rm -rf $(OBJS)
	@echo Removed cub3D object files
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@echo Removed libft.a
	@rm -f $(NAME)
	@echo Removed cub3D executable
	@rm -rf $(OBJDIR)

re: fclean all

.PHONY: all libmlx clean fclean re
