/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:36:34 by jhii              #+#    #+#             */
/*   Updated: 2022/05/26 14:17:37 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	checkpipe(char *str, int i)
{
	int	len;
	int	count;

	count = 0;
	len = ft_strlen(str);
	if (str[i++] == '|')
		count++;
	while (str[i] == ' ')
		i++;
	if (str[i] == '|' || i == len)
		count = -1;
	return (count);
}

// str = string, i = index, type = special characters
int	checkredir(char *str, int i, char type)
{
	int	len;
	int	count;

	count = 0;
	len = ft_strlen(str);
	if (str[i] == type)
	{
		if (str[i + 1] == type)
		{
			i = i + 2;
			count = count + 2;
		}
		else
		{
			i = i + 1;
			count = count + 1;
		}
		while (str[i] == ' ')
			i++;
		if (str[i] == '<' || str[i] == '>' || str[i] == '|' || i == len)
			count = -1;
	}
	return (count);
}

int	checkcommand(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"' && str[i] != '|'
			&& str[i] != '>' && str[i] != '<' && str[i] != ' '
			&& str[i] != '\0')
			len++;
		else
			break ;
		i++;
	}
	return (len);
}

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

int	extraquotes(char *str, int i, int check)
{
	while (str[i + check] == '\'' || str[i + check] == '\"')
	{
		if (str[i + check] == '\'')
		{
			if (checkquotes(str, i + check, '\'') == -1)
				check = -1;
			else
				check = check + checkquotes(str, i + check, '\'');
		}
		else if (str[i + check] == '\"')
		{
			if (checkquotes(str, i + check, '\"') == -1)
				check = -1;
			else
				check = check + checkquotes(str, i + check, '\"');
		}
		if (check == -1)
			break ;
	}
	return (check);
}
