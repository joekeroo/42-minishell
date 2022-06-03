/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:45:01 by jhii              #+#    #+#             */
/*   Updated: 2022/06/03 16:23:00 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	char	*extract_env(char *str, int *i)
{
	int		j;
	int		len;
	char	*env;

	j = 0;
	len = envlen(str, *i);
	*i = *i + 1;
	env = malloc(sizeof(char) * len + 1);
	while (j < len)
	{
		env[j++] = str[*i];
		*i = *i + 1;
	}
	env[j] = '\0';
	return (env);
}

static	void	squotes(char *str, char *dest, int *i, int *j)
{
	if (str[*i] == '\'')
	{
		*i = *i + 1;
		while (str[*i] != '\'')
			replace_char(str, dest, i, j);
		*i = *i + 1;
	}
}

static	void	dollar(char *str, char *dest, int *i, int *j)
{
	int		k;
	char	*env;
	char	*res;

	if (str[*i] == '$')
	{
		if (check_signs(str[*i + 1], 2))
		{
			k = 0;
			env = extract_env(str, i);
			res = getenv(env);
			if (res)
			{
				while (res[k])
				{
					dest[*j] = res[k++];
					*j = *j + 1;
				}
			}
			free(env);
		}
		else
			replace_char(str, dest, i, j);
	}
}

static	void	dquotes(char *str, char *dest, int *i, int *j)
{
	int	len;

	if (str[*i] == '\"')
	{
		len = *i + skipquotes(str, *i, '\"');
		*i = *i + 1;
		while (*j < len)
		{
			dollar(str, dest, i, j);
			if (str[*i] != '\"')
			{
				dest[*j] = str[*i];
				*i = *i + 1;
				*j = *j + 1;
			}
			else if (str[*i] == '\"')
				break ;
		}
		*i = *i + 1;
	}
}

char	*expand(t_array *array, int curr, int i)
{
	int		j;
	int		k;
	int		size;
	char	*temp;

	j = 0;
	k = 0;
	size = ft_strlen(array->cmd_group[curr].token[i]);
	count_expansion(array->cmd_group[curr].token[i], &size);
	temp = malloc(sizeof(char) * size + 1);
	while (j < ft_strlen(array->cmd_group[curr].token[i]))
	{
		if (check_signs(array->cmd_group[curr].token[i][j], 1))
		{
			squotes(array->cmd_group[curr].token[i], temp, &j, &k);
			dquotes(array->cmd_group[curr].token[i], temp, &j, &k);
			dollar(array->cmd_group[curr].token[i], temp, &j, &k);
		}
		else
			replace_char(array->cmd_group[curr].token[i], temp, &j, &k);
	}
	temp[k] = '\0';
	return (temp);
}
