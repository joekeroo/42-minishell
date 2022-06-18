/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:50 by jhii              #+#    #+#             */
/*   Updated: 2022/06/18 17:13:35 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	mulwaitpid(t_array *array)
{
	int	i;
	int	status;

	i = 0;
	while (i < array->n_cmdln)
		waitpid(array->process[i++], &status, 0);
}

static	void	midprocess(t_array *array, int prc, int lastfd, int *fd)
{
	dup2(lastfd, array->cmd_group[prc].files.curr_stdin);
	close(lastfd);
	dup2(fd[1], array->cmd_group[prc].files.curr_stdout);
	close(fd[1]);
	builtin(array, prc);
	exit(array->exitstat);
}

static	void	closefds(int *lastfd, int *fd)
{
	close(*lastfd);
	close(fd[1]);
	*lastfd = fd[0];
}

void	pipex(t_array *array)
{
	int		i;
	int		lastfd;
	int		fd[2];

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
			midprocess(array, i, lastfd, fd);
		closefds(&lastfd, fd);
		i++;
	}
	mulwaitpid(array);
}
