# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 13:21:01 by senam             #+#    #+#              #
#    Updated: 2022/01/04 15:48:33 by namseoa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =	ft_atoi.c ft_putnbr_fd.c ft_strlen.c \

OBJS            = $(SRCS:.c=.o)

NAME            = libft.a

CC = cc
RM = rm -f
FLAGS = -Wall -Werror -Wextra

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar cr $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re