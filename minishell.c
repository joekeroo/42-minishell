/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:34 by jhii              #+#    #+#             */
/*   Updated: 2022/05/27 14:16:19 by jhii             ###   ########.fr       */
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
			free_cmdgrp(&array);
		}
		free_array(array.token);
		free(array.line);
	}
	return ;
}
