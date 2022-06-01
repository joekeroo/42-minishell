/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:08:12 by jhii              #+#    #+#             */
/*   Updated: 2022/06/01 15:15:14 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser(t_array *array)
{
	init_cmdgrp(array);
	check_files(array);
	// check_cmd(array);
	print_cmdln(array);
}
