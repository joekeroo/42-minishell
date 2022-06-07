/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:25:52 by jhii              #+#    #+#             */
/*   Updated: 2022/06/07 21:19:23 by jhii             ###   ########.fr       */
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
