/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:09:26 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 13:09:45 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*create_filename(t_array *array, int prc)
{
	char	*tmp;
	char	*res;

	array->cmd_group[prc].files.in_status = 1;
	array->cmd_group[prc].files.curr_stdin = dup(0);
	tmp = malloc(sizeof(char) * 2);
	tmp[0] = '0' + array->filenumber++;
	tmp[1] = '\0';
	res = ft_strjoin("tmp", tmp);
	free(tmp);
	return (res);
}

static	void	in_file(t_array *array, char *filename, int prc, int i)
{
	int		tmp;
	int		type;
	char	*temp;

	if (ft_strcmp(filename, array->cmd_group[prc].redir.infile))
	{
		type = array->cmd_group[prc].redir.types[i];
		if (type == INFILE || type == HEREDOC)
		{
			temp = create_filename(array, prc);
			if (type == HEREDOC)
			{
				array->cmd_group[prc].files.heredoc_status = 1;
				tmp = open(temp, O_CREAT | O_RDWR | O_TRUNC, 0644);
				ft_putstr_fd(array->cmd_group[prc].heredoc, tmp);
				close(tmp);
				array->cmd_group[prc].files.infile = open(temp, O_RDONLY);
				unlink(temp);
			}
			else if (type == INFILE)
				array->cmd_group[prc].files.infile = open(filename, O_RDONLY);
			free(temp);
		}
	}
}

static	void	out_file(t_array *array, char *filename, int prc, int i)
{
	int	type;

	if (ft_strcmp(filename, array->cmd_group[prc].redir.outfile))
	{
		type = array->cmd_group[prc].redir.types[i];
		if (type == TRUNC || type == APPEND)
		{
			array->cmd_group[prc].files.out_status = 1;
			array->cmd_group[prc].files.curr_stdout = dup(1);
			if (type == TRUNC)
				array->cmd_group[prc].files.outfile
					= open(filename, O_WRONLY | O_TRUNC, 0644);
			else if (type == APPEND)
				array->cmd_group[prc].files.outfile
					= open(filename, O_WRONLY | O_APPEND, 0644);
		}
	}
}

static	void	mid_file(t_array *array, char *filename, int prc, int i)
{
	int	temp;
	int	type;

	if (array->cmd_group[prc].redir.infile)
	{
		if (ft_strcmp(filename, array->cmd_group[prc].redir.infile))
			return ;
	}
	if (array->cmd_group[prc].redir.outfile)
	{
		if (ft_strcmp(filename, array->cmd_group[prc].redir.outfile))
			return ;
	}
	type = array->cmd_group[prc].redir.types[i];
	if (type == TRUNC)
	{
		unlink(filename);
		temp = open(filename, O_CREAT, 0644);
		close(temp);
	}
}

int	redir_file(t_array *array, int prc)
{
	int		i;
	char	*filename;

	if (array->cmd_group[prc].redir.size > 0)
	{
		i = 0;
		if (checkfiles(array, prc) < 0)
			return (-1);
		while (i < array->cmd_group[prc].redir.size)
		{
			filename = ft_strdup(array->cmd_group[prc].redir.files[i]);
			if (array->cmd_group[prc].redir.infile)
				in_file(array, filename, prc, i);
			if (array->cmd_group[prc].redir.outfile)
				out_file(array, filename, prc, i);
			mid_file(array, filename, prc, i);
			free(filename);
			i++;
		}
		return (1);
	}
	return (0);
}
