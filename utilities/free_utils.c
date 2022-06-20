/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:07:24 by jhii              #+#    #+#             */
/*   Updated: 2022/06/20 15:09:07 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_array(char **array, int size)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < size)
		free(array[i++]);
	free(array);
}

static	void	free_extra_cmdgrp(t_array *array, int i)
{
	if (array->cmd_group[i].heredoc[0] != '\0')
		free(array->cmd_group[i].heredoc);
	if (array->cmd_group[i].type)
		free(array->cmd_group[i].type);
	if (array->cmd_group[i].redir.infile)
		free(array->cmd_group[i].redir.infile);
	if (array->cmd_group[i].redir.outfile)
		free(array->cmd_group[i].redir.outfile);
	if (array->cmd_group[i].redir.types)
		free(array->cmd_group[i].redir.types);
	if (array->cmd_group[i].redir.files)
		free_array(array->cmd_group[i].redir.files,
			array->cmd_group[i].redir.size);
	if (array->cmd_group[i].cmd)
		free(array->cmd_group[i].cmd);
}

void	free_cmdgrp(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->n_cmdln)
	{
		free_extra_cmdgrp(array, i);
		free_array(array->cmd_group[i].args, array->cmd_group[i].n_arg);
		free_array(array->cmd_group[i].token, array->cmd_group[i].size);
		i++;
	}
	free(array->cmd_group);
}
