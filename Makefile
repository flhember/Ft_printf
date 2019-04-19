# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flhember <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 15:51:59 by flhember          #+#    #+#              #
#    Updated: 2019/04/12 17:19:02 by flhember         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
FLAGS = -g3 -Wall -Wextra -Werror

SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
LIB_PATH = ./Libft/
INC_PATH = ./includes/

SRC_FILES = ft_printf.c 		\
			ft_set_tab.c		\
			ft_creatlst.c		\
			ft_convert_param.c	\
			ft_get_option.c		\
			ft_convert_c.c		\
			ft_convert_s.c		\
			ft_convert_p.c		\
			ft_convert_o.c		\
			ft_convert_x.c		\
			ft_convert_u.c		\
			ft_convert_f.c		\
			ft_free.c			\
			ft_print_tab.c		\
			ft_convert_i_d.c	\
			ft_get_good_size.c	\
			ft_set_list.c		\
			ft_put_option.c		\
			ft_put_option_x.c	\
			ft_ftoa.c			\
			ft_math_str.c		\
			ft_get_float.c		\
			ft_util_float.c		\
			ft_ftoa_80.c

INC_FILES = ft_printf.h

LIB_FILES = libft.a
LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))
LIB_HEADER = $(addprefix $(LIB_PATH), $(INC_PATH))

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(NAME)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_PATH) -I $(LIB_HEADER)
	@echo "\033[40mCompilation of \033[1m$(notdir $<)\033[0m \033[32mdone.\033[0m"

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC)
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJ_EXEC)
	@ranlib $(NAME)
	@echo "\033[1;32m$(notdir $(NAME))\033[1;0m\033[32m created.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[31mObjects files of \033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -rf $(NAME)
	@echo "\033[1;31m$(notdir $(NAME))\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
