# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 01:45:00 by mregrag           #+#    #+#              #
#    Updated: 2024/09/10 21:24:43 by aait-bab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c get_next_line.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c \
		ft_lstsize.c ft_lstlast.c ft_lstmap.c \
		ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c \

OBJS = $(SRCS:.c=.o)
NAME    = libft.a
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
CC		= cc

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
