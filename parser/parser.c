/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:08:12 by jhii              #+#    #+#             */
/*   Updated: 2022/06/08 16:14:10 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	toggle_print(t_array *array)
{
	if (array->toggle_info == 1)
		print_cmdln(array);
	if (array->n_cmdln == 1 && array->cmd_group[0].n_arg == 0
		&& array->cmd_group[0].cmd)
	{
		if (ft_strcmp(array->cmd_group[0].cmd, "print"))
		{
			if (array->toggle_info == 1)
				array->toggle_info = 0;
			else
				array->toggle_info = 1;
		}
	}
}

void	parser(t_array *array)
{
	init_cmdgrp(array);
	check_expansion(array);
	check_files(array);
	check_cmd(array);
	check_args(array);
	toggle_print(array);
}
