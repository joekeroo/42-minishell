/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:34:27 by jhii              #+#    #+#             */
/*   Updated: 2022/06/02 16:53:23 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	skipquotes(char *str, int i, char c)
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

static	int	envlen(char *str, int i)
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

static	int	expandsize(char *str, int i, int *size)
{
	int		j;
	int		len;
	char	*env;
	char	*res;

	j = 0;
	len = envlen(str, i++);
	env = malloc(sizeof(char) * len + 1);
	while (j < len)
		env[j++] = str[i++];
	env[j] = '\0';
	res = getenv(env);
	if (res)
		*size = *size - ((len + 1) - ft_strlen(res));
	free(env);
	return (i);
}

int	outsidequotes(char *str)
{
	int	i;
	int	temp;
	int	size;

	i = 0;
	temp = ft_strlen(str);
	size = ft_strlen(str);
	while (i < temp)
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '$')
		{
			if (str[i] == '\'')
				i = i + skipquotes(str, i, '\'');
			if (str[i] == '\"')
				i = i + skipquotes(str, i, '\"');
			if (str[i] == '$')
			{
				if (str[i + 1] == '_' || ft_isalnum(str[i + 1]))
					i = expandsize(str, i, &size);
			}
		}
		else
			i++;
	}
	return (size);
}
