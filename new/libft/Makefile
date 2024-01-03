NAME = libft.a
SRCS = arr/ft_2d_arr_free.c \
		arr/ft_3d_arr_free.c \
		arr/ft_bzero.c \
		arr/ft_calloc.c \
		arr/ft_realloc.c \
		fd/ft_putchar_fd.c \
		fd/ft_putchar_fd.c \
		fd/ft_putstr_fd.c \
		fd/ft_putendl_fd.c \
		fd/ft_putnbr_fd.c \
		fd/get_next_line_bonus.c \
		fd/get_next_line.c \
		int/ft_ltoa.c \
		int/ft_itoa.c \
		int/ft_max.c \
		int/ft_min.c \
		int/ft_swap.c \
		is/ft_isalnum.c \
		is/ft_isalpha.c \
		is/ft_isascii.c \
		is/ft_isdigit.c \
		is/ft_isprint.c \
		is/ft_isspace.c \
		is/ft_isvalid_number.c \
		is/ft_tolower.c \
		is/ft_toupper.c \
		list/ft_decadd_back.c \
		list/ft_decadd_front.c \
		list/ft_decdel_back.c \
		list/ft_decdel_front.c \
		list/ft_decnew.c \
		list/ft_lstadd_back.c \
		list/ft_lstadd_front.c \
		list/ft_lstclear.c \
		list/ft_lstdelone.c \
		list/ft_lstfree.c \
		list/ft_lstiter.c \
		list/ft_lstlast.c \
		list/ft_lstmap.c \
		list/ft_lstnew.c \
		list/ft_lstprint.c \
		list/ft_lstsize.c \
		memory/ft_memchr.c \
		memory/ft_memcmp.c \
		memory/ft_memcpy.c \
		memory/ft_memmove.c \
		memory/ft_memset.c \
		printf/ft_format.c \
		printf/ft_format2.c \
		printf/ft_printf.c \
		str/ft_atof.c \
		str/ft_atoi.c \
		str/ft_atol.c \
		str/ft_exit.c \
		str/ft_split.c \
		str/ft_split_bonus.c \
		str/ft_strchr.c \
		str/ft_strcmp.c \
		str/ft_strcspn.c \
		str/ft_strdup.c \
		str/ft_striteri.c \
		str/ft_strfilteri.c \
		str/ft_strjoin.c \
		str/ft_strlcat.c \
		str/ft_strlcpy.c \
		str/ft_strlen.c \
		str/ft_strmapi.c \
		str/ft_strncmp.c \
		str/ft_strnstr.c \
		str/ft_strrchr.c \
		str/ft_strtok.c \
		str/ft_strtrim.c \
		str/ft_substr.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGES = -Wall -Wextra -Werror
INCLUDE = libft.h 
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	@ar -rsc $@ $^
#	@echo ${GREEN} "LIBFT ✅"
.c.o:
		@$(CC) $(CFLAGES) -c $< -o $@

clean: 
		@$(RM) $(OBJS)
#		@echo ${RED}"Object Files Deleted LIBFT"${WHITE}

fclean: clean
		@$(RM) $(NAME)
#		@echo ${RED}"Executable Files Deleted LIBFT"${WHITE}
re : fclean all

.PHONY : all clean fclean re