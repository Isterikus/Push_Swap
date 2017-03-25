/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_opers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:58:25 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/05 20:14:36 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_two(t_arr **a)
{
	int		temp;

	if (!(*a) || (*a)->next == NULL)
		return ;
	temp = (*a)->val;
	(*a)->val = (*a)->next->val;
	(*a)->next->val = temp;
}

void	shift_down(t_arr **a)
{
	t_arr	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *a;
	(*a)->prev = temp;
	temp = temp->next;
	(*a) = (*a)->next;
	temp->next = NULL;
	(*a)->prev = NULL;
}

void	shift_up(t_arr **a)
{
	t_arr	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	temp->next = (*a);
	(*a)->prev = temp;
	(*a) = (*a)->prev;
	(*a)->prev = NULL;
}

void	push(t_arr **a, t_arr **b)
{
	if (*b == NULL)
		return ;
	if (*a == NULL)
	{
		(*a) = (t_arr *)malloc(sizeof(t_arr));
		(*a)->val = (*b)->val;
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
	else
	{
		(*a)->prev = (t_arr *)malloc(sizeof(t_arr));
		(*a)->prev->val = (*b)->val;
		(*a)->prev->next = *a;
		(*a) = (*a)->prev;
		(*a)->prev = NULL;
	}
	if ((*b)->next == NULL)
	{
		ft_memdel((void **)b);
		return ;
	}
	*b = (*b)->next;
	ft_memdel((void **)&((*b)->prev));
}
