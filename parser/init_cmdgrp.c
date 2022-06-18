/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmdgrp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:34:36 by jhii              #+#    #+#             */
/*   Updated: 2022/06/18 14:50:09 by jhii             ###   ########.fr       */
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
		while (j < array->size)
		{
			if (array->token[j][0] != '|')
				array->cmd_group[i].size++;
			else
				break ;
			j++;
		}
		j++;
		array->cmd_group[i].token = malloc(sizeof(char *)
				* array->cmd_group[i].size);
		array->cmd_group[i].type = malloc(sizeof(int)
				* array->cmd_group[i].size);
		array->cmd_group[i].executed = 0;
		i++;
	}
}

static	int	dup_token(t_array *array, int i, int j)
{
	int	k;

	k = 0;
	if (j < array->size && array->token[j][0] == '|')
		j++;
	while (k < array->cmd_group[i].size)
	{
		array->cmd_group[i].type[k] = 0;
		if (array->token[j][0] == '>' || array->token[j][0] == '<')
			array->cmd_group[i].type[k] = 1;
		array->cmd_group[i].token[k++] = ft_strdup(array->token[j++]);
	}
	return (j);
}

void	init_cmdgrp(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	array->n_cmdln = 0;
	while (i < array->size)
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
		array->cmd_group[i].files.in_status = 0;
		array->cmd_group[i].files.out_status = 0;
		array->cmd_group[i].files.curr_stdin = dup(0);
		array->cmd_group[i].files.curr_stdout = dup(1);
		array->cmd_group[i].heredoc = "\0";
		j = dup_token(array, i, j);
		i++;
	}
}
