/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:31:48 by jhii              #+#    #+#             */
/*   Updated: 2022/06/01 16:27:41 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_array(char **array)
{
	int	i;

	i = 0;
	printf("[");
	while (array[i])
	{
		printf("%s", array[i++]);
		if (array[i])
			printf(", ");
	}
	printf("]\n");
}

void	print_redir(t_array *array, int i)
{
	int	j;

	j = 0;
	printf("files = ");
	while (j < array->cmd_group[i].redir.size)
	{
		printf("%s ", array->cmd_group[i].redir.files[j]);
		printf("(%d)", array->cmd_group[i].redir.types[j++]);
		if (j < array->cmd_group[i].redir.size)
			printf(", ");
	}
	printf("\n");
	printf("infile = %s\n", array->cmd_group[i].redir.infile);
	printf("outfile = %s\n", array->cmd_group[i].redir.outfile);
}

void	print_cmdln(t_array *array)
{
	int	i;
	int	j;

	i = 0;
	while (i < array->n_cmdln)
	{
		j = 0;
		printf("\n");
		print_redir(array, i);
		printf("tokens = %s\n", array->cmd_group[i].cmd);
		printf("token = ");
		while (j < array->cmd_group[i].size)
		{
			printf("%s", array->cmd_group[i].token[j++]);
			if (j < array->cmd_group[i].size)
				printf(", ");
		}
		printf("\n\n");
		i++;
	}
}
