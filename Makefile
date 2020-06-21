# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-ahma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 11:40:44 by sel-ahma          #+#    #+#              #
#    Updated: 2019/12/11 10:41:42 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./libft/includes.mk

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3
CFLAGS += -O2 -fno-builtin
CFLAGS += -Wpadded
INC_FLAGS = -Iinc
INC_LIB_FLAGS = -Ilibft/includes

LIB = ./libft/libft.a
LIB_INC = ./libft/includes/libft.h
LIB_INC += ./libft/includes/ft_printf.h
LIB_INC += ./libft/includes/double.h


SRC_PATH = ./src
LIB_PATH = ./libft
OBJ_PATH = ./obj

SRC_NAME = 	paths_func.c \
			parse_paths.c \
			print_ants_travel.c \
			save_rooms.c \
			ft_utils_parser2.c \
			ft_utils_parser.c \
			ft_utils_parser3.c \
			parser.c \
			utils_edk.c \
			edmkarp.c \
			utils_graph.c \
			utils_graph2.c \
			init_pars_checknbants.c \
			calc_paths_capacities.c \
			bfs.c \
			print_ants_travel_utils.c \
			free_graph.c \
			main.c \

LIBFT_SRC := $(patsubst %.c, libft/%.c,$(LIBFT_SRC))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_LIB_NAME = $(SRC_LIB_NAME:.c=.o)
HEADER = ./inc/lem_in.h

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

##########
# COLORS #
##########

YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m
CLEAR = \033[2k\c
BOLD = \e[1m
/BOLD = \e[0m

###########
# /COLORS #
###########

all: $(NAME)

$(NAME): $(LIB) $(OBJ) $(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(LIB) $(INC_LIB_FLAGS) $(SRC) -o $@
	@echo "\nCreating $@"

$(LIB): $(LIBFT_SRC) $(HEADERS_LIB)
	@$(MAKE) -C $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(INC_FLAGS) $(INC_LIB_FLAGS) -o $@ -c $<

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@echo "\nRemoving the lem-in objects..."
	@rm -rf $(OBJ) lem-in.dSYM

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
	@rm -rf ./obj $(NAME)
	@echo "\nRemoving the lem-in binary..."

norme:
	@norminette $(SRC) $(LIB) $(INC)

re: fclean all

.PHONY: all clean fclean
