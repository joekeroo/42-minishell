/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:34 by jhii              #+#    #+#             */
/*   Updated: 2022/05/10 17:12:28 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	printarray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		printf("%s\n", array[i++]);
}

void	minishell(void)
{
	char	*temp;
	t_array	array;

	while (1)
	{
		ft_putstr_fd("minishell % ", 1);
		temp = get_next_line(0);
		if (ft_strncmp(temp, "exit\n", 5) == 0)
		{
			printf("exit\n");
			free(temp);
			break ;
		}
		lexer(&array, temp);
		printarray(array.storage);
		free(temp);
	}
	return ;
}
