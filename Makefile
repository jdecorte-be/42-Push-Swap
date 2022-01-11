NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	main.c\
		src/index.c\
		src/ope1.c\
		src/ope2.c\
		src/sort_handler.c\
		src/utils.c\
		libft/libft.a\
		src/quick_a.c\
		src/quick_b.c\

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