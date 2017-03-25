/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_minsolve.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:05:52 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/13 13:05:45 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	doo_b(t_arr **a, t_arr **b)
{
	if ((*b)->next->val < (*b)->next->next->val &&
		(*b)->next->next->val < (*b)->val)
	{
		oper2("pa\n", a, b);
		oper("sb\n", b);
	}
	else if ((*b)->val < (*b)->next->val &&
		(*b)->next->val < (*b)->next->next->val)
	{
		oper("rrb\n", b);
		oper2("pa\n", a, b);
		oper("sb\n", b);
	}
}

void	do_b(t_arr **a, t_arr **b)
{
	if (find_len(*b) < 2)
		return ;
	else if (find_len(*b) < 3)
	{
		if ((*b)->val < (*b)->next->val)
			oper("sb\n", b);
	}
	else if ((*b)->val < (*b)->next->next->val &&
		(*b)->next->next->val < (*b)->next->val)
		oper("rb\n", b);
	else if ((*b)->val > (*b)->next->val && (*b)->val < (*b)->next->next->val)
		oper("rrb\n", b);
	else if ((*b)->next->next->val < (*b)->val && (*b)->val < (*b)->next->val)
		oper("sb\n", b);
	else
		doo_b(a, b);
}

void	three(t_arr **a)
{
	if ((*a)->val < (*a)->next->next->val &&
		(*a)->next->next->val < (*a)->next->val)
	{
		oper("sa\n", a);
		oper("ra\n", a);
	}
	else if ((*a)->val > (*a)->next->val && (*a)->val < (*a)->next->next->val)
		oper("sa\n", a);
	else if ((*a)->next->next->val < (*a)->val && (*a)->val < (*a)->next->val)
		oper("rra\n", a);
	else if ((*a)->next->val < (*a)->next->next->val &&
		(*a)->next->next->val < (*a)->val)
		oper("ra\n", a);
	else if ((*a)->val > (*a)->next->val &&
		(*a)->next->val > (*a)->next->next->val)
	{
		oper("sa\n", a);
		oper("rra\n", a);
	}
}

void	solve(t_arr **a, int len)
{
	t_arr	*b;
	int		middle;

	b = NULL;
	middle = find_middle(*a, len);
	if (len % 6 == 0)
		middle++;
	while (len > 3)
	{
		if ((*a)->val < middle)
		{
			oper2("pb\n", a, &b);
			len--;
		}
		else
			oper("rra\n", a);
	}
	if (find_len(*a) == 2)
		swap_a(a);
	else
		three(a);
	do_b(a, &b);
	while (b != NULL)
		oper2("pa\n", a, &b);
}

int		if_sort(t_arr *a)
{
	while (a->next != NULL)
	{
		if (a->next->val < a->val)
			return (0);
		a = a->next;
	}
	return (1);
}
