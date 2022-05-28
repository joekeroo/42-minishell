/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmdgrp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:34:36 by jhii              #+#    #+#             */
/*   Updated: 2022/05/28 19:44:52 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	init_array(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < array->n_cmdln)
	{
		array->cmd_group[i].size = 0;
		while (array->token[j])
		{
			if (array->token[j][0] != '|')
				array->cmd_group[i].size++;
			else
				break ;
			j++;
		}
		j++;
		array->cmd_group[i].cmd = malloc(sizeof(char *)
				* array->cmd_group[i].size + 1);
		i++;
	}
}

void	init_cmdgrp(t_array *array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	array->n_cmdln = 0;
	while (array->token[i])
	{
		if (array->token[i][0] == '|')
			array->n_cmdln++;
		i++;
	}
	array->cmd_group = malloc(sizeof(t_group) * ++array->n_cmdln);
	init_array(array);
	i = 0;
	j = 0;
	while (i < array->n_cmdln)
	{
		k = 0;
		if (array->token[j][0] == '|')
			j++;
		while (k < array->cmd_group[i].size)
			array->cmd_group[i].cmd[k++] = ft_strdup(array->token[j++]);
		array->cmd_group[i++].cmd[k] = 0;
	}
}
