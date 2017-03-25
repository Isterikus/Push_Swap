# Push_Swap

Our fifth project in UNIT Factory.

The Push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

There are two programs on C:

The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

The second one called push_swap which calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.

Array must contain only unique numbers within the integer size.

To solve this problem i used sorting algorithm called quicksort.

Avialable commands:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.

rrr : rra and rrb at the same time.

Also i managed some bonuses, you can use such flags on checker: c, n, v.
c - set output in color;
n - displays the number of operations;
v - displays arrays after every command;

Usage example:
$>./push_swap 3 5 4 1

$>ARG="(array of integers)"; ./push_swap $ARG | ./checker -vc $ARG

Also i submit randomizer executable(rand) which create array of unique integers.

./rand (from) (to) (amount)

$>./rand 1 500 100
