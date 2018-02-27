# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 13:32:09 by emarin            #+#    #+#              #
#    Updated: 2018/02/27 16:23:59 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =  srcs/ft_validp.c \
	   srcs/ft_voisin.c \
	   srcs/ft_validtetriminos.c \
	   srcs/ft_fillit.c \
	   srcs/ft_realloctab.c \
	   srcs/ft_fillitmove.c \
	   srcs/main.c

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

HFILES = includes/fillit.h \
		 libft/includes/libft.h \
		 libft/includes/get_next_line.h \

SRCS_DIR = srcs/
OBJS_DIR = objs/

INC_DIR =	includes/ \
			libft/includes/ \

INC := $(addprefix -I , $(INC_DIR))
OBJS:= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: 
	make -C libft
	make $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(LIBFT)
	gcc -o $(NAME) $(OBJS) $(INC) $(FLAGS) $(LIBFT) -L libft/ -lft


$(OBJS_DIR)%.o: %.c $(HFILES) $(OBJS_DIR)
	$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(dir $(OBJS))

clean:
	make -C libft/ clean
	rm -rf $(OBJS_DIR)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
