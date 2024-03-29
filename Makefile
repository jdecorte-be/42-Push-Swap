NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/main.c\
		src/index.c\
		src/ope1.c\
		src/ope2.c\
		src/ope3.c\
		src/ope4.c\
		src/quick_sort.c\
		src/sort_handler.c\
		src/sort_utils.c\
		libft/libft.a\

SRCS_BONUS = src_bonus/checker_bonus.c\
			src_bonus/ope1_bonus.c\
			src_bonus/ope2_bonus.c\
			src_bonus/ope3_bonus.c\
			src_bonus/ope4_bonus.c\
			src_bonus/utils_bonus.c\
			libft/libft.a\

$(NAME) :
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : 
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o checker