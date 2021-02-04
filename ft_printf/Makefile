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
NAME = libftprintf.a
PATHLIB = ../libft
NAMELIB = libft.a
HEADER = includes/ft_printf.h
FLAG = -Wall -Wextra -Werror
PATHSRC = srcs digits chars
SRCLIST = $(wildcard $(dir)/*.c)
SRC = $(foreach dir, $(PATHSRC), $(SRCLIST))
INC = -I../ft_printf/includes -I../libft
OBJ =  $(SRC:.c=.o)


.PHONY: all lib clean fclean re

all: lib $(NAME) $(SRC)

$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) objs/*.o $(PATHLIB)/$(NAMELIB)

%.o: %.c $(HEADER)
	$(CC) -c $(FLAG) $< $(INC) -o objs/$(notdir $@)

lib:
	$(MAKE) bonus -C$(PATHLIB)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C$(PATHLIB)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C$(PATHLIB)

re: fclean all