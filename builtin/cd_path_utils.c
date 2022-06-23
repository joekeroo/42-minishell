/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:16 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 13:22:57 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cd_err(char *str, int type)
{
	if (type == 1)
		printf("minishell: cd: %s: No such file or directory\n", str);
	if (type == 2)
		printf("minishell: cd: %s: Not a directory\n", str);
	if (type == 3)
		printf("minishell: cd: %s not set\n", str);
	g_exitstat = 1;
}
