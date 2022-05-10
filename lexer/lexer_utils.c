/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:36:34 by jhii              #+#    #+#             */
/*   Updated: 2022/05/10 17:29:55 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// str = string, i = index, type = quotes symbol
int	checkquotes(char *str, int i, char type)
{
	int	len;
	int	closed_quotes;

	len = 0;
	closed_quotes = 0;
	if (str[i] != type)
		return (len);
	i++;
	len++;
	while (str[i])
	{
		if (str[i] != type)
			len++;
		else if (str[i] == type)
		{
			len++;
			closed_quotes++;
			break ;
		}
		i++;
	}
	if (closed_quotes == 0)
		len = -1;
	return (len);
}

// str = string, i = index, type = special characters
int	checksymbol(char *str, int i, char type)
{
	int	count;

	count = 0;
	if (type == '|')
	{
		if (str[i] == type)
			count++;
		if (str[i + 1] == type)
			count = -1;
	}
	else if (type == '>' || type == '<')
	{
		if (str[i] == type)
		{
			count++;
			if (str[i + 1] == type)
			{
				count++;
				if (str[i + 2] == type)
					count = -1;
			}
		}
	}
	return (count);
}

int	checkcommand(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"' && str[i] != '|'
			&& str[i] != '>' && str[i] != '<' && str[i] != ' '
			&& str[i] != '\n')
			len++;
		else
			break ;
		i++;
	}
	return (len);
}
