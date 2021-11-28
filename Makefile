NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	main.c\
		src/index.c\
		src/operations.c\
		src/sort.c\
		src/utils.c\
		libft/libft.a\

$(NAME) :
	make bonus -C libft
	gcc -fsanitize=address $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all