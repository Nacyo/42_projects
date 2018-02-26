# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:34:19 by ynacache          #+#    #+#              #
#    Updated: 2017/11/07 13:51:45 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_strcmp.c \
		srcs/ft_strlen.c \
		srcs/ft_swap.c

O_FILES = ft_putchar.o \
		  ft_putstr.o \
		  ft_strcmp.o \
		  ft_strlen.o \
		  ft_swap.o

HEADERS = -I includes/

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	$(CC) -c $(C_FLAGS) $(SRCS) $(HEADERS)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

clean :
	rm -fr $(O_FILES)

fclean : clean
	rm -rf $(NAME)

re: fclean all
