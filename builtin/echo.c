/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:05:04 by jhii              #+#    #+#             */
/*   Updated: 2022/06/12 14:25:11 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] == 'n')
		i++;
	if (i == 1 || i < ft_strlen(str))
		return (0);
	return (1);
}

void	echo(t_array *array, int prc)
{
	int	i;
	int	nl;
	int	start;

	i = 0;
	nl = 1;
	start = 0;
	if (ft_strcmp(array->cmd_group[prc].cmd, "echo"))
	{
		array->exitstat = 0;
		while (i < array->cmd_group[prc].n_arg)
		{
			if (check_nl(array->cmd_group[prc].args[i]) && start == 0)
				nl = 0;
			else
			{
				start = 1;
				printf("%s", array->cmd_group[prc].args[i]);
			}
			if (++i < array->cmd_group[prc].n_arg && start == 1)
				printf(" ");
		}
		if (nl == 1)
			printf("\n");
	}
}
