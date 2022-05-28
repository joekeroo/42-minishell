/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:08:12 by jhii              #+#    #+#             */
/*   Updated: 2022/05/28 17:32:46 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	is_redir(t_array *array, int i)
{
	int	j;

	j = 0;
	while (array->cmd_group[i].cmd[j])
	{
		if (array->cmd_group[i].cmd[j][0] == '<')
		{
			if (array->cmd_group[i].cmd[j][1] == '<')
			array->cmd_group[i].outredir = INFILE;
			if (array->cmd_group[i].infile)
				free(array->cmd_group[i].infile);
			array->cmd_group[i].infile
				= ft_strdup(array->cmd_group[i].cmd[j + 1]);
		}
		if (array->cmd_group[i].cmd[j][0] == '>')
		{
			array->cmd_group[i].outredir = TRUNC;
			if (array->cmd_group[i].cmd[j][1] == '>')
				array->cmd_group[i].outredir = APPEND;
			if (array->cmd_group[i].outfile)
				free(array->cmd_group[i].outfile);
			array->cmd_group[i].outfile
				= ft_strdup(array->cmd_group[i].cmd[j + 1]);
		}
		j++;
	}
}

static	void	check_files(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->n_cmdln)
	{
		j = 0;
		array->cmd_group[i].infile = NULL;
		array->cmd_group[i].outfile = NULL;
		is_redir(array, i);
		i++;
	}
}

void	parser(t_array *array)
{
	init_cmdgrp(array);
	check_files(array);
	print_cmdln(array);
}
