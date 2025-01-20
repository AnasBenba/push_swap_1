CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker

SRC = main.c push_swap.c instructions.c instructions2.c instructions3.c functions.c functions2.c\
functions3.c functions4.c functions5.c functions6.c functions7.c 

BONUS_SRC = checker.c checker_sort.c checker_func3.c checker_func6.c checker_inst3.c checker_func2.c\
checker_func4.c checker_func.c checker_inst2.c checker_inst.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: clean