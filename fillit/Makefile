# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emarin <emarin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 13:32:09 by emarin            #+#    #+#              #
#    Updated: 2017/11/20 10:15:43 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

NAME2 = libft.a

SRC =  ft_validp.c \
	   ft_voisin.c \
	   ft_validtetriminos.c \
	   ft_fillit.c \
	   ft_realloctab.c \
	   ft_fillitmove.c \
	   main.c

SRC2 = ft_isdigit.c \
	   ft_lstnew.c \
	   ft_memset.c \
	   ft_putstr_fd.c \
	   ft_strequ.c \
	   ft_strncat.c \
	   ft_strstr.c \
	   ft_isprint.c \
	   ft_memalloc.c \
	   ft_putchar.c \
	   ft_strcat.c \
	   ft_striter.c \
	   ft_strncmp.c \
	   ft_strsub.c \
	   ft_itoa.c \
	   ft_memccpy.c \
	   ft_putchar_fd.c \
	   ft_strchr.c \
	   ft_striteri.c \
	   ft_strncpy.c \
	   ft_strtrim.c \
	   ft_atoi.c \
	   ft_lstadd.c \
	   ft_memchr.c \
	   ft_putendl.c \
	   ft_strclr.c \
	   ft_strjoin.c \
	   ft_strnequ.c \
	   ft_tolower.c \
	   ft_bzero.c \
	   ft_lstdel.c \
	   ft_memcmp.c \
	   ft_putendl_fd.c \
	   ft_strcmp.c \
	   ft_strlcat.c \
	   ft_strnew.c \
	   ft_toupper.c \
	   ft_isalnum.c \
	   ft_lstdelone.c \
	   ft_memcpy.c \
	   ft_putnbr.c \
	   ft_strcpy.c \
	   ft_strlen.c \
	   ft_strnstr.c \
	   ft_isalpha.c \
	   ft_lstiter.c \
	   ft_memdel.c \
	   ft_putnbr_fd.c \
	   ft_strdel.c \
	   ft_strmap.c \
	   ft_strrchr.c \
	   ft_isascii.c \
	   ft_lstmap.c \
	   ft_memmove.c \
	   ft_putstr.c \
	   ft_strdup.c \
	   ft_strmapi.c \
	   ft_strsplit.c

OBJ = $(SRC:.c=.o) 

OBJ2 = $(SRC2:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBFT = -L. -lft

HEADERS = -I ./

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	ar rc $(NAME2) $(OBJ2)
	ranlib $(NAME2)
	gcc -o $(NAME) $(OBJ) $(LIBFT)


%.o: %.c
	gcc -c $(FLAGS) $<

clean:
	rm -f $(OBJ) $(OBJ2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all, clean, fclean, re
