# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosby <gopal@student.42.fr>                +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 17:42:16 by gopal             #+#    #+#              #
#    Updated: 2022/04/26 06:17:50 by gopal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

HEADER	=	src/philo.h
SRCS_DIR=	src/
SRCS	=	main.c\
			args_check.c\
			init.c\
			utils.c
OBJ		=	$(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:		$(OBJ) $(HEADER)
				@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
				@echo "$(YELLOW) Philosophers compiles, $(GREEN)check!$(WHITE) 👌"

%.o		:	%.c
				@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean	:
				@rm -rf $(OBJ)

fclean	:		clean
				@rm -f $(NAME)

re		:		fclean all

# Colors
WHITE	=	\033[00m
GREEN	=	\033[04;32m
YELLOW	=	\033[01;33m
