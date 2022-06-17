/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:02:42 by jhii              #+#    #+#             */
/*   Updated: 2022/06/17 16:13:30 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	run_exec(t_array *array, int prc)
{
	int		i;
	int		j;
	char	**args;
	char	**paths;
	char	*new_path;

	if (!array->cmd_group[prc].cmd)
		return ;
	paths = get_path(array, prc);
	if (!paths)
		return ;
	i = 0;
	args = get_arguments(array, prc);
	while (paths[i])
	{
		j = 0;
		while (j < array->cmd_group[prc].n_arg + 1)
		{
			new_path = re_path(paths[i], args[j++]);
			execve(new_path, args, array->en_var);
			free(new_path);
		}
		i++;
	}
	print_cmd_error(array, array->cmd_group[prc].cmd);
}
