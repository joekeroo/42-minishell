/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:05:17 by jhii              #+#    #+#             */
/*   Updated: 2022/06/26 11:51:01 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	replace_heredoc(t_array *array, int prc, char *temp)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strdup(array->cmd_group[prc].heredoc);
	temp2 = ft_strjoin(temp1, temp);
	if (array->cmd_group[prc].heredoc[0] != '\0')
		free(array->cmd_group[prc].heredoc);
	array->cmd_group[prc].heredoc = ft_strjoin(temp2, "\n");
	free(temp1);
	free(temp2);
}

static	void	here_doc(t_array *array, int prc, char **temp, int size)
{
	char	*temp1;

	while (1)
	{
		temp1 = readline("> ");
		if (ft_strcmp(temp1, temp[array->i]))
			array->i++;
		else if (array->i == size - 1)
			replace_heredoc(array, prc, temp1);
		if (array->i == size)
		{
			free(temp1);
			save_file(array, prc);
			break ;
		}
		free(temp1);
	}
}

static	void	get_heredoc(t_array *array, char **temp, int prc)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < array->cmd_group[prc].redir.size)
	{
		if (array->cmd_group[prc].redir.types[i] == HEREDOC)
			temp[j++] = ft_strdup(array->cmd_group[prc].redir.files[i]);
		i++;
	}
}

static	void	parent_hd(t_array *array, int prc)
{
	int		fd;
	char	*temp1;
	char	*temp2;

	fd = open("heredoc", O_RDONLY);
	while (1)
	{
		temp1 = get_next_line(fd);
		if (!temp1)
			break ;
		temp2 = ft_strdup(array->cmd_group[prc].heredoc);
		if (array->cmd_group[prc].heredoc[0] != '\0')
			free(array->cmd_group[prc].heredoc);
		array->cmd_group[prc].heredoc = ft_strjoin(temp2, temp1);
		free(temp2);
		free(temp1);
	}
	close(fd);
	unlink("heredoc");
}

void	save_heredoc(t_array *array, int prc)
{
	int		size;
	int		status;
	char	**temp;
	pid_t	process;

	array->i = 0;
	size = heredoc_size(array, prc);
	if (size == 0)
		return ;
	process = fork();
	if (process == 0)
	{
		signal(SIGINT, SIG_DFL);
		temp = malloc(sizeof(char *) * size);
		get_heredoc(array, temp, prc);
		here_doc(array, prc, temp, size);
		free_array(temp, size);
		exit(0);
	}
	else
	{
		waitpid(process, &status, 0);
		signal(SIGINT, SIG_IGN);
		parent_hd(array, prc);
	}
}
