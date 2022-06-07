/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:34 by jhii              #+#    #+#             */
/*   Updated: 2022/06/07 23:08:11 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	init_minishell(t_array *array)
{
	array->env.size = 0;
	array->env.key = NULL;
	array->env.value = NULL;
}

static	void	free_minishell(t_array *array)
{
	free_array(array->env.key, array->env.size);
	free_array(array->env.value, array->env.size);
}

static	int	exit_minishell(char *input)
{
	if (ft_strcmp(input, "exit"))
	{
		printf("exit\n");
		free(input);
		return (1);
	}
	return (0);
}

void	minishell(char **envp)
{
	t_array	array;

	init_minishell(&array);
	while (1)
	{
		array.line = readline("minishell % ");
		if (!array.line)
			break ;
		if (exit_minishell(array.line) > 0)
			break ;
		add_history(array.line);
		if (array.line[0] != '\0' && lexer(&array) > 0)
		{
			parser(&array);
			builtin(&array, envp);
			free_cmdgrp(&array);
		}
		free_array(array.token, array.size);
		free(array.line);
	}
	free_minishell(&array);
}
