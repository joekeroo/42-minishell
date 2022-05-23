/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:31:33 by jhii              #+#    #+#             */
/*   Updated: 2022/05/23 14:41:46 by jhii             ###   ########.fr       */
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
		check = checkpipe(str, i);
	else if (str[i] == '>')
		check = checkredir(str, i, '>');
	else if (str[i] == '<')
		check = checkredir(str, i, '<');
	else
		check = checkcommand(str, i);
	if (str[i] != '\n' && type == 1)
		array->size++;
	return (check);
}

static	int	checkfirstpipe(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|')
	{
		printf("Syntax Error\n");
		return (-1);
	}
	return (i);
}

static	int	get_token(t_array *array, char *str, int type)
{
	int	i;
	int	check;
	int	status;

	status = 1;
	i = checkfirstpipe(str);
	if (i < 0)
		return (i);
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

static	void	init_lexer(t_array *array)
{
	array->size = 0;
	array->token = NULL;
}

int	lexer(t_array *array)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	init_lexer(array);
	if (get_token(array, array->line, 1) < 0)
		return (-1);
	array->token = malloc(sizeof(char *) * array->size + 1);
	while (i < array->size)
	{
		while (array->line[j] == ' ')
			j++;
		k = 0;
		len = checkcharacter(array, array->line, j, 2);
		array->token[i] = malloc(sizeof(char) * len + 1);
		while (k < len)
			array->token[i][k++] = array->line[j++];
		array->token[i][k] = '\0';
		i++;
	}
	array->token[i] = 0;
	return (1);
}
