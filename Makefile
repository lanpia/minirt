# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soohkang <soohkang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 22:18:47 by soohkang          #+#    #+#              #
#    Updated: 2024/01/03 11:50:10 by soohkang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

LIBFT		= libft

LIBFT_LIB	= libft.a

MLX			= mlx

MLX_LIB		= libmlx.a
# MLX		= minilibx-linux
# MLX_LIB	= libmlx_Linux.a

SRCS		= minirt.c \
			_parse/parse_check_data_condition.c \
			_parse/parse_extension.c \
			_parse/parse_open_scene_file.c \
			_raytracing/camera.c \
			_utils/mlx_handling.c \
			_vector/vector_operations.c

OBJS 		= $(SRCS:.c=.o)

OBJS 		= $(addprefix obj/,$(SRCS:.c=.o))

OBJS_BONUS 	= $(addprefix obj/,$(SRCS_BONUS:.c=.o))

LIBC		= ar rc

CC 			= cc

CFLAGS 		= -Wall -Wextra -Werror -g -g3 -fsanitize=address

RM 			= rm -rf

GREEN		= "\033[1;32m"
WHITE		= "\033[0m"
RED			= "\033[0;31m"

ifdef BONUS
	OBJ_CUR = $(OBJS_BONUS)
else
	OBJ_CUR = $(OBJS)
endif

all			:	$(NAME)

$(NAME): $(OBJ_CUR)
		@make all -C $(LIBFT)/
		@make all -C $(MLX)/
		@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/$(LIBFT_LIB) $(MLX)/$(MLX_LIB) -framework OpenGL -framework AppKit -lz -lm
		@echo ${GREEN} "Compilation Done ✅"

bonus:
		make BONUS=1 all

obj/%.o : %.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) obj/*.o
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

# @$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/$(LIBFT_LIB) $(MLX)/$(MLX_LIB) -lz -lXext -lX11 -lm