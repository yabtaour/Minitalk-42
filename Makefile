# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 20:14:41 by yabtaour          #+#    #+#              #
#    Updated: 2022/01/11 21:35:17 by yabtaour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: client server

CC=gcc

HEADER=minitalk.h

UTILS=minitalk_utils.o

FLAGS=-Wall -Wextra -Werror

%.o : %.c minitalk_utils.c
	$(CC) $(FLAGS) -c $< -o $@

server : server.o $(UTILS)
	$(CC) $(FLAGS) -o $@ $^

client : client.o $(UTILS)
	$(CC) $(FLAGS) -o $@ $^
	
clean :
	rm -rf client.o server.o $(UTILS)

fclean: clean
	rm -rf server client

re: fclean all
