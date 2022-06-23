/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:47:58 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 13:17:26 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	startprocess(t_array *array, int i)
{
	int	stat;

	stat = redir_file(array, i);
	if (stat < 0)
	{
		close(array->fd[1]);
		close(array->fd[0]);
	}
	else if (stat == 0)
	{
		dup2(array->fd[1], 1);
		close(array->fd[1]);
		close(array->fd[0]);
		builtin(array, i);
	}
	else
	{
		if (array->cmd_group[i].files.out_status == 0)
			dup2(array->fd[1], 1);
		change_in_out_fd(array, i, 3);
		close(array->fd[1]);
		close(array->fd[0]);
		builtin(array, i);
	}
	exit(g_exitstat);
}

static	void	extra_midprc(t_array *array, int prc, int *lastfd)
{
	if (array->cmd_group[prc].files.heredoc_status)
		change_in_out_fd(array, prc, 1);
	else
		dup2(*lastfd, 0);
	if (array->cmd_group[prc].redir.outfile)
		change_in_out_fd(array, prc, 2);
	else
		dup2(array->fd[1], 1);
	close(*lastfd);
	close(array->fd[1]);
	close(array->fd[0]);
	close(array->cmd_group[prc].files.infile);
	builtin(array, prc);
}

static	void	midprocess(t_array *array, int i, int lastfd)
{
	int	stat;

	stat = redir_file(array, i);
	if (stat < 0)
	{
		close(lastfd);
		close(array->fd[1]);
		close(array->fd[0]);
		exit(g_exitstat);
	}
	else if (stat == 0)
	{
		dup2(lastfd, 0);
		close(lastfd);
		dup2(array->fd[1], 1);
		close(array->fd[1]);
		close(array->fd[0]);
		builtin(array, i);
	}
	else
		extra_midprc(array, i, &lastfd);
	exit(g_exitstat);
}

static	void	endprocess(t_array *array, int i, int lastfd)
{
	int	stat;

	stat = redir_file(array, i);
	if (stat < 0)
		close(lastfd);
	else if (stat == 0)
	{
		dup2(lastfd, 0);
		close(lastfd);
		builtin(array, i);
	}
	else
	{
		if (array->cmd_group[i].files.heredoc_status)
			change_in_out_fd(array, i, 1);
		else
			dup2(lastfd, 0);
		change_in_out_fd(array, i, 2);
		close(lastfd);
		close(array->cmd_group[i].files.infile);
		builtin(array, i);
	}
	exit(g_exitstat);
}

void	run_pipex(t_array *array)
{
	int	i;
	int	lastfd;

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
		closefds(array, &lastfd, i, array->n_cmdln);
		extra_waitpid(array, i++);
	}
}
