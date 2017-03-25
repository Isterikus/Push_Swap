/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:00:48 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/09 12:42:28 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rf(t_flags *flags, char **argv, int *j)
{
	int		i;

	i = 1;
	(*j) = 1;
	while (argv[1][i] == 'c' || argv[1][i] == 'v'
			|| argv[1][i] == 'n' || argv[1][i] == 'f')
	{
		if (argv[1][i] == 'c')
			(*flags).colour = 1;
		else if (argv[1][i] == 'v')
			(*flags).vers = 1;
		else if (argv[1][i] == 'n')
			(*flags).num = 1;
		i++;
	}
	(*j)++;
}

void	fill_flags(int argc, t_flags *flags)
{
	if (argc == 1)
		exit(0);
	(*flags).colour = 0;
	(*flags).vers = 0;
	(*flags).num = 0;
	(*flags).file = NULL;
}
