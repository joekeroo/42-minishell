/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:45:01 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 13:16:18 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	squotes(t_array *array, char *str, int *i, int *j)
{
	if (str[*i] == '\'')
	{
		*i = *i + 1;
		while (str[*i] != '\'')
			replace_char(array, str, i, j);
		*i = *i + 1;
	}
}

static	void	my_env(t_array *array, char *env, int *j)
{
	int		i;
	int		k;
	char	*temp;

	k = 0;
	while (k < array->env.size)
	{
		i = 0;
		temp = NULL;
		if (ft_strcmp(array->env.key[k], env))
			temp = ft_strdup(array->env.value[k]);
		else if (env[0] == '?')
			temp = ft_itoa(g_exitstat);
		if (temp)
		{
			while (temp[i])
			{
				array->temp[*j] = temp[i++];
				*j = *j + 1;
			}
			free(temp);
			break ;
		}
		k++;
	}
}

static	void	dollar(t_array *array, char *str, int *i, int *j)
{
	char	*env;

	if (str[*i] == '$')
	{
		if (check_signs(str[*i + 1], 2) || str[*i + 1] == '?')
		{
			env = extract_env(str, i);
			my_env(array, env, j);
			free(env);
		}
		else
			replace_char(array, str, i, j);
	}
}

static	void	dquotes(t_array *array, char *str, int *i, int *j)
{
	int	len;

	if (str[*i] == '\"')
	{
		len = *i + skipquotes(str, *i, '\"');
		*i = *i + 1;
		while (*j < len)
		{
			dollar(array, str, i, j);
			if (str[*i] != '\"')
			{
				array->temp[*j] = str[*i];
				*i = *i + 1;
				*j = *j + 1;
			}
			else if (str[*i] == '\"')
				break ;
		}
		*i = *i + 1;
	}
}

void	expand(t_array *array, int curr, int i)
{
	int		j;
	int		k;
	int		size;

	j = 0;
	k = 0;
	size = ft_strlen(array->cmd_group[curr].token[i]);
	count_expansion(array, array->cmd_group[curr].token[i], &size);
	array->temp = malloc(sizeof(char) * size + 1);
	while (j < ft_strlen(array->cmd_group[curr].token[i]))
	{
		if (check_signs(array->cmd_group[curr].token[i][j], 1))
		{
			squotes(array, array->cmd_group[curr].token[i], &j, &k);
			dquotes(array, array->cmd_group[curr].token[i], &j, &k);
			dollar(array, array->cmd_group[curr].token[i], &j, &k);
		}
		else
			replace_char(array, array->cmd_group[curr].token[i], &j, &k);
	}
	array->temp[k] = '\0';
}
