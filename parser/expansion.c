/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:46:23 by jhii              #+#    #+#             */
/*   Updated: 2022/06/02 16:51:07 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	countexpansion(char *str)
{
	int	size;

	size = outsidequotes(str);
	return (size);
}

static	void	expand(t_array *array, int curr, int i)
{
	int		j;
	int		k;
	int		size;
	// char	*temp;

	j = 0;
	k = 0;
	printf("before size: %d\n", ft_strlen(array->cmd_group[curr].token[i]));
	size = countexpansion(array->cmd_group[curr].token[i]);
	printf("after size: %d\n", size);
	// temp = malloc(sizeof(char) * size + 1);
	// while (array->cmd_group[curr].token[i][j])
	// {
	// 	j++;
	// }
	// temp[k] = '\0';
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
			if (array->cmd_group[i].token[j][0] != '>'
				&& array->cmd_group[i].token[j][0] != '<')
				expand(array, i, j);
			j++;
		}
		i++;
	}
}
