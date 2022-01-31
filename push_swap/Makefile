# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumfred <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 13:16:31 by lumfred           #+#    #+#              #
#    Updated: 2022/01/22 13:16:31 by lumfred          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

FLAG = -Wall -Wextra -Werror

HEADER = push_swap.h

SRC = push_swap.c \
		operations.c \
		list.c \
		list_functions.c \
		cmd_list.c \
		check_args.c \
		indexation_mark.c \
		direction.c \
		process_a.c \
		process_b.c \
		process.c \
		common_utilities.c \
		mandatory_utilities.c

BONUS_SRC = checker.c \
			operations.c \
			list.c \
			list_functions.c \
			cmd_list.c \
			check_args.c \
			common_utilities.c \
			bonus_utilities.c


OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC := gcc

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)
	@echo $(NAME) compiled

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(HEADER)
	$(CC) $(BONUS_OBJ) -o $(BONUS_NAME)
	@echo $(BONUS_NAME) compiled

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo $(NAME) files cleaned

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo $(NAME) cleaned

re: fclean all

.PHONY: re, clean, fclean, all, bonus
