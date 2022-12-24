# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 10:22:14 by edboutil          #+#    #+#              #
#    Updated: 2022/12/05 11:27:15 by edboutil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_isprint.c ft_striteri.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memcpy.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_split.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_strtrim.c\

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = ${BONUS:.c=.o}

NAME = libft.a
HEAD = libft.h
CC		= cc
RM		= rm -f
FLAGS = -Wall -Wextra -Werror

all:	${NAME}

%.o: %.c Makefile ${HEAD}
	${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
		${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	${NAME} ${BONUS_OBJS}
		ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY: all clean fclean bonus re
