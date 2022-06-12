/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:32 by jhii              #+#    #+#             */
/*   Updated: 2022/06/12 15:14:02 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// update array->pwd && array->old_pwd && env
void	cd_path(t_array *array, int prc)
{
	if (ft_strcmp(array->cmd_group[prc].cmd, "cd"))
	{
		array->cd_count++;
		if (array->old_pwd)
			free(array->old_pwd);
		array->old_pwd = ft_strdup(array->pwd);
	}
}
