/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:52:54 by jhii              #+#    #+#             */
/*   Updated: 2022/06/17 16:23:31 by jhii             ###   ########.fr       */
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

static	void	check_exitstat(t_array *array, int check)
{
	if (check == 1)
		array->exitstat = 1;
	else
		array->exitstat = 0;
}

static	void	error_check(t_array *array, int prc)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < array->cmd_group[prc].n_arg)
	{
		if (ft_isdigit(array->cmd_group[prc].args[i][0]) == 0)
		{
			if (find_env(array, array->cmd_group[prc].args[i]))
				remove_key_value(array, array->cmd_group[prc].args[i]);
		}
		else
		{
			check = 1;
			printf("minishell: unset: `%s': not a valid identifier\n",
				array->cmd_group[prc].args[i]);
		}
		i++;
	}
	check_exitstat(array, check);
}

int	unset_env(t_array *array, int prc)
{
	if (array->cmd_group[prc].cmd)
	{
		if (ft_strcmp(array->cmd_group[prc].cmd, "unset"))
			error_check(array, prc);
		return (1);
	}
	return (0);
}
