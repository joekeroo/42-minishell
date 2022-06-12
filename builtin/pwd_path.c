/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:19:46 by jhii              #+#    #+#             */
/*   Updated: 2022/06/12 14:50:37 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_pwd(t_array *array, int prc)
{
	if (ft_strcmp(array->cmd_group[prc].cmd, "pwd"))
	{
		array->exitstat = 0;
		if (array->pwd)
			printf("%s\n", array->pwd);
	}
}
