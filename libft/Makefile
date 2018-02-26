# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:26:25 by ynacache          #+#    #+#              #
#    Updated: 2018/01/09 17:21:38 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = srcs/ft_strlen.c \
		srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_putendl.c \
		srcs/ft_putnbr.c \
		srcs/ft_putchar_fd.c \
		srcs/ft_putstr_fd.c \
		srcs/ft_putendl_fd.c \
		srcs/ft_putnbr_fd.c \
		srcs/ft_strcmp.c \
		srcs/ft_strncmp.c \
		srcs/ft_strcpy.c \
		srcs/ft_strncpy.c \
		srcs/ft_strcat.c \
		srcs/ft_strncat.c \
		srcs/ft_toupper.c \
		srcs/ft_tolower.c \
		srcs/ft_isalpha.c \
		srcs/ft_isdigit.c \
		srcs/ft_isalnum.c \
		srcs/ft_isascii.c \
		srcs/ft_isprint.c \
		srcs/ft_atoi.c \
		srcs/ft_itoa.c \
		srcs/ft_strstr.c \
		srcs/ft_strnstr.c \
		srcs/ft_strchr.c \
		srcs/ft_strrchr.c \
		srcs/ft_memalloc.c \
		srcs/ft_memdel.c \
		srcs/ft_strnew.c \
		srcs/ft_strdel.c \
		srcs/ft_strclr.c \
		srcs/ft_striter.c \
		srcs/ft_striteri.c \
		srcs/ft_strmap.c \
		srcs/ft_strmapi.c \
		srcs/ft_strequ.c \
		srcs/ft_strnequ.c \
		srcs/ft_strsub.c \
		srcs/ft_strjoin.c \
		srcs/ft_strtrim.c \
		srcs/ft_strsplit.c \
		srcs/ft_strdup.c \
		srcs/ft_memset.c \
		srcs/ft_bzero.c \
		srcs/ft_memcpy.c \
		srcs/ft_memccpy.c \
		srcs/ft_memmove.c \
		srcs/ft_memchr.c \
		srcs/ft_memcmp.c \
		srcs/ft_strlcat.c \
		srcs/list/ft_lstnew.c \
		srcs/list/ft_lstdelone.c \
		srcs/list/ft_lstdel.c \
		srcs/list/ft_lstadd.c \
		srcs/list/ft_lstiter.c \
		srcs/list/ft_lstmap.c \
		srcs/bonus/ft_iseven.c \
		srcs/bonus/ft_isodd.c \
		srcs/bonus/ft_str_is_printable.c \
		srcs/bonus/ft_abs.c \
		srcs/bonus/ft_free.c \
		srcs/bonus/ft_strlowcase.c \
		srcs/bonus/ft_strupcase.c \
		srcs/bonus/ft_strndup.c \
		srcs/bonus/ft_latoi.c \
		srcs/gnl/get_next_line.c

HFILES = includes/libft.h \
		includes/get_next_line.h


CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC = -I includes
OBJS_DIR = objs/

SRCS := $(FILES)
OBJS := $(addprefix $(OBJS_DIR), $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS_DIR)%.o: %.c $(HFILES) $(OBJS_DIR)
	$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)
	mkdir -p $(dir $(OBJS))

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
