
# VAR ---------------------------------------------------------------
OBJS_DIR		=	.OBJS/
SRCS			=	utils/printf.c utils/split.c utils/get_next_line.c utils/utils1.c utils/utils2.c\
					read_file.c\
                    main.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))

NAME			=	fdf
HEAD_DIR		=	INCLUDES/

CC				=	cc
RM				=	rm -rf
FLAGS			=	-Wall -Wextra -Werror -g3
FLAGS			+=	-MMD -MP


# RULES -------------------------------------------------------------
all:                $(NAME)

run:				all
					./$(NAME)

norm:
					norminette

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEP)
$(OBJS_DIR)%.o:		%.c | dir
					$(CC) $(FLAGS) -I $(HEAD_DIR) -c $< -o $@

dir:
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)/utils

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME) $(NAME_BON)

re:					fclean all

.PHONY:				all run norm dir clean fclean re