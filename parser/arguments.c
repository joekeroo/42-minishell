/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:01:04 by jhii              #+#    #+#             */
/*   Updated: 2022/06/13 14:03:35 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	count_args(int *type, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		if (type[i] == 1 || type[i] == 1)
			i++;
		else
			res++;
		i++;
	}
	if (res > 0)
		res--;
	return (res);
}

static	void	get_args(t_array *array, int i)
{
	int	j;
	int	k;
	int	cmd;

	j = 0;
	k = 0;
	cmd = 0;
	while (j < array->cmd_group[i].size)
	{
		if (array->cmd_group[i].type[j] == 1)
			j++;
		else
		{
			if (cmd > 0)
				array->cmd_group[i].args[k++]
					= ft_strdup(array->cmd_group[i].token[j]);
			cmd++;
		}
		j++;
	}
}

void	check_args(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->n_cmdln)
	{
		array->cmd_group[i].n_arg
			= count_args(array->cmd_group[i].type, array->cmd_group[i].size);
		array->cmd_group[i].args
			= malloc(sizeof(char *) * array->cmd_group[i].n_arg);
		get_args(array, i);
		i++;
	}
}
