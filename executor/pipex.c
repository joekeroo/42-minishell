/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:36:50 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 14:48:45 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	extra_waitpid(t_array *array, int prc)
{
	int	status;

	redir_file(array, prc);
	if (array->cmd_group[prc].files.heredoc_status == 1)
		waitpid(array->process[prc], &status, 0);
	else
		waitpid(array->process[prc], &status, 1);
	g_exitstat = WEXITSTATUS(status);
}

void	closefds(t_array *array, int *lastfd, int i, int size)
{
	if (i == 0)
	{
		close(array->fd[1]);
		*lastfd = array->fd[0];
	}
	else if (i == size - 1)
	{
		close(array->fd[0]);
		close(*lastfd);
	}
	else
	{
		close(array->fd[1]);
		close(*lastfd);
		*lastfd = array->fd[0];
	}
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
		if (redir_file(array, 0) < 0)
			return ;
		change_in_out_fd(array, 0, 3);
		builtin(array, 0);
		check_dup(array, 0);
	}
}
