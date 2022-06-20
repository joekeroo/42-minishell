/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:34:15 by jhii              #+#    #+#             */
/*   Updated: 2022/06/20 15:40:12 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_dup(t_array *array, int prc)
{
	if (array->cmd_group[prc].files.in_status)
	{
		array->cmd_group[prc].files.in_status = 0;
		dup2(array->cmd_group[prc].files.curr_stdin, 0);
		close(array->cmd_group[prc].files.curr_stdin);
	}
	if (array->cmd_group[prc].files.out_status)
	{
		array->cmd_group[prc].files.out_status = 0;
		dup2(array->cmd_group[prc].files.curr_stdout, 1);
		close(array->cmd_group[prc].files.curr_stdout);
	}
}

void	builtin(t_array *array, int prc)
{
	echo(array, prc);
	cd_path(array, prc);
	print_pwd(array, prc);
	print_env(array, prc);
	export_env(array, prc);
	unset_env(array, prc);
	if (array->cmd_group[prc].executed == 0)
		fork_exec(array, prc);
	check_dup(array, prc);
}
