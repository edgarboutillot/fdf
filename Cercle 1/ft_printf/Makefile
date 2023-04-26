# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 09:17:23 by edboutil          #+#    #+#              #
#    Updated: 2022/12/19 14:50:34 by edboutil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS 	= ft_printf.c ft_print_tools.c

OBJS 	= $(SRCS:.c=.o)

NAME 	= libftprintf.a
HEAD 	= ft_printf.h
CC		= cc
RM		= rm -rf
FLAGS	= -Wall -Wextra -Werror

all:	${NAME}

%.o: %.c Makefile ${HEAD}
		${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
