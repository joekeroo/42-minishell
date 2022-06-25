/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:46:23 by jhii              #+#    #+#             */
/*   Updated: 2022/06/25 21:13:18 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	check_heredoc(t_array *array, int prc, int i)
{
	if (i == 0)
		return (0);
	if (array->cmd_group[prc].token[i - 1][0] == '<'
		&& array->cmd_group[prc].token[i - 1][1] == '<')
		return (1);
	return (0);
}

static	int	get_heredoc_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (i < ft_strlen(str))
	{
		if (str[i] == '\"')
		{
			i = i + skipquotes(str, i, '\"');
			size = size - 2;
		}
		else if (str[i] == '\'')
		{
			i = i + skipquotes(str, i, '\'');
			size = size - 2;
		}
		else
			i++;
	}
	return (size);
}

static	void	replace_heredoc(t_array *array, char *str)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = get_heredoc_size(str);
	array->temp = malloc(sizeof(char) * size + 1);
	while (i < ft_strlen(str))
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				array->temp[j++] = str[i++];
			i++;
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				array->temp[j++] = str[i++];
			i++;
		}
		else
			array->temp[j++] = str[i++];
	}
	array->temp[j] = '\0';
}

static	void	expand_heredoc(t_array *array, int prc, int i)
{
	replace_heredoc(array, array->cmd_group[prc].token[i]);
	free(array->cmd_group[prc].token[i]);
	array->cmd_group[prc].token[i] = ft_strdup(array->temp);
	free(array->temp);
}

void	check_expansion(t_array *array)
{
	int		i;
	int		j;

	i = 0;
	while (i < array->n_cmdln)
	{
		j = 0;
		while (j < array->cmd_group[i].size)
		{
			if (check_heredoc(array, i, j))
				expand_heredoc(array, i, j);
			else if (array->cmd_group[i].token[j][0] != '>'
				&& array->cmd_group[i].token[j][0] != '<')
			{
				expand(array, i, j);
				free(array->cmd_group[i].token[j]);
				array->cmd_group[i].token[j] = ft_strdup(array->temp);
				free(array->temp);
			}
			j++;
		}
		i++;
	}
}
