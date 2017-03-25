/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 13:13:03 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/12 13:06:06 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_sol(int **ret, char **str)
{
	int		i;
	int		j;
	int		er;

	i = 0;
	j = 0;
	*ret = (int *)malloc(sizeof(int) * (ret_len((*str)) + 1));
	while (j < ret_len((*str)))
	{
		er = 0;
		er += get_s((*str), &i, ret, &j);
		er += get_p((*str), &i, ret, &j);
		er += get_r((*str), &i, ret, &j);
		if (!(*str)[i])
			break ;
		if (er == 0)
			error();
		i += er;
	}
	(*ret)[j] = 0;
	free(*str);
}

void	read_solution(int **ret, t_flags flags)
{
	char	*str;
	int		i;
	int		rd;
	int		fd;

	if (flags.file != NULL)
		fd = open(flags.file, O_RDONLY);
	else
		fd = 0;
	str = (char *)malloc(sizeof(char) * 1000000);
	i = 0;
	while ((rd = read(fd, str + i, 1)) > 0)
		i++;
	str[i] = '\0';
	return (set_sol(ret, &str));
}

void	output(t_flags flags, t_arr *a, t_arr *b, int i)
{
	if (flags.num == 1)
	{
		if (flags.colour == 1)
			ft_printf("\nNumber of operations: {underlined}{cyan}%d{eoc}", i);
		else
			ft_printf("\nNumber of operations: %d", i);
	}
	(a == NULL) ? ft_printf("\nKO\n") : 0;
	(a == NULL) ? exit(0) : 0;
	while (a->next != NULL)
	{
		if (a->val > a->next->val || b != NULL)
		{
			if (flags.colour == 1)
				ft_printf("\n{red}KO{eoc}\n");
			else
				ft_printf("\nKO\n");
			exit(0);
		}
		a = a->next;
	}
	if (flags.colour == 1)
		ft_printf("\n{green}OK{eoc}\n");
	else
		ft_printf("\nOK\n");
}

void	check_arr(t_arr **a, int *sol, t_flags flags)
{
	int		i;
	t_arr	*b;

	i = 0;
	b = NULL;
	while (sol[i] != 0)
	{
		(sol[i] == 1 || sol[i] == 3) ? swap_two(a) : 0;
		(sol[i] == 2 || sol[i] == 3) ? swap_two(&b) : 0;
		(sol[i] == 11) ? push(a, &b) : 0;
		(sol[i] == 12) ? push(&b, a) : 0;
		(sol[i] == 21 || sol[i] == 23) ? shift_down(a) : 0;
		(sol[i] == 22 || sol[i] == 23) ? shift_down(&b) : 0;
		(sol[i] == 31 || sol[i] == 33) ? shift_up(a) : 0;
		(sol[i] == 32 || sol[i] == 33) ? shift_up(&b) : 0;
		if (flags.vers == 1)
			print_arrays((*a), b, sol[i], flags);
		i++;
	}
	output(flags, *a, b, i);
	free_a(&b);
}

int		main(int argc, char **argv)
{
	int		i;
	t_arr	*a;
	int		*sol;
	t_flags	flags;

	fill_flags(argc, &flags);
	i = 1;
	(argv[1][0] == '-' && !ft_isdigit(argv[1][1])) ? rf(&flags, argv, &i) : 0;
	if (argc < 4)
	{
		check_digit_2(argv[i]);
		create_arr_2(&a, argv);
	}
	else
	{
		while (i < argc)
			check_digit(argv[i++]);
		create_arr(&a, argc, argv);
	}
	check_duplicates(a);
	read_solution(&sol, flags);
	check_arr(&a, sol, flags);
	free_a(&a);
	free(sol);
	return (0);
}
