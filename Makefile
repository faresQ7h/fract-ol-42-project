# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: farmoham <farmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 00:58:57 by farmoham          #+#    #+#              #
#    Updated: 2025/09/29 22:52:40 by farmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := $(shell uname -s)

ifeq ($(OS),Linux)
	MLXDIRE = minilibx-linux
	MLXLIBE = $(MLXDIRE)/libmlx_Linux.a
	LDFLAGS = -lX11 -lXext -lm -lz
else
	MLXDIRE = minilibx_macos_opengl/minilibx_opengl_20191021
	MLXLIBE = $(MLXDIRE)/libmlx.a
	LDFLAGS = -framework OpenGL -framework AppKit
endif

NAME = fract-ol
SRC = main.c valid.c parse.c hook.c render.c color.c iteration.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIRE = libftprintf
LIBLIBE = $(LIBDIRE)/libftprintf.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(MLXLIBE) $(LIBLIBE)
	$(CC) $(CFLAGS) $(OBJ) $(MLXLIBE) $(LIBLIBE) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLXLIBE): $(MLXDIRE)
	$(MAKE) -C $(MLXDIRE)

$(LIBLIBE): $(LIBDIRE)
	$(MAKE) -C $(LIBDIRE)

clean:
	rm -f *.o
	$(MAKE) -C $(LIBDIRE) clean
	$(MAKE) -C $(MLXDIRE) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBDIRE) fclean
	$(MAKE) -C $(MLXDIRE) fclean


re: fclean all
