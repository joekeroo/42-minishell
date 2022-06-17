/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:32:35 by jhii              #+#    #+#             */
/*   Updated: 2022/06/17 14:41:13 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	checkfd1(char *filename)
{
	int	fd;

	fd = -1;
	if (access(filename, F_OK) < 0)
		printf("minishell: %s: no such file or directory\n", filename);
	else if (access(filename, R_OK) < 0)
		printf("minishell: %s: permission denied\n", filename);
	else
		fd = 1;
	return (fd);
}

// type[1] = infile, type[2] = outfile
static	int	checkfd(char *filename, int type)
{
	int	fd;

	fd = -1;
	if (type == 1)
		fd = checkfd1(filename);
	else
	{
		if (access(filename, F_OK) < 0)
		{
			fd = open(filename, O_CREAT, 0644);
			close(fd);
			fd = 1;
		}
		else if (access(filename, W_OK) < 0)
			printf("minishell: %s: permission denied\n", filename);
		else
			fd = 1;
	}
	return (fd);
}

int	checkfiles(t_array *array, int prc)
{
	int	i;

	i = 0;
	while (i < array->cmd_group[prc].redir.size)
	{
		if (array->cmd_group[prc].redir.types[i] == INFILE)
		{
			if (checkfd(array->cmd_group[prc].redir.files[i], 1) < 0)
				return (-1);
		}
		else if (array->cmd_group[prc].redir.types[i] == TRUNC
			|| array->cmd_group[prc].redir.types[i] == APPEND)
		{
			if (checkfd(array->cmd_group[prc].redir.files[i], 2) < 0)
				return (-1);
		}
		i++;
	}
	return (1);
}
