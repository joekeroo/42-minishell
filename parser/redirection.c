/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:39:27 by jhii              #+#    #+#             */
/*   Updated: 2022/05/28 21:13:38 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	count_redirection(t_array *array, int i)
{
	int	j;

	j = 0;
	array->cmd_group[i].redir.size = 0;
	while (array->cmd_group[i].cmd[j])
	{
		if (array->cmd_group[i].cmd[j][0] == '<'
			|| array->cmd_group[i].cmd[j][0] == '>')
			array->cmd_group[i].redir.size++;
		j++;
	}
}

static	int	get_status(t_array *array, int i, int j)
{
	int	status;

	status = 0;
	if (array->cmd_group[i].cmd[j][0] == '<')
	{
		status = INFILE;
		if (array->cmd_group[i].cmd[j][1] == '<')
			status = HEREDOC;
	}
	else if (array->cmd_group[i].cmd[j][0] == '>')
	{
		status = TRUNC;
		if (array->cmd_group[i].cmd[j][1] == '>')
			status = APPEND;
	}
	return (status);
}

static	void	check_infile(t_array *array, int i, int *curr)
{
	int	j;

	j = 0;
	while (array->cmd_group[i].cmd[j])
	{
		if (array->cmd_group[i].cmd[j][0] == '<')
		{
			array->cmd_group[i].redir.types[*curr] = get_status(array, i, j);
			array->cmd_group[i].redir.files[*curr]
				= ft_strdup(array->cmd_group[i].cmd[j + 1]);
			*curr = *curr + 1;
			if (array->cmd_group[i].redir.infile)
				free(array->cmd_group[i].redir.infile);
			array->cmd_group[i].redir.infile
				= ft_strdup(array->cmd_group[i].cmd[j + 1]);
		}
		j++;
	}
}

static	void	check_outfile(t_array *array, int i, int *curr)
{
	int	j;

	j = 0;
	while (array->cmd_group[i].cmd[j])
	{
		if (array->cmd_group[i].cmd[j][0] == '>')
		{
			array->cmd_group[i].redir.types[*curr] = get_status(array, i, j);
			array->cmd_group[i].redir.files[*curr]
				= ft_strdup(array->cmd_group[i].cmd[j + 1]);
			*curr = *curr + 1;
			if (array->cmd_group[i].redir.outfile)
				free(array->cmd_group[i].redir.outfile);
			array->cmd_group[i].redir.outfile
				= ft_strdup(array->cmd_group[i].cmd[j + 1]);
		}
		j++;
	}
}

void	check_files(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->n_cmdln)
	{
		j = 0;
		array->cmd_group[i].redir.infile = NULL;
		array->cmd_group[i].redir.outfile = NULL;
		count_redirection(array, i);
		array->cmd_group[i].redir.types = malloc(sizeof(int)
				* array->cmd_group[i].redir.size);
		array->cmd_group[i].redir.files = malloc(sizeof(char *)
				* array->cmd_group[i].redir.size + 1);
		check_infile(array, i, &j);
		check_outfile(array, i, &j);
		array->cmd_group[i].redir.files[j] = 0;
		i++;
	}
}
