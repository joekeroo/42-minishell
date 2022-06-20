/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:47:58 by jhii              #+#    #+#             */
/*   Updated: 2022/06/20 20:08:30 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	closefds(t_array *array, int *lastfd, int i, int size)
{
	if (i == 0)
	{
		close(array->fd[1]);
		*lastfd = array->fd[0];
	}
	else if (i == size - 1)
		close(*lastfd);
	else
	{
		close(*lastfd);
		close(array->fd[1]);
		*lastfd = array->fd[0];
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
