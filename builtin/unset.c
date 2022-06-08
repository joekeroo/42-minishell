/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:52:54 by jhii              #+#    #+#             */
/*   Updated: 2022/06/08 15:31:43 by jhii             ###   ########.fr       */
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

void	unset_env(t_array *array)
{
	int	i;

	if (array->n_cmdln > 1)
		return ;
	if (ft_strcmp(array->cmd_group[0].cmd, "unset"))
	{
		i = 0;
		while (i < array->cmd_group[0].n_arg)
		{
			if (find_env(array, array->cmd_group[0].args[i]))
				remove_key_value(array, array->cmd_group[0].args[i]);
			i++;
		}
	}
}
