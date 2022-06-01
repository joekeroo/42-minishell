/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:09:42 by jhii              #+#    #+#             */
/*   Updated: 2022/06/01 15:22:26 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	is_redir(t_array *array, int curr, int i)
{
	if (array->cmd_group[curr].token[i][0] == '>'
		|| array->cmd_group[curr].token[i][0] == '<')
		return (1);
	return (0);
}

static	int	has_redir(t_array *array, int curr)
{
	int	i;

	i = 0;
	while (array->cmd_group[curr].token[i])
	{
		if (is_redir(array, curr, i))
			return (1);
		i++;
	}
	return (0);
}

static	int	get_cmd(t_array *array, int curr)
{
	int	i;
	int	cmd;

	i = 0;
	cmd = -1;
	if (has_redir(array, curr) == 0)
		return (0);
	while (array->cmd_group[curr].token[i])
	{
		if (is_redir(array, curr, i))
			i++;
		else
		{
			if (i == 0)
				return (0);
			cmd = i;
			break ;
		}
		i++;
	}
	return (cmd);
}

void	check_cmd(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (array->cmd_group[i].token)
	{
		j = get_cmd(array, i);
		array->cmd_group[i].cmd = NULL;
		if (j > -1)
			array->cmd_group[i].cmd = ft_strdup(array->cmd_group[i].token[j]);
		i++;
	}
}
