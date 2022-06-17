/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:50:00 by jhii              #+#    #+#             */
/*   Updated: 2022/06/17 11:51:13 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// type[1 = key, 2 = value]
static	char	*extr_env(char *str, int type)
{
	int		i;
	int		size;
	int		done;
	char	*temp;

	i = 0;
	size = 0;
	done = 0;
	while (str[i])
	{
		if (str[i] == '=')
			done++;
		if (done == 0)
			size++;
		i++;
	}
	if (type == 1)
		temp = ft_substr(str, 0, size);
	else
		temp = ft_substr(str, size + 1, i);
	return (temp);
}

void	init_env(t_array *array, char **envp)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (envp[array->env.size])
		array->env.size++;
	array->env.key = malloc(sizeof(char *) * array->env.size);
	array->env.value = malloc(sizeof(char *) * array->env.size);
	while (i < array->env.size)
	{
		key = extr_env(envp[i], 1);
		value = extr_env(envp[i], 2);
		if (ft_strcmp(key, "PWD"))
			array->pwd = ft_strdup(value);
		array->env.key[i] = ft_strdup(key);
		array->env.value[i++] = ft_strdup(value);
		free(key);
		free(value);
	}
}
