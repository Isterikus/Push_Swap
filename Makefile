NAME = push_swap

FLAGS = -Wall -Wextra -Werror

LIBA = ./libft/libftprintf.a

BOTH_C = both.c both_check.c both_create.c both_opers.c

BOTH_O = both.o both_check.o both_create.o both_opers.o

CHECKER_C = checker.c checker_flags.c checker_getstr.c

CHECKER_O = checker.o checker_flags.o checker_getstr.o

PUSH_C = push_swap.c push_swap1.c push_swap2.c push_swap_beats.c push_swap_help.c push_swap_middle.c push_swap_minsolve.c

PUSH_O = push_swap.o push_swap1.o push_swap2.o push_swap_beats.o push_swap_help.o push_swap_middle.o push_swap_minsolve.o

all: checker push

checker: $(BOTH_O) $(CHECKER_O)
	@ make -C ./libft
	gcc $(FLAGS) $(BOTH_O) $(CHECKER_O) $(LIBA) -o checker

push: $(BOTH_O) $(PUSH_O)
	@ make -C ./libft
	gcc $(FLAGS) $(BOTH_O) $(PUSH_O) $(LIBA) -o push_swap

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	@ make clean -C ./libft
	@rm -f *.o

fclean: clean
	@rm -f checker push_swap $(LIBA)
	@echo "cleaned push_swap"

re: fclean all
