/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 18:57:33 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/09 12:46:25 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	create_arr(t_arr **head, int argc, char **argv)
{
	int			i;
	t_arr		*temp;

	i = 1;
	if (argv[1][0] == '-' && !ft_isdigit(argv[1][1]))
		i++;
	(*head) = (t_arr *)malloc(sizeof(t_arr));
	num_check(ft_atoi(argv[i]));
	(*head)->val = ft_atoi(argv[i++]);
	temp = (t_arr *)malloc(sizeof(t_arr));
	num_check(ft_atoi(argv[i]));
	temp->val = ft_atoi(argv[i++]);
	(*head)->next = temp;
	(*head)->prev = NULL;
	temp->prev = (*head);
	while (i < argc)
	{
		temp->next = (t_arr *)malloc(sizeof(t_arr));
		num_check(ft_atoi(argv[i]));
		temp->next->val = ft_atoi(argv[i++]);
		temp->next->prev = temp;
		temp = temp->next;
	}
	temp->next = NULL;
}

void	next_num(char **argv, int j, int *i)
{
	while (ft_isdigit(argv[j][*i]) || argv[j][*i] == '-')
		(*i)++;
	(*i)++;
}

void	help_arr(t_arr **temp, char **argv, int i, int j)
{
	if (!argv[j][i - 1])
		return ;
	while (argv[j][i])
	{
		(*temp)->next = (t_arr *)malloc(sizeof(t_arr));
		num_check(ft_atoi(argv[j] + i));
		(*temp)->next->val = ft_atoi(argv[j] + i);
		next_num(argv, j, &i);
		(*temp)->next->prev = (*temp);
		(*temp) = (*temp)->next;
		if (!argv[j][i - 1])
			break ;
	}
	(*temp)->next = NULL;
}

void	create_arr_2(t_arr **head, char **argv)
{
	int			i;
	t_arr		*temp;
	int			j;

	i = 0;
	j = 1;
	(*head) = (t_arr *)malloc(sizeof(t_arr));
	if (argv[1][0] == '-' && ft_isdigit(argv[1][1]) == 0)
		j++;
	num_check(ft_atoi(argv[j]));
	(*head)->val = ft_atoi(argv[j]);
	next_num(argv, j, &i);
	(*head)->prev = NULL;
	(*head)->next = NULL;
	if (!argv[j][i - 1])
		return ;
	temp = (t_arr *)malloc(sizeof(t_arr));
	num_check(ft_atoi(argv[j] + i));
	temp->val = ft_atoi(argv[j] + i);
	next_num(argv, j, &i);
	(*head)->next = temp;
	temp->prev = (*head);
	temp->next = NULL;
	help_arr(&temp, argv, i, j);
}
