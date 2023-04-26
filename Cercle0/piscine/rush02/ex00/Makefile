SRCS	= checkArgs.c create_tab.c ft_print.c ft_read_file.c ft_strndup.c main.c
OBJS	= $(addprefix srcs/, ${SRCS:.c=.o})
NAME	= rush-02
HEAD	= includes
CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} 

re:			fclean ${NAME}
