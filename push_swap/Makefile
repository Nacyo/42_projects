# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:53:49 by ynacache          #+#    #+#              #
#    Updated: 2018/01/28 15:27:47 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

FILES1 = srcs/checker.c \
		 srcs/check.c \
		 srcs/display.c \
		 srcs/use.c \
		 srcs/moves/push.c \
		 srcs/moves/swap.c \
		 srcs/moves/rotate.c \
		 srcs/moves/reverse.c

FILES2 = srcs/push_swap/push_swap.c \
		 srcs/push_swap/algo_small.c \
		 srcs/push_swap/sort_int.c \
		 srcs/check.c \
		 srcs/display.c \
		 srcs/use.c \
		 srcs/moves/push.c \
		 srcs/moves/swap.c \
		 srcs/moves/rotate.c \
		 srcs/moves/reverse.c

HFILES = includes/checker.h \
		 libft/includes/libft.h \
		 libft/includes/get_next_line.h \

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
OBJS_DIR = objs/

INC_DIR =	includes/ \
			libft/includes/ \

ARG = 1

INC := $(addprefix -I , $(INC_DIR))
OBJS1 := $(addprefix $(OBJS_DIR), $(FILES1:.c=.o))
OBJS2 := $(addprefix $(OBJS_DIR), $(FILES2:.c=.o))

all:
	@make -C libft
	@make $(NAME1)
	@make $(NAME2)

$(NAME1): $(OBJS_DIR) $(OBJS1) $(LIBFT)
	$(CC) -o $(NAME1) $(OBJS1) $(INC) $(CFLAGS) -L libft/ -lft

$(NAME2): $(OBJS2) $(LIBFT)
	$(CC) -o $(NAME2) $(OBJS2) $(INC) $(CFLAGS) -L libft/ -lft

$(OBJS_DIR)%.o: %.c $(HFILES) $(OBJS_DIR)
	$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(dir $(OBJS1))
	mkdir -p $(dir $(OBJS2))

clean:
	make -C libft/ clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME1) $(NAME2)

re: fclean all

test:
	@./$(NAME2) $(ARG) | wc -l | sed "s/ //g" | tr "\n" "\t"
	@./$(NAME2) $(ARG) | ./$(NAME1) $(ARG) | sed "s/KO/KO >>> FAIL!!!/g"


.PHONY: all clean fclean re

