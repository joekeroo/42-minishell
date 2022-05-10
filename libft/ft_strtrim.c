/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 05:51:54 by jhii              #+#    #+#             */
/*   Updated: 2021/07/22 01:56:43 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkfront(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_strlen(s1))
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_checkback(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_strlen(s1))
	{
		if (ft_strchr(set, s1[ft_strlen(s1) - 1 - i]) == 0)
			break ;
		i++;
	}
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_checkfront(s1, set);
	end = ft_checkback(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
