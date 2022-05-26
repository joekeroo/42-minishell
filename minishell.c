/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:34 by jhii              #+#    #+#             */
/*   Updated: 2022/05/26 17:52:53 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	exit_minishell(char *input)
{
	if (ft_strncmp(input, "exit", 4) == 0)
	{
		printf("exit\n");
		free(input);
		return (1);
	}
	return (0);
}

void	minishell(void)
{
	int		i;
	t_array	array;

	while (1)
	{
		array.line = readline("minishell % ");
		if (exit_minishell(array.line) > 0)
			break ;
		add_history(array.line);
		if (lexer(&array) > 0)
		{
			parser(&array);
			i = 0;
			while (i < array.n_cmdln)
				free_array(array.cmd_group[i++].cmd);
			free(array.cmd_group);
		}
		free_array(array.token);
		free(array.line);
	}
	return ;
}
