

# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
SRCS			=	src/instructions.c src/tools.c src/parsing.c src/parsing_tools.c\
					instructions/rotate.c instructions/reverse_rotate.c \
					utils/list.c utils/printf.c \
                    main.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))

NAME			=	push_swap
HEAD_DIR		=	INCLUDES/

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3


# RULES -------------------------------------------------------------
all:                $(NAME)

run:				all
					./$(NAME) 6 4 3 0 18 4

norm:
					norminette

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

~include = $(DEP)
$(OBJS_DIR)%.o:		%.c Makefile | dir
					$(CC) $(FLAGS) -I $(HEAD_DIR) -c $< -o $@

dir:
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)/src
					@mkdir -p $(OBJS_DIR)/instructions
					@mkdir -p $(OBJS_DIR)/utils

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BON)

re:					fclean all

.PHONY:				all run norm dir clean fclean re