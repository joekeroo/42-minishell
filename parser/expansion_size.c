/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:34:27 by jhii              #+#    #+#             */
/*   Updated: 2022/06/08 11:46:00 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// static	void	check_local_env(t_array *array, char *env, int len, int *size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < array->env.size)
// 	{
// 		if (ft_strcmp(array->env.key[i], env))
// 		{
// 			*size = *size - (len + 1) - ft_strlen(env);
// 			break ;
// 		}
// 		i++;
// 	}
// }

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
	// else if (array->env.key)
	// 	check_local_env(array, env, len, size);
	else
		*size = *size - (len + 1);
	free(env);
	return (i);
}

static	int	skipwithsize(char *str, int i, int *sz)
{
	int	size;

	i++;
	*sz = *sz - 2;
	size = 1;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			size++;
			break ;
		}
		size++;
		i++;
	}
	return (size);
}

static	int	insidequotes(char *str, int i, int *size)
{
	int	len;

	len = i + skipquotes(str, i, '\"');
	*size = *size - 2;
	while (i < len)
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '_' || ft_isalnum(str[i + 1]))
				i = expandsize(str, i, size);
			else
				i++;
		}
		else
			i++;
	}
	return (i);
}

void	count_expansion(char *str, int *size)
{
	int	i;
	int	temp;

	i = 0;
	temp = ft_strlen(str);
	while (i < temp)
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '$')
		{
			if (str[i] == '\'')
				i = i + skipwithsize(str, i, size);
			if (str[i] == '\"')
				i = insidequotes(str, i, size);
			if (str[i] == '$')
			{
				if (str[i + 1] == '_' || ft_isalnum(str[i + 1]))
					i = expandsize(str, i, size);
				else
					i++;
			}
		}
		else
			i++;
	}
}
