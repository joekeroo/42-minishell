/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:34:15 by jhii              #+#    #+#             */
/*   Updated: 2022/06/17 16:27:22 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	check_dup(t_array *array, int prc)
{
	if (array->cmd_group[prc].files.in_status)
	{
		dup2(array->cmd_group[prc].files.curr_stdin, 0);
		close(array->cmd_group[prc].files.curr_stdin);
	}
	if (array->cmd_group[prc].files.out_status)
	{
		dup2(array->cmd_group[prc].files.curr_stdout, 1);
		close(array->cmd_group[prc].files.curr_stdout);
	}
}

void	builtin(t_array *array, int prc)
{
	if (redir_file(array, prc) < 0)
		return ;
	echo(array, prc);
	cd_path(array, prc);
	print_pwd(array, prc);
	print_env(array, prc);
	export_env(array, prc);
	unset_env(array, prc);
	check_dup(array, prc);
	exit_minishell(array, prc);
	// run_exec(array, prc);
}
