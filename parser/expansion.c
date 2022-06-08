/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:46:23 by jhii              #+#    #+#             */
/*   Updated: 2022/06/08 11:50:21 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_expansion(t_array *array)
{
	int		i;
	int		j;

	i = 0;
	while (i < array->n_cmdln)
	{
		j = 0;
		while (j < array->cmd_group[i].size)
		{
			if (array->cmd_group[i].token[j][0] != '>'
				&& array->cmd_group[i].token[j][0] != '<')
			{
				expand(array, i, j);
				free(array->cmd_group[i].token[j]);
				array->cmd_group[i].token[j] = ft_strdup(array->temp);
				free(array->temp);
			}
			j++;
		}
		i++;
	}
}
