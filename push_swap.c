/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:53:11 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/12 13:07:42 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	nax2(t_arr **a, t_arr **b, int len, int ra)
{
	int		i;

	i = 0;
	if (len + ra < 3)
	{
		while (i++ < len)
			oper("rrb\n", b);
		i = 0;
		while (i++ < len + ra)
			oper2("pa\n", a, b);
		swap_a(a);
	}
	else if (find_len(*b) == 3)
		all_from_b(a, b);
	if (ra + len == find_len(*b))
		beat_to_a(a, b, ra + len);
}

void	help(t_arr **a, t_arr **b, t_help **st, int temp_len)
{
	int		i;
	int		j;
	int		middle;
	int		pushed;

	j = 0;
	while ((pushed = find_len(*a)) > 3)
	{
		i = 0;
		middle = ((*st)->sort_a)[temp_len];
		while (i++ < pushed)
			if ((*a)->val < middle)
			{
				oper2("pb\n", a, b);
				((*st)->srav)[j]++;
				if (pushed - ((*st)->srav)[j] < 3)
					break ;
			}
			else
				oper("ra\n", a);
		temp_len = temp_len + ((*st)->len - temp_len) / 2;
		j++;
	}
}

void	solve2(t_arr **a, t_help *st)
{
	t_arr	*b;
	int		temp_len;
	int		j;

	st->len = sort(&(st->sort_a), (*a));
	temp_len = st->len / 2;
	b = NULL;
	st->srav = (int *)malloc(sizeof(int) * can_del(st->len));
	j = 0;
	while (j < can_del(st->len))
		(st->srav)[j++] = 0;
	help(a, &b, &st, temp_len);
	if (find_len(*a) > 2)
		three(a);
	else
		swap_a(a);
	j = can_del(st->len) - 1;
	while (j >= 0)
		beat_to_a(a, &b, (st->srav)[j--]);
	free((st->sort_a));
	free((st->srav));
}

void	fill(int argc, char **argv, t_arr **a)
{
	int		i;

	i = 1;
	if (argc < 2)
		error();
	else if (argc == 2)
	{
		check_digit_2(argv[i]);
		create_arr_2(a, argv);
	}
	else
	{
		while (i < argc)
			check_digit(argv[i++]);
		create_arr(a, argc, argv);
	}
	if ((*a)->next == NULL)
		return ;
}

int		main(int argc, char **argv)
{
	int		i;
	t_arr	*a;
	t_help	*st;

	i = 1;
	fill(argc, argv, &a);
	st = (t_help *)malloc(sizeof(t_help));
	check_duplicates(a);
	if (if_sort(a) == 1)
		return (0);
	if (find_len(a) < 7)
		solve(&a, find_len(a));
	else
		solve2(&a, st);
	free_a(&a);
	free(st);
	return (0);
}
