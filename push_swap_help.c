/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:56:06 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/20 10:56:39 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	all_from_b(t_arr **a, t_arr **b)
{
	int		i;

	i = 0;
	do_b(a, b);
	i = find_len(*b);
	while (i-- > 0)
		oper2("pa\n", a, b);
}

int		to_do_b(t_arr **a, t_arr **b, int middle)
{
	if ((*b)->val > middle)
	{
		oper2("pa\n", a, b);
		return (1);
	}
	else
	{
		oper("rb\n", b);
		return (0);
	}
}

int		to_do_a(t_arr **a, t_arr **b, int middle)
{
	if ((*a)->val < middle)
	{
		oper2("pb\n", a, b);
		return (1);
	}
	else
	{
		oper("ra\n", a);
		return (0);
	}
}

int		to_do_b_rr(t_arr **a, t_arr **b, int middle, int *j)
{
	oper("rra\n", a);
	(*j)++;
	if ((*a)->val < middle)
	{
		oper2("pb\n", a, b);
		return (1);
	}
	return (0);
}

void	nax(t_arr **a, int len)
{
	int		i;

	i = 0;
	while (i++ < len)
		oper("rra\n", a);
	swap_a(a);
}
