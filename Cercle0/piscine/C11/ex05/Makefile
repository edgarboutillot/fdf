# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edboutil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 14:05:07 by edboutil          #+#    #+#              #
#    Updated: 2022/08/25 14:06:30 by edboutil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS		= do-op.c
NAME		= do-op
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:
			${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean:
			${RM} *.o

fclean:		clean
			${RM} ${NAME}

.PHONY:	all clean fclean
