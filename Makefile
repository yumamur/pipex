NAME	= pipex
TITLE	= \033[38;2;180;30;80;1m[PIPEX]\033[m

RM		= rm
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address

LIBFT_DIR		= ./src/libft
LIBFT_HEADERS	= $(LIBFT_DIR)/include
LIBFT			= $(LIBFT_DIR)/libft.a

SRC			= $(wildcard ./src/mandatory/*.c)
SRC_BONUS	= $(wildcard ./src/bonus/*.c)

$(NAME): $(SRC)
	@printf "$(TITLE) \033[1mMandatory\033[m\n"
	@printf "$(TITLE) Building 'libft.a'\n"
	@make -sC $(LIBFT_DIR)
	@mkdir -p ./include/libft
	@cp -r $(LIBFT_HEADERS)/* ./include/libft/
	@printf "$(TITLE) Building '$(NAME)'\n"
	@$(CC) $(CFLAGS) -I./include $(SRC) $(LIBFT) -o $(NAME)
	@printf "$(TITLE) Successful\n"

.PHONY: all bonus clean fclean re

all: $(NAME) $(HELP)

bonus: $(SRC_BONUS) $(HELP_BONUS)
	@printf "$(TITLE) \033[1mBonus\033[m\n"
	@printf "$(TITLE) Building 'libft.a'\n"
	@make -sC $(LIBFT_DIR)
	@mkdir -p ./include/libft
	@cp -r $(LIBFT_HEADERS)/* ./include/libft/
	@printf "$(TITLE) Building '$(NAME)'\n"
	@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME) 
	@printf "$(TITLE) Successful\n"

clean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	fi \
	if [ -e ./include/libft ]; then \
		$(RM) -rf ./include/libft; \
	fi
	@make -sC $(LIBFT_DIR) clean

fclean:
	@if [ -e $(NAME) ]; then \
		$(RM) -rf $(NAME); \
	fi \
	if [ -e ./include/libft ]; then \
		$(RM) -rf ./include/libft; \
	fi
	@make -sC $(LIBFT_DIR) fclean

re: fclean all
