/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:46:23 by jhii              #+#    #+#             */
/*   Updated: 2022/06/03 16:38:44 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// leaks on line32
void	check_expansion(t_array *array)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < array->n_cmdln)
	{
		j = 0;
		while (j < array->cmd_group[i].size)
		{
			if (array->cmd_group[i].token[j][0] != '>'
				&& array->cmd_group[i].token[j][0] != '<')
			{
				temp = expand(array, i, j);
				array->cmd_group[i].token[j] = ft_strdup(temp);
				free(temp);
			}
			j++;
		}
		i++;
	}
}
