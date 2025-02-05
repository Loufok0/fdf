# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 00:28:46 by malapoug          #+#    #+#              #
#    Updated: 2025/01/16 15:16:46 by malapoug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define HEADER
========================================================================
  __      _   __                                      _  _            _
 / _|    | | / _|                                    (_)| |          | |
| |_   __| || |_        ___   ___   _ __ ___   _ __   _ | |  ___   __| |
|  _| / _` ||  _|      / __| / _ \ | '_ ` _ \ | '_ \ | || | / _ \ / _` |
| |  | (_| || |       | (__ | (_) || | | | | || |_) || || ||  __/| (_| |
|_|   \__,_||_|        \___| \___/ |_| |_| |_|| .__/ |_||_| \___| \__,_|
                                              | |
                                              |_|
========================================================================
endef
export HEADER

NAME = fdf

CC = gcc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

SRCS =	fdf.c\
	fdf_init.c\
	parser.c\
	parser_utils.c\
	fdf_draw.c\
	get_color.c\
	bresenham.c\
	fdf_maths.c\
	fdf_hook.c\
	fdf_clean.c\

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "FDF compiled!\n"

debug: $(OBJS)
	@make -C libft/
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "FDF compiled with debug!\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@


clean:
	@make clean -C libft/
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft/
	@$(RM) $(NAME)

done:
	@echo "$$HEADER"

re: fclean all

.PHONY: all clean fclean re

