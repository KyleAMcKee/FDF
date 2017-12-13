#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmckee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:55:28 by kmckee            #+#    #+#              #
#    Updated: 2017/11/22 16:40:06 by kmckee           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf
SRCDIR		=	srcs/

FILES		=	main.c draw_line.c \
				scale.c map_draw.c \
				map_create.c view.c \
				to_origin.c key_press.c \
				set_color.c display_usage.c \
				error_handle.c

SRC 		= 	$(addprefix $(SRCDIR), $(FILES))
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
GFX			= 	mlx/libmlx.a -framework OpenGL -framework AppKit
LIBFT		=	libft/libft.a

all: $(NAME)

$(NAME):
	make all -C libft
	$(CC) -o $(NAME) $(FLAGS) $(SRC) $(GFX) $(LIBFT)

clean:
	make clean -C libft

fclean:
	make fclean -C libft
	rm -f $(NAME)

re: fclean all
