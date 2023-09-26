NAME = libftprintf.a
LIBFT = libft/libft.a
SRC = ft_printf.c
OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft/

$(NAME): $(LIBFT) $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@gcc $(FLAGS) -I libft/ -I . -c $< -o $@

clean:
	@make clean -C libft/
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
