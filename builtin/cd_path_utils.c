/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:16 by jhii              #+#    #+#             */
/*   Updated: 2022/06/25 18:53:02 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	checkpwd(t_array *array, char *key)
{
	int	i;

	i = 0;
	while (i < array->env.size)
	{
		if (ft_strcmp(array->env.key[i], key) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	print_cd_err(char *str, int type)
{
	char	*res;
	char	*temp1;
	char	*temp2;
	char	*temp3;
	char	*temp4;

	temp1 = ft_strjoin("minishell: cd: ", str);
	temp2 = ft_strdup(": No such file or directory\n");
	temp3 = ft_strdup(": Not a directory\n");
	temp4 = ft_strdup(" not set\n");
	if (type == 1)
		res = ft_strjoin(temp1, temp2);
	if (type == 2)
		res = ft_strjoin(temp1, temp3);
	if (type == 3)
		res = ft_strjoin(temp1, temp4);
	ft_putstr_fd(res, 2);
	free(temp1);
	free(temp2);
	free(temp3);
	free(temp4);
	free(res);
	g_exitstat = 1;
}
