/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:55:10 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/22 13:45:21 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	find_turn(char **str, int turn)
{
	*str = NULL;
	(turn == 1) ? *str = ft_strdup("sa") : 0;
	(turn == 2) ? *str = ft_strdup("sb") : 0;
	(turn == 3) ? *str = ft_strdup("ss") : 0;
	(turn == 11) ? *str = ft_strdup("pa") : 0;
	(turn == 12) ? *str = ft_strdup("pb") : 0;
	(turn == 21) ? *str = ft_strdup("ra") : 0;
	(turn == 22) ? *str = ft_strdup("rb") : 0;
	(turn == 23) ? *str = ft_strdup("rr") : 0;
	(turn == 31) ? *str = ft_strdup("rra") : 0;
	(turn == 32) ? *str = ft_strdup("rrb") : 0;
	(turn == 33) ? *str = ft_strdup("rrr") : 0;
}

void	free_a(t_arr **a)
{
	t_arr	*temp;

	while ((*a) != NULL)
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
}

void	print_val(t_arr **a, t_flags flags, int flag)
{
	char	*temp;

	if (*a != NULL)
	{
		temp = ft_itoa((*a)->val);
		if (flags.colour == 1 && flag == 0)
			ft_printf(" {green}%11s{eoc}", temp);
		else if (flags.colour == 1 && flag == 1)
			ft_printf("{red}%s{eoc}", temp);
		else
			ft_printf(" %11s", temp);
		(*a) = (*a)->next;
		if (flag == 0)
			ft_printf("   |   ");
		free(temp);
	}
}

void	print_arrays(t_arr *a, t_arr *b, int turn, t_flags flags)
{
	char	*str;

	find_turn(&str, turn);
	if (flags.colour == 1)
	{
		ft_printf("\n{bold}{magenta}[%s]{eoc}\n", str);
		ft_printf("       {green}a{eoc}       |        {red}b{eoc}");
		ft_printf("\n--------------------------------\n");
	}
	else
	{
		ft_printf("\n%s\n", str);
		ft_printf("       a       |        b");
		ft_printf("\n--------------------------------\n");
	}
	while (a != NULL || b != NULL)
	{
		if (a == NULL)
			ft_printf("               |   ");
		print_val(&a, flags, 0);
		print_val(&b, flags, 1);
		if (a != NULL || b != NULL)
			ft_printf("\n\n");
	}
	free(str);
}
