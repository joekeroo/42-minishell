/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:47:32 by jhii              #+#    #+#             */
/*   Updated: 2022/06/26 11:44:02 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	heredoc_size(t_array *array, int prc)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (i < array->cmd_group[prc].redir.size)
	{
		if (array->cmd_group[prc].redir.types[i] == HEREDOC)
			size++;
		i++;
	}
	return (size);
}

void	save_file(t_array *array, int prc)
{
	int	tmp;

	tmp = open("heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	ft_putstr_fd(array->cmd_group[prc].heredoc, tmp);
	close(tmp);
}
