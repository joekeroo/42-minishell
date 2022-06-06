/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:38:09 by jhii              #+#    #+#             */
/*   Updated: 2022/06/06 16:39:30 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	print_export(t_array *array, char **envp)
{
	(void)array;
	(void)envp;
	return ;
}

void	export_env(t_array *array, char **envp)
{
	if (array->n_cmdln > 1 || !array->cmd_group[0].cmd)
		return ;
	if (ft_strncmp(array->cmd_group[0].cmd, "export", 6) == 0)
	{
		if (array->cmd_group[0].n_arg == 0)
			print_export(array, envp);
	}
}
