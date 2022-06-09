/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:08:17 by jhii              #+#    #+#             */
/*   Updated: 2022/06/09 15:17:23 by jhii             ###   ########.fr       */
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
		array->env.key[i] = ft_strdup(key);
		array->env.value[i] = ft_strdup(value);
		free(key);
		free(value);
		i++;
	}
}

void	print_env(t_array *array, int prc)
{
	int	j;

	if (ft_strcmp(array->cmd_group[prc].cmd, "env"))
	{
		if (array->cmd_group[prc].n_arg == 0)
		{
			j = 0;
			while (j < array->env.size)
			{
				printf("%s=%s\n", array->env.key[j], array->env.value[j]);
				j++;
			}
		}
		else
			printf("env: %s: No such file or directory\n",
				array->cmd_group[prc].args[0]);
	}
}
