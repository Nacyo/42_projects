# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/12 19:09:28 by ynacache          #+#    #+#              #
#    Updated: 2017/11/23 11:04:49 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c \
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
	   ft_strsplit.c \
	   ft_iseven.c \
	   ft_isodd.c \
	   ft_strupcase.c \
	   ft_strlowcase.c \
	   ft_str_is_printable.c

O_FILES = $(SRCS:c=o)

HEADERS = -I ./includes

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(O_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)
  
%.o: %.c
	$(CC) -c $(C_FLAGS) $(HEADERS) $<

clean :
	rm -rf $(O_FILES)

fclean : clean
	rm -rf $(NAME)

re : fclean all
