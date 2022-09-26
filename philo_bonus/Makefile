# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosby <gopal@student.42.fr>                +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 17:42:16 by gopal             #+#    #+#              #
#    Updated: 2022/04/26 06:17:47 by gopal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

HEADER	=	src/philo_bonus.h
SRCS_DIR=	src/
SRCS	=	main_bonus.c\
			args_check_bonus.c\
			utils_bonus.c
OBJ		=	$(addprefix $(SRCS_DIR), $(SRCS:%.c=%.o))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "$(YELLOW) Philosophers compiles $(RED)+ bonus, $(GREEN)check!$(WHITE) 😎"

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
