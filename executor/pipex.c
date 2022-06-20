/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:50 by jhii              #+#    #+#             */
/*   Updated: 2022/06/20 13:51:19 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	startprocess(t_array *array, int i, int *fd)
{
	dup2(fd[1], 1);
	close(fd[1]);
	close(fd[0]);
	builtin(array, i);
	exit(array->exitstat);
}

static	void	midprocess(t_array *array, int i, int lastfd, int *fd)
{
	dup2(lastfd, 0);
	close(lastfd);
	dup2(fd[1], 1);
	close(fd[1]);
	builtin(array, i);
	exit(array->exitstat);
}

static	void	endprocess(t_array *array, int i, int lastfd)
{
	dup2(lastfd, 0);
	close(lastfd);
	builtin(array, i);
	exit(array->exitstat);
}

static	void	run_pipex(t_array *array, int *fd)
{
	int		i;
	int		lastfd;

	i = 0;
	lastfd = 0;
	while (i < array->n_cmdln)
	{
		if (i != array->n_cmdln - 1)
			pipe(fd);
		array->process[i] = fork();
		if (array->process[i] < 0)
			return (perror("Fork Error"));
		if (array->process[i] == 0)
		{
			if (i == 0)
				startprocess(array, i, fd);
			else if (i == array->n_cmdln - 1)
				endprocess(array, i, lastfd);
			else
				midprocess(array, i, lastfd, fd);
		}
		closefds(&lastfd, fd, i++, array->n_cmdln);
	}
	mulwaitpid(array);
}

void	pipex(t_array *array)
{
	int		fd[2];

	if (exit_minishell(array, 0))
		return ;
	save_heredoc(array);
	if (array->n_cmdln > 1)
	{
		array->process = malloc(sizeof(int) * array->n_cmdln);
		run_pipex(array, fd);
		free(array->process);
	}
	else
		builtin(array, 0);
}
