

# VAR ---------------------------------------------------------------
OBJS_DIR		=	.objs/
SRCS			=	main.c \
					src/init.c src/parsing.c src/hook.c src/draw.c \
					utils/get_next_line.c utils/printf.c utils/maths.c utils/split.c utils/error.c utils/free.c utils/lst.c utils/atoi.c \
					utils/str/str_len.c utils/str/str_endwith.c utils/str/str_cmp.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))

NAME			=	fdf
CC				=	cc
FLAGS			=	-Wall -Wextra -Werror -MMD -MP -fsanitize=address -g3
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
					@mkdir -p $(OBJS_DIR)utils/str
					@mkdir -p $(OBJS_DIR)src
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