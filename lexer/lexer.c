/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:31:33 by jhii              #+#    #+#             */
/*   Updated: 2022/05/10 17:33:16 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	int	checkcharacter(t_array *array, char *str, int i, int type)
{
	int	check;

	check = 0;
	if (str[i] == '\n')
		check++;
	else if (str[i] == '\'')
		check = checkquotes(str, i, '\'');
	else if (str[i] == '\"')
		check = checkquotes(str, i, '\"');
	else if (str[i] == '|')
		check = checksymbol(str, i, '|');
	else if (str[i] == '>')
		check = checksymbol(str, i, '>');
	else if (str[i] == '<')
		check = checksymbol(str, i, '<');
	else
		check = checkcommand(str, i);
	if (str[i] != '\n' && type == 1)
		array->size++;
	return (check);
}

static	int	get_token(t_array *array, char *str, int type)
{
	int	i;
	int	check;
	int	status;

	i = 0;
	status = 1;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		check = checkcharacter(array, str, i, type);
		if (check < 0)
		{
			printf("Syntax Error\n");
			status = -1;
			break ;
		}
		i = i + check;
	}
	return (status);
}

static	void	combine_array(t_array *array)
{
	(void)array;
}

void	lexer(t_array *array, char *str)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	array->size = 0;
	if (get_token(array, str, 1) < 0)
		return ;
	array->storage = malloc(sizeof(char *) * array->size + 1);
	while (i < array->size)
	{
		while (str[j] == ' ')
			j++;
		k = 0;
		len = checkcharacter(array, str, j, 2);
		array->storage[i] = malloc(sizeof(char) * len + 1);
		while (k < len)
			array->storage[i][k++] = str[j++];
		array->storage[i][k] = '\0';
		i++;
	}
	array->storage[i] = 0;
	combine_array(array);
}
