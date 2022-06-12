/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:25:52 by jhii              #+#    #+#             */
/*   Updated: 2022/06/12 14:38:25 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	char	**duplicate_array(char **array, int size)
{
	int		i;
	char	**temp;

	if (!array)
		return (NULL);
	i = 0;
	temp = malloc(sizeof(char *) * size);
	while (i < size)
	{
		temp[i] = ft_strdup(array[i]);
		i++;
	}
	return (temp);
}

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

void	add_env(t_array *array, char *str)
{
	int		i;
	int		status;
	char	*curr_key;
	char	*curr_value;

	i = 0;
	status = 0;
	curr_key = extr_env(str, 1);
	curr_value = extr_env(str, 2);
	while (i < array->env.size)
	{
		if (ft_strcmp(array->env.key[i], curr_key))
		{
			free(array->env.value[i]);
			array->env.value[i] = ft_strdup(curr_value);
			status = 1;
			break ;
		}
		i++;
	}
	if (status == 0)
		add_key_value(array, curr_key, curr_value);
	free(curr_key);
	free(curr_value);
}

void	add_key_value(t_array *array, char *key, char *value)
{
	int		i;
	char	**temp_key;
	char	**temp_value;

	i = 0;
	temp_key = duplicate_array(array->env.key, array->env.size);
	temp_value = duplicate_array(array->env.value, array->env.size);
	free_array(array->env.key, array->env.size);
	free_array(array->env.value, array->env.size++);
	array->env.key = malloc(sizeof(char *) * array->env.size);
	array->env.value = malloc(sizeof(char *) * array->env.size);
	while (i < array->env.size - 1)
	{
		array->env.key[i] = ft_strdup(temp_key[i]);
		array->env.value[i] = ft_strdup(temp_value[i]);
		i++;
	}
	array->env.key[i] = ft_strdup(key);
	array->env.value[i] = ft_strdup(value);
	free_array(temp_key, array->env.size - 1);
	free_array(temp_value, array->env.size - 1);
}
