/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:22:03 by jhii              #+#    #+#             */
/*   Updated: 2022/06/09 15:05:12 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	exit_minishell(t_array *array, int prc)
{
	if (array->cmd_group[prc].cmd)
	{
		if (ft_strcmp(array->cmd_group[prc].cmd, "exit"))
		{
			if (array->cmd_group[prc].n_arg > 1)
			{
				printf("minishell: exit: too many arguments\n");
				return ;
			}
			array->exit = 1;
			printf("exit\n");
			if (array->cmd_group[prc].n_arg == 0)
				array->exitstat = 0;
			else if (is_number(array->cmd_group[prc].args[0]))
				array->exitstat = ft_atoi(array->cmd_group[prc].args[0]) % 256;
			else
			{
				array->exitstat = 255;
				printf("minishell: exit: %s: numeric argument required\n",
					array->cmd_group[prc].args[0]);
			}
		}
	}
}
