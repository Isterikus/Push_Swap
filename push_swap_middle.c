/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_middle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:03:51 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/20 11:52:20 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fill_and(t_arr *a, int **and, int len, int len_back)
{
	int		i;

	i = 0;
	while (i < len && a != NULL)
	{
		(*and)[i++] = a->val;
		a = a->next;
	}
	while (a->next != NULL)
		a = a->next;
	while (i < len_back + len)
	{
		(*and)[i++] = a->val;
		a = a->prev;
	}
}

int		find_middle_all(t_arr *a, int len, int len_back)
{
	int		i;
	int		val;
	int		*and;

	val = 0;
	i = 0;
	and = (int *)malloc(sizeof(int) * (len + len_back));
	fill_and(a, &and, len, len_back);
	sort_it(&and, len + len_back);
	val = and[(len + len_back) / 2];
	if ((len + len_back) % 2 == 0)
		val = and[(len + len_back) / 2 - 1];
	free(and);
	and = NULL;
	return (val);
}

int		find_middle(t_arr *a, int len)
{
	int		i;
	int		val;
	int		*and;

	val = 0;
	i = 0;
	and = (int *)malloc(sizeof(int) * len);
	while (i < len && a != NULL)
	{
		and[i++] = a->val;
		a = a->next;
	}
	sort_it(&and, len);
	val = and[len / 2];
	if (len % 2 == 0)
		val = and[len / 2 - 1];
	free(and);
	and = NULL;
	return (val);
}

int		find_middle_back(t_arr *a, int len)
{
	int		i;
	int		val;
	int		*and;

	val = 0;
	i = 0;
	and = (int *)malloc(sizeof(int) * len);
	while (a->next != NULL)
		a = a->next;
	while (i < len && a != NULL)
	{
		and[i++] = a->val;
		a = a->prev;
	}
	sort_it(&and, len);
	val = and[len / 2];
	if (len % 2 == 0)
		val = and[len / 2 - 1];
	free(and);
	and = NULL;
	return (val);
}

int		can_del(int len)
{
	int		ret;

	ret = 0;
	while (len > 1)
	{
		len = len / 2;
		ret++;
	}
	return (ret);
}
