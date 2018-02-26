# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynacache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/02 12:48:23 by ynacache          #+#    #+#              #
#    Updated: 2018/01/07 17:07:56 by ynacache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = libft/srcs/ft_strlen.c \
		libft/srcs/ft_putchar.c \
		libft/srcs/ft_putstr.c \
		libft/srcs/ft_putendl.c \
		libft/srcs/ft_putnbr.c \
		libft/srcs/ft_putchar_fd.c \
		libft/srcs/ft_putstr_fd.c \
		libft/srcs/ft_putendl_fd.c \
		libft/srcs/ft_putnbr_fd.c \
		libft/srcs/ft_strcmp.c \
		libft/srcs/ft_strncmp.c \
		libft/srcs/ft_strcpy.c \
		libft/srcs/ft_strncpy.c \
		libft/srcs/ft_strcat.c \
		libft/srcs/ft_strncat.c \
		libft/srcs/ft_toupper.c \
		libft/srcs/ft_tolower.c \
		libft/srcs/ft_isalpha.c \
		libft/srcs/ft_isdigit.c \
		libft/srcs/ft_isalnum.c \
		libft/srcs/ft_isascii.c \
		libft/srcs/ft_isprint.c \
		libft/srcs/ft_atoi.c \
		libft/srcs/ft_itoa.c \
		libft/srcs/ft_strstr.c \
		libft/srcs/ft_strnstr.c \
		libft/srcs/ft_strchr.c \
		libft/srcs/ft_strrchr.c \
		libft/srcs/ft_memalloc.c \
		libft/srcs/ft_memdel.c \
		libft/srcs/ft_strnew.c \
		libft/srcs/ft_strdel.c \
		libft/srcs/ft_strclr.c \
		libft/srcs/ft_striter.c \
		libft/srcs/ft_striteri.c \
		libft/srcs/ft_strmap.c \
		libft/srcs/ft_strmapi.c \
		libft/srcs/ft_strequ.c \
		libft/srcs/ft_strnequ.c \
		libft/srcs/ft_strsub.c \
		libft/srcs/ft_strjoin.c \
		libft/srcs/ft_strtrim.c \
		libft/srcs/ft_strsplit.c \
		libft/srcs/ft_strdup.c \
		libft/srcs/ft_memset.c \
		libft/srcs/ft_bzero.c \
		libft/srcs/ft_memcpy.c \
		libft/srcs/ft_memccpy.c \
		libft/srcs/ft_memmove.c \
		libft/srcs/ft_memchr.c \
		libft/srcs/ft_memcmp.c \
		libft/srcs/ft_strlcat.c \
		libft/srcs/list/ft_lstnew.c \
		libft/srcs/list/ft_lstdelone.c \
		libft/srcs/list/ft_lstdel.c \
		libft/srcs/list/ft_lstadd.c \
		libft/srcs/list/ft_lstiter.c \
		libft/srcs/list/ft_lstmap.c \
		libft/srcs/bonus/ft_iseven.c \
		libft/srcs/bonus/ft_isodd.c \
		libft/srcs/bonus/ft_str_is_printable.c \
		libft/srcs/bonus/ft_abs.c \
		libft/srcs/bonus/ft_free.c \
		libft/srcs/bonus/ft_strlowcase.c \
		libft/srcs/bonus/ft_strupcase.c \
		libft/srcs/bonus/ft_strndup.c \
		srcs/printf/ft_printf.c \
		srcs/printf/ft_dprintf.c \
		srcs/printf/ft_vasprintf.c \
		srcs/check/ft_parse.c \
		srcs/check/ft_check.c \
		srcs/check/ft_initarg.c \
		srcs/check/ft_forest.c \
		srcs/check/ft_checkconv.c \
		srcs/ft_strfreejoin.c \
		srcs/conv/ft_wchart.c \
		srcs/conv/ft_wchart_2.c \
		srcs/conv/ft_getheight.c \
		srcs/conv/ft_conv_bigs.c \
		srcs/conv/ft_conv_bigs_2.c \
		srcs/conv/ft_conv_s.c \
		srcs/conv/ft_fill_str_ud.c \
		srcs/conv/ft_conv_d.c \
		srcs/conv/ft_conv_o.c \
		srcs/conv/ft_conv_u.c \
		srcs/conv/ft_conv_x.c \
		srcs/conv/ft_conv_c.c \
		srcs/conv/ft_conv_n.c \
		srcs/conv/ft_conv_modulo.c \
		srcs/conv/ft_conv_invalid.c \
		srcs/conv/ft_case_conv_0.c \

HFILES = includes/ft_printf.h \
		 includes/ft_printf_2.h \
		 includes/ft_printf_struct.h \
		 libft/includes/libft.h \

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = includes/ \
		  $(LIBFT_DIR)includes
SRCS_DIR = srcs/
OBJS_DIR = objs/

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

INC := $(addprefix -I , $(INC_DIR))
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

re: fclean
	make

exec:
	clear
	make all
	$(CC) ../main.c -o ../printf_test $(INC) -L . $(CFLAGS) -lftprintf
	../printf_test

.PHONY: all clean fclean re
