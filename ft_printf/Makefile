# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: senam <senam@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 14:49:39 by senam             #+#    #+#              #
#    Updated: 2021/09/26 14:49:40 by senam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB	= libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB)
	@gcc -Wall -Wextra -Werror -c *.c
	@ar -q $(NAME) *.o 

$(LIB):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@ar -q libft/$(LIB) *.o

clean:
	@rm -rf *.o libft/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/$(LIB)

re: fclean $(LIB) all
