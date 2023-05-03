NAME = pipex

RM		= /bin/rm
CC		= /bin/clang
CFLAGS	= -Wall -Werror -Wextra

LIBFT_DIR	= ./src/libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= $(wildcard ./src/mandatory/*)
SRC_BONUS	= $(wildcard ./src/bonus/*)

$(NAME): $(LIBFT) $(SRC)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR)/include -I./include $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

.PHONY: all bonus clean fclean re

all: $(NAME)

# bonus: $(LIBFT) $(SRC)
#	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME) 

clean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	else \
		continue; \
	fi
	@make -sC $(LIBFT_DIR) clean

fclean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	else \
		continue; \
	fi
	@make -sC $(LIBFT_DIR) fclean

re: fclean all
