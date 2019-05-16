# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoole <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/02 17:48:34 by spoole            #+#    #+#              #
#    Updated: 2019/03/01 23:55:26 by spoole           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#REMOVE -g flag from ALL MAKE FILES

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

FILES = ft_printf.c ft_vasprintf.c node_init.c arg_node.c modifier.c is_check_functions.c str_tasks.c mod_string.c
LIBFT = includes/Libft/

all : $(NAME)

libft:
	@make -C $(LIBFT) $(OBJ)

$(NAME): libft
	@$(CC) $(CFLAGS) -c $(FILES)
	@ar rcs $(NAME) *.o $(LIBFT)*.o
	@ranlib $(NAME)

clean:
	@rm -f *.o
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all libft $(NAME) clean fclean re
