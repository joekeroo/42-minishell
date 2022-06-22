/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:47:32 by jhii              #+#    #+#             */
/*   Updated: 2022/06/22 12:48:36 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_file(t_array *array, int prc)
{
	int	tmp;

	tmp = open("heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	ft_putstr_fd(array->cmd_group[prc].heredoc, tmp);
	close(tmp);
}
