# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 18:07:02 by plisieck          #+#    #+#              #
#    Updated: 2016/11/27 22:40:02 by aboudjem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES_PATH = includes
SRCS = ft_isascii.c ft_memcmp.c ft_strchr.c ft_strlen.c ft_strrchr.c 		\
	  ft_atoi.c ft_isdigit.c ft_memcpy.c ft_strcmp.c ft_strncat.c 			\
	  ft_strstr.c ft_bzero.c ft_isprint.c ft_memmove.c ft_strcpy.c 			\
	  ft_strncmp.c ft_tolower.c ft_isalnum.c ft_memccpy.c ft_memset.c 		\
	  ft_strdup.c ft_strncpy.c ft_toupper.c ft_isalpha.c ft_memchr.c 		\
	  ft_strcat.c ft_strlcat.c ft_strnstr.c ft_strsplit.c ft_itoa.c			\
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c 		\
	  ft_striter.c ft_striteri.c ft_strmap.c ft_putchar.c ft_putstr.c 		\
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c 		\
	  ft_strtrim.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_exit.c      	\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstadd.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_hsqrt.c      	\
	  ft_sort_ascii.c ft_revtab.c                               			\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c $(INCLUDES_PATH)/libft.h
	@$(CC) $(FLAGS) -c -o $@ $< -I $(INCLUDES_PATH)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
