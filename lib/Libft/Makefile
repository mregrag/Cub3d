# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-bab <aait-bab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 01:45:00 by mregrag           #+#    #+#              #
#    Updated: 2024/10/03 19:05:23 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= $(shell find . -name '*.c')
OBJS 	= $(SRCS:.c=.o)
NAME    = libft.a
RM	= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
CC	= cc

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
