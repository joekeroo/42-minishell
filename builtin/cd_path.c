/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:32 by jhii              #+#    #+#             */
/*   Updated: 2022/06/18 15:11:30 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// update array->pwd && array->old_pwd && env
void	cd_path(t_array *array, int prc)
{
	if (!array->cmd_group[prc].cmd)
		return ;
	if (ft_strcmp(array->cmd_group[prc].cmd, "cd"))
	{
		array->cd_count++;
		if (array->old_pwd)
			free(array->old_pwd);
		array->old_pwd = ft_strdup(array->pwd);
		array->cmd_group[prc].executed = 1;
	}
}
