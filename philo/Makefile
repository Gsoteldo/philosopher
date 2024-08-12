# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 17:06:58 by gabo              #+#    #+#              #
#    Updated: 2024/08/12 18:30:46 by gsoteldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m
# CURRENT_FILE = 1
# TOTAL_FILES = $(words $(SRC))


NAME = philo

SRC = philo.c \
	checker.c \
	utils.c \
	initialization.c \

OBJ = $(SRC:.c=.o)

CC = gcc -g3

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) show_progress

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

show_progress:
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)It has been compiled, have a nice day.👍$(NC)"; \
	else \
		for file in $(SRC); do \
		echo "Compiling $$file "; \
		done; \
		echo "$(GREEN)Compiled: 100%$(NC)"; \
	fi

git:
	git add *
	git commit
	git push

clean:
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Full Cleaning...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Full Cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re