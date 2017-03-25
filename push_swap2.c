/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_beat_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:04:39 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/17 19:33:40 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	all_in(t_arr **a, t_arr **b, int len)
{
	int		i;

	i = 0;
	if (len == 0)
		return ;
	else if (find_len(*b) == 3)
	{
		three(b);
		while (i++ < len)
			oper2("pa\n", a, b);
	}
	{
		if ((*b)->next != NULL && (*b)->val < (*b)->next->val)
			oper("sb\n", b);
		while (i < len)
		{
			oper2("pa\n", a, b);
			i++;
		}
	}
}

void	all_in_2(t_arr **a, t_arr **b, int len)
{
	int		i;

	i = 0;
	if (len == 0)
		return ;
	else
	{
		while (i < len)
		{
			oper("rrb\n", b);
			i++;
		}
		if ((*b)->val < (*b)->next->val)
			oper("sb\n", b);
		i = 0;
		while (i < len)
		{
			oper2("pa\n", a, b);
			i++;
		}
	}
}

void	swap_a(t_arr **a)
{
	if ((*a)->val > (*a)->next->val)
		oper("sa\n", a);
}

int		if_less(t_arr *a, int len, int mid, int flag)
{
	int		i;

	i = 0;
	while (i++ < len)
	{
		if (flag == 0)
			if (a->val <= mid)
				return (1);
		if (flag == 1)
			if (a->val > mid)
				return (1);
		if (flag == 3)
			if (a->val < mid)
				return (1);
		a = a->next;
	}
	return (0);
}

int		if_less_end(t_arr *a, int len, int mid, int flag)
{
	int		i;

	i = 0;
	while (a->next != NULL)
		a = a->next;
	while (i++ < len)
	{
		if (flag == 0)
			if (a->val > mid)
				return (1);
		if (flag == 1)
			if (a->val < mid)
				return (1);
		a = a->prev;
	}
	return (0);
}
