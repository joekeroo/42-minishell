/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:19:46 by jhii              #+#    #+#             */
/*   Updated: 2022/06/17 16:22:32 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	check_pwd(char *str)
{
	if (ft_strlen(str) != 3)
		return (0);
	if (str[0] != 'p' && str[0] != 'P')
		return (0);
	if (str[1] != 'w' && str[1] != 'W')
		return (0);
	if (str[2] != 'd' && str[2] != 'D')
		return (0);
	return (1);
}

int	print_pwd(t_array *array, int prc)
{
	if (!array->cmd_group[prc].cmd)
		return (0);
	if (check_pwd(array->cmd_group[prc].cmd))
	{
		array->exitstat = 0;
		if (array->pwd)
			printf("%s\n", array->pwd);
		return (1);
	}
	return (0);
}
