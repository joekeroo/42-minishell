/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:02:42 by jhii              #+#    #+#             */
/*   Updated: 2022/06/18 20:03:40 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	run_exec(t_array *array, char **paths, char **args, int size)
{
	int		i;
	int		j;
	char	*new_path;

	i = 0;
	while (paths[i])
	{
		j = 0;
		while (j < size)
		{
			new_path = re_path(paths[i], args[j++]);
			execve(new_path, args, array->en_var);
			free(new_path);
		}
		i++;
	}
	return (i);
}

static	void	executor(t_array *array, int prc)
{
	int		size;
	char	**args;
	char	**paths;

	if (!array->cmd_group[prc].cmd)
		return ;
	paths = get_path(array, prc);
	if (!paths)
		return ;
	args = get_arguments(array, prc);
	size = run_exec(array, paths, args, array->cmd_group[prc].n_arg + 1);
	free_array(paths, size);
	free_array(args, array->cmd_group[prc].n_arg + 1);
	print_cmd_error(array, array->cmd_group[prc].cmd);
}

void	fork_exec(t_array *array, int prc)
{
	int		status;
	int		outfd;
	int		fd[2];
	pid_t	process;

	pipe(fd);
	outfd = dup(1);
	process = fork();
	if (process < 0)
		return (perror("Fork Error"));
	if (process == 0)
	{
		dup2(fd[1], outfd);
		close(fd[1]);
		close(fd[0]);
		executor(array, prc);
		exit(array->exitstat);
	}
	waitpid(process, &status, 0);
	array->exitstat = WEXITSTATUS(status);
	dup2(outfd, 1);
	close(outfd);
	close(fd[0]);
	close(fd[1]);
}
