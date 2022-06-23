/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:11:03 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 13:24:22 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cmd_error(char *cmd)
{
	char	*res;
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin("minishell: ", cmd);
	temp2 = ft_strdup(": command not found\n");
	res = ft_strjoin(temp1, temp2);
	ft_putstr_fd(res, 2);
	free(temp1);
	free(temp2);
	free(res);
	g_exitstat = 127;
}

char	**get_path(t_array *array, int prc)
{
	int		i;
	char	*path;
	char	**temp;

	i = 0;
	path = get_env_value(array, "PATH");
	if (!path)
	{
		print_cmd_error(array->cmd_group[prc].cmd);
		return (NULL);
	}
	temp = ft_split(path, ':');
	free(path);
	return (temp);
}

char	**get_arguments(t_array *array, int prc)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = malloc(sizeof(char *) * (array->cmd_group[prc].n_arg + 2));
	temp[j++] = ft_strdup(array->cmd_group[prc].cmd);
	while (i < array->cmd_group[prc].n_arg)
		temp[j++] = ft_strdup(array->cmd_group[prc].args[i++]);
	temp[j] = NULL;
	return (temp);
}

char	*re_path(char *str1, char *str2)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	result = malloc(sizeof(char) * len + 1);
	while (str1[j])
		result[i++] = str1[j++];
	result[i++] = '/';
	j = 0;
	while (str2[j])
		result[i++] = str2[j++];
	result[i] = '\0';
	return (result);
}
