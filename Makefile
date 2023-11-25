NAME		= miniRT
LIBFT		= libft
LIBFT_LIB	= libft.a
# MLX			= minilibx_opengl_20191021
# MLX_LIB		= libmlx.a
MLX			= minilibx-linux
MLX_LIB		= libmlx_Linux.a
SRCS		= minirt.c \
				file_read.c \
				camera.c \
				vector.c \
				util.c \
				draw.c
OBJS 		= $(SRCS:.c=.o)
SRCS_BONUS = bonus/minirt_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
LIBC		= ar rc
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g #-g3 -fsanitize=address
RM 			= rm -rf

GREEN		=	"\033[1;32m"
WHITE		=	"\033[0m"
RED			=	"\033[0;31m"

ifdef BONUS
	OBJ_CUR = $(OBJS_BONUS)
else
	OBJ_CUR = $(OBJS)
endif

all			:	$(NAME)

$(NAME): $(OBJ_CUR)
		@make all -C $(LIBFT)/
		@make all -C $(MLX)/
		$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/$(LIBFT_LIB) $(MLX)/$(MLX_LIB) -lz -lXext -lX11 -lm
		@echo ${GREEN} "Compilation Done ✅"

bonus:
	make BONUS=1 all

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS) $(OBJS_BONUS)
		@make clean -C $(LIBFT)
		@make clean -C $(MLX)
		@echo ${RED}"Object Files Deleted"${WHITE}

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT_LIB)
		@make fclean -C $(LIBFT)
		@echo ${RED}"Executable Files Deleted"${WHITE}

re : fclean all

.PHONY : all clean fclean re bonus