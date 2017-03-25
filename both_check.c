/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:56:44 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/20 11:57:32 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		error(void)
{
	ft_printf("{red}Error{eoc}\n");
	exit(0);
}

void	check_digit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && ft_isdigit(str[i]) == 0)
			error();
		i++;
	}
}

void	check_digit_2(char *str)
{
	int		i;

	i = 0;
	if (!str)
		error();
	while (str[i])
	{
		while (str[i] == '-' || ft_isdigit(str[i]) == 1)
			i++;
		if (!str[i])
			break ;
		if (str[i] != ' ')
			error();
		i++;
	}
}

void	check_duplicates(t_arr *a)
{
	t_arr	*temp;

	while (a != NULL)
	{
		temp = a->next;
		while (temp != NULL)
		{
			if (a->val == temp->val)
				error();
			temp = temp->next;
		}
		a = a->next;
	}
}

void	num_check(long int num)
{
	if (num > INT_MAX || num < INT_MIN)
		error();
}
