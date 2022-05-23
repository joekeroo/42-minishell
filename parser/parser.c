/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:08:12 by jhii              #+#    #+#             */
/*   Updated: 2022/05/23 19:05:40 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	init_parser(t_array *array)
{
	int	i;

	i = 0;
	array->cmdln = 0;
	while (array->token[i])
	{
		if (array->token[i][0] == '|')
			array->cmdln++;
		i++;
	}
	array->cmdln++;
	array->cmd_group = malloc(sizeof(t_group) * array->cmdln);
}

// int	checkspace(t_array *array, int i)
// {
// 	char	*temp;

// 	while (array->line[k])
// 	{
// 		if ()
// 	}
// 	return (0);
// }

void	parser(t_array *array)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	init_parser(array);
	while (i < array->cmdln)
	{
		array->cmd_group[i].cmd = ft_strdup(array->token[j++]);
		// j = get_args(array, i);
		i++;
	}
}
