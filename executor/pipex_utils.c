/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:47:58 by jhii              #+#    #+#             */
/*   Updated: 2022/06/18 20:34:20 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	closefds(int *lastfd, int *fd, int i, int size)
{
	if (i == 0)
	{
		close(fd[1]);
		*lastfd = fd[0];
	}
	else if (i == size - 1)
		close(*lastfd);
	else
	{
		close(*lastfd);
		close(fd[1]);
		*lastfd = fd[0];
	}
}

void	mulwaitpid(t_array *array)
{
	int	i;
	int	status;

	i = 0;
	while (i < array->n_cmdln)
		waitpid(array->process[i++], &status, 0);
	array->exitstat = WEXITSTATUS(status);
}
