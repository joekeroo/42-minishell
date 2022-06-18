/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:22:03 by jhii              #+#    #+#             */
/*   Updated: 2022/06/18 20:26:27 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	is_number(char *str)
{
	int	i;
	int	op;

	i = 0;
	op = 0;
	if (str[i] == '-' || str[i] == '+')
		op = ++i;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (i == 1 && op == 1)
		return (0);
	return (1);
}

static	void	exit_prog(t_array *array, int prc)
{
	if (array->cmd_group[prc].n_arg == 0
		|| (ft_strlen(array->cmd_group[prc].args[0]) == 2
			&& array->cmd_group[prc].args[0][0] == '-'
		&& array->cmd_group[prc].args[0][1] == '-'))
	{
		array->exit = 1;
		printf("exit\n");
	}
	else if (is_number(array->cmd_group[prc].args[0]))
	{
		array->exit = 1;
		printf("exit\n");
		array->exitstat = ft_atoi(array->cmd_group[prc].args[0]) % 256;
	}
	else
	{
		array->exit = 1;
		array->exitstat = 255;
		printf("exit\nminishell: exit: %s: numeric argument required\n",
			array->cmd_group[prc].args[0]);
	}
}

static	int	mul_args(t_array *array, int prc)
{
	if (array->cmd_group[prc].n_arg > 1)
	{
		if (is_number(array->cmd_group[prc].args[0]))
		{
			array->exitstat = 1;
			printf("exit\nminishell: exit: too many arguments\n");
		}
		else
			exit_prog(array, prc);
		return (1);
	}
	return (0);
}

int	exit_minishell(t_array *array, int prc)
{
	if (array->cmd_group[prc].cmd)
	{
		if (ft_strcmp(array->cmd_group[prc].cmd, "exit"))
		{
			if (array->n_cmdln > 1)
				return (1);
			if (mul_args(array, prc))
				return (1);
			else
				exit_prog(array, prc);
			return (1);
		}
	}
	return (0);
}
