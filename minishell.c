/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:34 by jhii              #+#    #+#             */
/*   Updated: 2022/06/25 14:41:38 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	init_minishell(t_array *array, char **envp)
{
	struct termios	termios_new;

	array->i = 0;
	array->exit = 0;
	array->filenumber = 0;
	array->cd_count = 0;
	array->toggle_info = 0;
	array->env.size = 0;
	array->env.key = NULL;
	array->env.value = NULL;
	array->pwd = NULL;
	array->old_pwd = NULL;
	init_env(array, envp);
	tcgetattr(STDIN_FILENO, &termios_new);
	termios_new.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_new);
	tcsetattr(0, 0, &termios_new);
	signal(SIGQUIT, SIG_IGN);
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

static	int	chckspcs(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (i == ft_strlen(str))
		return (0);
	return (1);
}

static	void	check_child(void)
{
	int	status;

	while (waitpid(-1, &status, 0) > 0)
		;
}

// system("leaks minishell");
void	minishell(char **envp)
{
	t_array	array;

	init_minishell(&array, envp);
	while (1)
	{
		signal(SIGINT, handle_signals);
		array.line = readline("minishell % ");
		if (!array.line)
			break ;
		add_history(array.line);
		if (chckspcs(array.line) && array.line[0] != '\0' && lexer(&array) > 0)
		{
			parser(&array);
			pipex(&array);
			free_cmdgrp(&array);
			free_array(array.token, array.size);
		}
		free(array.line);
		check_child();
		if (array.exit == 1)
			break ;
	}
	free_minishell(&array);
	system("leaks minishell");
	exit(g_exitstat);
}
