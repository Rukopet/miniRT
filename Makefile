# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egums <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 11:45:53 by egums             #+#    #+#              #
#    Updated: 2020/11/06 15:45:41 by egums            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
NAME = miniRT
PRINTPATH = ./ft_printf
PRINTNAME = libftprintf.a
PATHLIB = ./libft
NAMELIB = libft.a
LIBS = $(PATHLIB)/$(NAMELIB) $(PRINTPATH)/$(PRINTNAME)
LIBX = -L./ -lmlx
HEADER = includes/minirt.h
FLAG = -Wall -Wextra #-Werror
FLAGKIT = $(FLAG) -framework OpenGL -framework AppKit
PATHSRC = srcs
SRCLIST = $(wildcard $(dir)/*.c)
SRC = $(foreach dir, $(PATHSRC), $(SRCLIST))
INC = -I./ft_printf/includes -I./libft/ -I./includes
OBJ = $(SRC:.c=.o)

.PHONY: all libs clean fclean re

all: $(NAME) $(SRC) libs

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(LIBS) $(LIBX) $(OBJ) $(INC)

%.o: %.c $(HEADER)
	$(CC) -c $(FLAG) $(LIBX) $< $(INC) -o $@

libs:
	$(MAKE) all -C$(PRINTPATH)
	$(MAKE) -C./minilibx_mms
	mv ./minilibx_mms/libmlx.dylib ./

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C$(PRINTPATH)
	$(MAKE) clean -C./minilibx_mms

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C$(PRINTPATH)
	rm -f libmlx.dylib

re: fclean all