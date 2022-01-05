# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namseoa <namseoa@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 13:21:01 by senam             #+#    #+#              #
#    Updated: 2022/01/05 12:29:16 by namseoa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =	ft_atoi.c ft_putnbr_fd.c ft_strlen.c \
					ft_convert_textws.c ft_is_numstr.c ft_strdup.c \

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