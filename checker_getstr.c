/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_getstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:59:39 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/22 13:24:16 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ret_len(char *str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	while (str[i])
		if (str[i++] == '\n')
			ret++;
	return (ret);
}

int		get_s(char *str, int *i, int **ret, int *j)
{
	if (str[*i] == 's')
	{
		(*i)++;
		if (str[*i] == 'a')
			(*ret)[(*j)++] = 1;
		else if (str[*i] == 'b')
			(*ret)[(*j)++] = 2;
		else if (str[*i] == 's')
			(*ret)[(*j)++] = 3;
		else
			return (0);
		(*i)++;
		return (1);
	}
	return (0);
}

int		get_p(char *str, int *i, int **ret, int *j)
{
	if (str[*i] == 'p')
	{
		(*i)++;
		if (str[*i] == 'a')
			(*ret)[(*j)++] = 11;
		else if (str[*i] == 'b')
			(*ret)[(*j)++] = 12;
		else
			return (0);
		(*i)++;
		return (1);
	}
	return (0);
}

int		get_rr(char *str, int *i, int **ret, int *j)
{
	if (str[*i] == '\n' || !str[*i])
	{
		(*ret)[(*j)++] = 23;
		return (1);
	}
	else if (str[*i] == 'a')
		(*ret)[(*j)++] = 31;
	else if (str[*i] == 'b')
		(*ret)[(*j)++] = 32;
	else if (str[*i] == 'r')
		(*ret)[(*j)++] = 33;
	else
		return (0);
	return (2);
}

int		get_r(char *str, int *i, int **ret, int *j)
{
	if (str[*i] == 'r')
	{
		(*i)++;
		if (str[(*i)] == 'a')
			(*ret)[(*j)++] = 21;
		else if (str[*i] == 'b')
			(*ret)[(*j)++] = 22;
		else if (str[*i] == 'r')
		{
			(*i)++;
			return (get_rr(str, i, ret, j));
		}
		else
			return (0);
		return (2);
	}
	return (0);
}
