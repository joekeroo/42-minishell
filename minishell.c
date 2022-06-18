/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:34 by jhii              #+#    #+#             */
/*   Updated: 2022/06/18 21:24:55 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	init_minishell(t_array *array, char **envp)
{
	array->i = 0;
	array->exit = 0;
	array->cd_count = 0;
	array->exitstat = 0;
	array->toggle_info = 0;
	array->env.size = 0;
	array->env.key = NULL;
	array->env.value = NULL;
	array->pwd = NULL;
	array->old_pwd = NULL;
	init_env(array, envp);
}

static	void	free_minishell(t_array *array)
{
	if (array->pwd)
		free(array->pwd);
	if (array->old_pwd)
		free(array->old_pwd);
	if (array->home)
		free(array->home);
	free_array(array->env.key, array->env.size);
	free_array(array->env.value, array->env.size);
}

void	minishell(char **envp)
{
	t_array	array;

	init_minishell(&array, envp);
	while (1)
	{
		array.line = readline("minishell % ");
		if (!array.line)
			break ;
		add_history(array.line);
		if (array.line[0] != '\0' && lexer(&array) > 0)
		{
			parser(&array);
			pipex(&array);
			free_cmdgrp(&array);
			free_array(array.token, array.size);
		}
		free(array.line);
		if (array.exit == 1)
			break ;
	}
	free_minishell(&array);
	system("leaks minishell");
	exit(array.exitstat);
}
