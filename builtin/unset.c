/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:52:54 by jhii              #+#    #+#             */
/*   Updated: 2022/06/25 18:59:27 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	find_env(t_array *array, char *str)
{
	int	i;

	i = 0;
	while (i < array->env.size)
	{
		if (ft_strcmp(array->env.key[i], str))
			return (1);
		i++;
	}
	return (0);
}

static	void	check_exitstat(int check)
{
	if (check == 1)
		g_exitstat = 1;
	else
		g_exitstat = 0;
}

static	int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (ft_isalnum(str[i]) || str[i] == '_')
			i++;
		else
			return (0);
	}
	return (1);
}

static	void	error_check(t_array *array, int prc)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < array->cmd_group[prc].n_arg)
	{
		if (check_syntax(array->cmd_group[prc].args[i]))
		{
			if (find_env(array, array->cmd_group[prc].args[i]))
				remove_key_value(array, array->cmd_group[prc].args[i]);
		}
		else
		{
			check = 1;
			print_unset_err(array->cmd_group[prc].args[i]);
		}
		i++;
	}
	check_exitstat(check);
}

void	unset_env(t_array *array, int prc)
{
	if (array->cmd_group[prc].cmd)
	{
		if (ft_strcmp(array->cmd_group[prc].cmd, "unset"))
		{
			error_check(array, prc);
			array->cmd_group[prc].executed = 1;
		}
	}
}
