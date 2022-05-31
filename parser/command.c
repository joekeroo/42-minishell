/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:09:42 by jhii              #+#    #+#             */
/*   Updated: 2022/05/31 15:48:17 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	check_redir(t_array *array, int curr)
{
	int	i;
	int	redir;

	i = 0;
	redir = 0;
	while (array->cmd_group[curr].token[i])
	{
		if (array->cmd_group[curr].token[i][0] == '>'
			|| array->cmd_group[curr].token[i][0] == '<')
			redir = 1;
		i++;
	}
	return (redir);
}

static	int	hasnextredir(t_array *array, int curr, int i)
{
	if (array->cmd_group[curr].token[i + 2] == 0)
		return (0);
	else if (array->cmd_group[curr].token[i][0] == '>'
			|| array->cmd_group[curr].token[i][0] == '<')
		return (0);
	else
		return (1);
}

static	void	get_cmd(t_array *array, int curr)
{
	int	i;

	i = 0;
	while (array->cmd_group[curr].token[i])
	{
		if (array->cmd_group[curr].token[i][0] == '>'
			|| array->cmd_group[curr].token[i][0] == '<')
		{
			if (hasnextredir(array, curr, i))
				array->cmd_group[curr].cmd
					= ft_strdup(array->cmd_group[curr].token[i + 2]);
		}
		i++;
	}
}

void	check_cmd(t_array *array)
{
	int	i;

	i = 0;
	while (array->cmd_group[i].token)
	{
		array->cmd_group[i].cmd = NULL;
		if (check_redir(array, i))
			get_cmd(array, i);
		else
			array->cmd_group[i].cmd = ft_strdup(array->cmd_group[i].token[0]);
		i++;
	}
}
