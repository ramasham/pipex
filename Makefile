NAME = pipex
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include

SRCS = src/parent.c src/child_process.c utils/get_cmd_path.c utils/erros.c \

OBJ = $(SRCS:.c=.o)

all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) | libft
	@$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBFT)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft