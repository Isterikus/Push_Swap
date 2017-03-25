/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:56:30 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/05 20:06:00 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <fcntl.h>
# include "./libft/printf_functions/includes/header.h"

typedef struct		s_arr
{
	struct s_arr	*next;
	struct s_arr	*prev;
	int				val;
}					t_arr;

typedef struct		s_flags
{
	int				colour;
	int				vers;
	int				num;
	char			*file;
}					t_flags;

typedef struct		s_help
{
	int				*sort_a;
	int				len;
	int				*srav;
}					t_help;

void				find_turn(char **str, int turn);
void				free_a(t_arr **a);
void				print_val(t_arr **a, t_flags flags, int flag);
void				print_arrays(t_arr *a, t_arr *b, int turn, t_flags flags);

int					error(void);
void				check_digit(char *str);
void				check_digit_2(char *str);
void				check_duplicates(t_arr *a);
void				num_check(long int num);

void				create_arr(t_arr **head, int argc, char **argv);
void				next_num(char **argv, int j, int *i);
void				help_arr(t_arr **temp, char **argv, int i, int j);
void				create_arr_2(t_arr **head, char **argv);

void				swap_two(t_arr **a);
void				shift_down(t_arr **a);
void				shift_up(t_arr **a);
void				push(t_arr **a, t_arr **b);

void				set_sol(int **ret, char **str);
void				read_solution(int **ret, t_flags flags);
void				output(t_flags flags, t_arr *a, t_arr *b, int i);
void				check_arr(t_arr **a, int *sol, t_flags flags);

void				rf(t_flags *flags, char **argv, int *j);
void				fill_flags(int argc, t_flags *flags);

int					ret_len(char *str);
int					get_s(char *str, int *i, int **ret, int *j);
int					get_p(char *str, int *i, int **ret, int *j);
int					get_rr(char *str, int *i, int **ret, int *j);
int					get_r(char *str, int *i, int **ret, int *j);

void				nax2(t_arr **a, t_arr **b, int len, int ra);
void				help(t_arr **a, t_arr **b, t_help **st, int temp_len);
void				solve2(t_arr **a, t_help *st);
void				fill(int argc, char **argv, t_arr **a);

void				oper(char *str, t_arr **a);
void				oper2(char *str, t_arr **a, t_arr **b);
void				sort_it(int **sort_a, int len);
int					sort(int **sort_a, t_arr *a);
int					find_len(t_arr *a);

void				all_in(t_arr **a, t_arr **b, int len);
void				all_in_2(t_arr **a, t_arr **b, int len);
void				swap_a(t_arr **a);
int					if_less(t_arr *a, int len, int mid, int flag);
int					if_less_end(t_arr *a, int len, int mid, int flag);

int					to_do_a_rr(t_arr **a, t_arr **b, int middle, int *j);
void				beat_to_a(t_arr **a, t_arr **b, int len);
void				beat_to_b(t_arr **a, t_arr **b, int len);
void				beat_to_b_rr(t_arr **a, t_arr **b, int len, int ra);
void				beat_to_a_rr(t_arr **a, t_arr **b, int len, int ra);

void				all_from_b(t_arr **a, t_arr **b);
int					to_do_b(t_arr **a, t_arr **b, int middle);
int					to_do_a(t_arr **a, t_arr **b, int middle);
int					to_do_b_rr(t_arr **a, t_arr **b, int middle, int *j);
void				nax(t_arr **a, int len);

void				fill_and(t_arr *a, int **and, int len, int len_back);
int					find_middle_all(t_arr *a, int len, int len_back);
int					find_middle(t_arr *a, int len);
int					find_middle_back(t_arr *a, int len);
int					can_del(int len);

void				doo_b(t_arr **a, t_arr **b);
void				do_b(t_arr **a, t_arr **b);
void				three(t_arr **a);
void				solve(t_arr **a, int len);
int					if_sort(t_arr *a);

#endif
