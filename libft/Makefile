# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 14:34:40 by sel-ahma          #+#    #+#              #
#    Updated: 2019/12/11 10:24:47 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes.mk

NAME = libft.a

HEADERS = includes/libft.h
HEADERS += includes/double.h
HEADERS += includes/ft_printf.h

INCLUDES = -I./includes/

OBJ += $(LIBFT_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
#CFLAGS += -fsanitize=address,undefined -g3

CLEAR_LINE = \033[2K\c

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@echo "\nCreating $@"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo "$(CLEAR_LINE)"
	@echo "Compiling $<\r\c"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing the libft.a library"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
