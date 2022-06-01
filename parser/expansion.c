/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:46:23 by jhii              #+#    #+#             */
/*   Updated: 2022/06/01 20:03:11 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	is_string(char *s)
{
	if (s[0] == '>' || s[0] == '<')
		return (0);
	else
		return (1);
}

static	void	expand(t_array *array, int curr, int i)
{
	(void)array;
	(void)curr;
	(void)i;
	return ;
}

void	check_expansion(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->n_cmdln)
	{
		j = 0;
		while (j < array->cmd_group[i].size)
		{
			if (is_string(array->cmd_group[i].token[j]))
				expand(array, i, j);
			j++;
		}
		i++;
	}
}
