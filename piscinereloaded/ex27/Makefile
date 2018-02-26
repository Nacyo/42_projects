# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:55:23 by ynacache          #+#    #+#              #
#    Updated: 2017/11/07 13:49:25 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS = ft_display_file.c

O_FILES = ft_display_file.o

CC = gcc

C_FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	$(CC) -c $(C_FLAGS) $(SRCS)
	$(CC) -o $(C_FILES) $(NAME) $(O_FILES)

clean :
	rm -rf $(O_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all
