

# VAR ---------------------------------------------------------------
OBJS_DIR		=	.objs/
SRCS			=	main.c read_file.c draw.c\
					utils/get_next_line.c utils/printf.c utils/split.c utils/utils1.c utils/utils2.c utils/utils3.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))

NAME			=	fdf
CC				=	cc
FLAGS			=	-Wall -Wextra -Werror -MMD -MP -fPIC
RF				=	rm -rf
MLX_NAME		=	libmlx.a

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
MLX_DIR			=	./mlx/linux/
MLX_FLAGS		=	-lXext -lX11 -lz
endif

ifeq ($(UNAME), Darwin)
MLX_DIR			=	./mlx/mac/
MLX_FLAGS		=	-framework OpenGL -framework AppKit
endif

# RULES -------------------------------------------------------------
all:				mlx $(NAME)

run:				all
					./$(NAME) test_maps/42.fdf

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) $(MLX_DIR)$(MLX_NAME) $(MLX_FLAGS) -o $(NAME)

-include $(DEP)
$(OBJS_DIR)%.o:		%.c
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)utils
					$(CC) $(FLAGS) -c $< -o $@

mlx:
					make -C $(MLX_DIR)

clean:
					$(RF) $(OBJS_DIR)
					make clean -C $(MLX_DIR)

fclean:				clean
					$(RF) $(NAME)

re:					fclean all

.PHONY:				all mlx clean fclean re run