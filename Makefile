# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 09:03:11 by akent-go          #+#    #+#              #
#    Updated: 2022/08/12 12:33:30 by akent-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = client.c server.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft
		$(CC) -o $@ $< -Llibft -lft

client: client.o libft
		$(CC) -o $@ $< -Llibft -lft

%.o: %.c 
		$(CC) -c $(CFLAGS) $?

libft: 
		make -C libft 

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean:	clean
		rm -f server client libft/libft.a 

re : fclean all 

.PHONY: all bonus libft clean fclean re
