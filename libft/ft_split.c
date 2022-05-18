/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 05:53:13 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:54:59 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static int	ft_getstr(const char *s, char c, int i)
{
	int		j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (ft_countstr(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			str[j] = malloc(ft_getstr(s, c, i) + 1);
			if (str[j] == NULL)
				return (NULL);
			ft_strlcpy(str[j++], (char *)s + i, ft_getstr(s, c, i) + 1);
			i = i + ft_getstr(s, c, i);
		}
	}
	str[j] = 0;
	return (str);
}
