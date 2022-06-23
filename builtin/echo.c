/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:05:04 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 17:30:36 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (0);
	while (str[i] == 'n')
		i++;
	if (i == 1 || i < ft_strlen(str))
		return (0);
	return (1);
}

static	int	print_msg(t_array *array, int prc, int i)
{
	printf("%s", array->cmd_group[prc].args[i]);
	return (1);
}

static	int	check_echo(char *str)
{
	if (ft_strlen(str) != 4)
		return (0);
	if (str[0] != 'e' && str[0] != 'E')
		return (0);
	if (str[1] != 'c' && str[1] != 'C')
		return (0);
	if (str[2] != 'h' && str[2] != 'H')
		return (0);
	if (str[3] != 'o' && str[3] != 'O')
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
	if (!array->cmd_group[prc].cmd)
		return ;
	if (check_echo(array->cmd_group[prc].cmd))
	{
		g_exitstat = 0;
		while (i < array->cmd_group[prc].n_arg)
		{
			if (check_nl(array->cmd_group[prc].args[i]) && start == 0)
				nl = 0;
			else
				start = print_msg(array, prc, i);
			if (++i < array->cmd_group[prc].n_arg && start == 1)
				printf(" ");
		}
		if (nl == 1)
			printf("\n");
		array->cmd_group[prc].executed = 1;
	}
}
