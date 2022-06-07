/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:48:14 by jhii              #+#    #+#             */
/*   Updated: 2022/06/07 22:36:20 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	envlen(char *str, int i)
{
	int	size;

	i++;
	size = 0;
	while (str[i])
	{
		if (str[i] == '_' || ft_isalnum(str[i]))
			size++;
		else
			break ;
		i++;
	}
	return (size);
}

int	check_signs(char c, int type)
{
	if (type == 1)
	{
		if (c == '\'' || c == '\"' || c == '$')
			return (1);
	}
	else if (type == 2)
	{
		if (c == '_' || ft_isalnum(c))
			return (1);
	}
	return (0);
}

int	skipquotes(char *str, int i, char c)
{
	int	size;

	i++;
	size = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			size++;
			break ;
		}
		size++;
		i++;
	}
	return (size);
}

char	*extract_env(char *str, int *i)
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

void	replace_char(t_array *array, char *str, int *i, int *j)
{
	array->temp[*j] = str[*i];
	*i = *i + 1;
	*j = *j + 1;
}
