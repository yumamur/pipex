NAME = pipex

RM		= /bin/rm
CC		= /bin/clang
CFLAGS	= -Wall -Werror -Wextra

LIBFT		= $(patsubst Makefile, libft.a, $(wildcard libft/Makefile))
DIR_LIBFT	= $(dir $(LIBFT))

SRC			= $(wildcard ./src/mandatory/*)
SRC_BONUS	= $(wildcard ./src/bonus/*)

$(NAME): $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(SRC) -o $(NAME)

$(LIBFT):
	@make -C $(DIR_LIBFT)

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(LIBFT)
	@$(CC) $(CFLAGS) $(LIBFT) $(HEADER_BONUS) $(SRC_BONUS) -o $(NAME)
clean:
	@$(RM) $(NAME)
	@make -C $(DIR_LIBFT) -E clean

fclean:
	@$(RM) $(NAME)
	@make -C $(DIR_LIBFT) -E fclean
