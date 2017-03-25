/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_beats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:57:48 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/20 11:21:35 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		to_do_a_rr(t_arr **a, t_arr **b, int middle, int *j)
{
	oper("rrb\n", b);
	(*j)++;
	if ((*b)->val > middle)
	{
		oper2("pa\n", a, b);
		return (1);
	}
	return (0);
}

void	beat_to_a(t_arr **a, t_arr **b, int len)
{
	int		i;
	int		middle;
	int		pushed;

	if (len < 3 || find_len(*b) == 3)
	{
		(len < 3) ? all_in(a, b, len) : 0;
		(find_len(*b) == 3) ? all_from_b(a, b) : 0;
		return ;
	}
	middle = find_middle(*b, len);
	i = 0;
	pushed = 0;
	while (i++ < len && if_less(*b, len - i + 1, middle, 1))
		pushed += to_do_b(a, b, middle);
	beat_to_b(a, b, pushed);
	if (--i - pushed != 0 && len - pushed != find_len(*b))
		beat_to_a_rr(a, b, i - pushed, len - i);
	else
		beat_to_a(a, b, len - pushed);
}

void	beat_to_b(t_arr **a, t_arr **b, int len)
{
	int		i;
	int		middle;
	int		pushed;

	if (len < 3)
	{
		swap_a(a);
		return ;
	}
	middle = find_middle(*a, len);
	i = 0;
	pushed = 0;
	while (i++ < len && if_less(*a, len - i + 1, middle, 3))
		pushed += to_do_a(a, b, middle);
	if (--i - pushed > 0)
		beat_to_b_rr(a, b, i - pushed, len - i);
	else
		beat_to_b(a, b, len - pushed);
	beat_to_a(a, b, pushed);
}

void	beat_to_b_rr(t_arr **a, t_arr **b, int len, int ra)
{
	int		i;
	int		middle;
	int		pushed;
	int		yt;
	int		j;

	i = 0;
	if (len + ra < 3)
	{
		nax(a, len);
		return ;
	}
	middle = find_middle_all(*a, ra, len);
	j = 0;
	pushed = 0;
	while (j < len && if_less_end(*a, len + ra - pushed, middle, 1))
		pushed += to_do_b_rr(a, b, middle, &j);
	yt = 0;
	while (ra != 0 && i++ < j + ra - pushed &&
			if_less(*a, j + ra - pushed - yt, middle, 3))
		yt += to_do_a(a, b, middle);
	(ra != 0) ? (i--) : 0;
	beat_to_b_rr(a, b, i - yt + len - j, ra + j - pushed - yt - i + yt);
	beat_to_a(a, b, pushed + yt);
}

void	beat_to_a_rr(t_arr **a, t_arr **b, int len, int ra)
{
	int		i;
	int		middle;
	int		pushed;
	int		yt;
	int		j;

	i = 0;
	if (len + ra < 3 || find_len(*b) == 3 || ra + len == find_len(*b))
	{
		nax2(a, b, len, ra);
		return ;
	}
	middle = find_middle_all(*b, ra, len);
	j = 0;
	pushed = 0;
	while (j < len && if_less_end(*b, len + ra - pushed, middle, 0))
		pushed += to_do_a_rr(a, b, middle, &j);
	i = 0;
	yt = 0;
	while (ra != 0 && i++ < ra + j - pushed &&
			if_less(*b, j + ra - pushed - yt, middle, 1))
		yt += to_do_b(a, b, middle);
	(ra != 0) ? (i--) : 0;
	beat_to_b(a, b, pushed + yt);
	beat_to_a_rr(a, b, i - yt + len - j, ra + j - pushed - i);
}
