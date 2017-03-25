/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:03:00 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/20 11:58:16 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	oper(char *str, t_arr **a)
{
	ft_putstr(str);
	if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n"))
		swap_two(a);
	else if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rrb\n"))
		shift_up(a);
	else if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n"))
		shift_down(a);
}

void	oper2(char *str, t_arr **a, t_arr **b)
{
	ft_putstr(str);
	if (ft_strcmp(str, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(b, a);
}

void	sort_it(int **sort_a, int len)
{
	int		i;
	int		j;
	int		temp;

	j = 0;
	while (j < len)
	{
		i = 1;
		while (i < len)
		{
			if ((*sort_a)[i - 1] > (*sort_a)[i])
			{
				temp = (*sort_a)[i - 1];
				(*sort_a)[i - 1] = (*sort_a)[i];
				(*sort_a)[i] = temp;
			}
			i++;
		}
		j++;
	}
}

int		sort(int **sort_a, t_arr *a)
{
	int		i;
	t_arr	*temp;

	i = 0;
	temp = a;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	*sort_a = (int *)malloc(sizeof(int) * i);
	i = 0;
	temp = a;
	while (temp != NULL)
	{
		(*sort_a)[i++] = temp->val;
		temp = temp->next;
	}
	sort_it(sort_a, i);
	return (i);
}

int		find_len(t_arr *a)
{
	int		i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}
