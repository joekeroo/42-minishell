/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:50 by jhii              #+#    #+#             */
/*   Updated: 2022/06/20 20:41:33 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	startprocess(t_array *array, int i)
{
	if (redir_file(array, i) < 0)
	{
		close(array->fd[1]);
		close(array->fd[0]);
		array->exitstat = 1;
		exit(array->exitstat);
	}
	else
	{
		if (array->cmd_group[i].files.dup_out == 0)
			dup2(array->fd[1], 1);
	}
	close(array->fd[1]);
	close(array->fd[0]);
	builtin(array, i);
	exit(array->exitstat);
}

static	void	midprocess(t_array *array, int i, int lastfd)
{
	if (redir_file(array, i) < 0)
	{
		close(lastfd);
		close(array->fd[1]);
		close(array->fd[0]);
		array->exitstat = 1;
		exit(array->exitstat);
	}
	else
	{
		if (array->cmd_group[i].files.dup_out == 0)
			dup2(array->fd[1], 1);
	}
	if (array->cmd_group[i].files.in_status	== 0)
		dup2(lastfd, 0);
	close(lastfd);
	close(array->fd[0]);
	close(array->fd[1]);
	builtin(array, i);
	exit(array->exitstat);
}

static	void	endprocess(t_array *array, int i, int lastfd)
{
	if (redir_file(array, i) < 0)
	{
		close(lastfd);
		array->exitstat = 1;
		exit(array->exitstat);
	}
	if (array->cmd_group[i].files.in_status	== 0)
		dup2(lastfd, 0);
	close(lastfd);
	builtin(array, i);
	exit(array->exitstat);
}

static	void	run_pipex(t_array *array)
{
	int		i;
	int		lastfd;

	i = 0;
	lastfd = 0;
	while (i < array->n_cmdln)
	{
		if (i != array->n_cmdln - 1)
			pipe(array->fd);
		array->process[i] = fork();
		if (array->process[i] < 0)
			return (perror("Fork Error"));
		if (array->process[i] == 0)
		{
			if (i == 0)
				startprocess(array, i);
			else if (i == array->n_cmdln - 1)
				endprocess(array, i, lastfd);
			else
				midprocess(array, i, lastfd);
		}
		closefds(array, &lastfd, i++, array->n_cmdln);
	}
	mulwaitpid(array);
}

void	pipex(t_array *array)
{
	int	i;

	if (exit_minishell(array, 0))
		return ;
	i = 0;
	while (i < array->n_cmdln)
		save_heredoc(array, i++);
	if (array->n_cmdln > 1)
	{
		array->process = malloc(sizeof(int) * array->n_cmdln);
		run_pipex(array);
		free(array->process);
	}
	else
	{
		if (redir_file(array, 0))
			builtin(array, 0);
	}
}
