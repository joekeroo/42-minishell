/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:14:54 by jhii              #+#    #+#             */
/*   Updated: 2022/06/08 15:28:20 by jhii             ###   ########.fr       */
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

void	remove_key_value(t_array *array, char *key)
{
	int		i;
	int		j;
	char	**temp_key;
	char	**temp_value;

	i = 0;
	j = 0;
	temp_key = duplicate_array(array->env.key, array->env.size);
	temp_value = duplicate_array(array->env.value, array->env.size);
	free_array(array->env.key, array->env.size);
	free_array(array->env.value, array->env.size--);
	array->env.key = malloc(sizeof(char *) * array->env.size);
	array->env.value = malloc(sizeof(char *) * array->env.size);
	while (i < array->env.size + 1)
	{
		if (ft_strcmp(temp_key[i], key))
			i++;
		array->env.key[j] = ft_strdup(temp_key[i]);
		array->env.value[j++] = ft_strdup(temp_value[i++]);
	}
	free_array(temp_key, array->env.size + 1);
	free_array(temp_value, array->env.size + 1);
}
