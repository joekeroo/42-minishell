/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:34:15 by jhii              #+#    #+#             */
/*   Updated: 2022/06/09 15:28:45 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin(t_array *array, int prc)
{
	echo(array, prc);
	cd_path(array, prc);
	print_pwd(array, prc);
	print_env(array, prc);
	export_env(array, prc);
	unset_env(array, prc);
	exit_minishell(array, prc);
}
