/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 05:49:30 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:51:21 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, int len)
{
	int		i;
	int		slen;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start + len > slen)
		len = slen - start;
	if (start > slen)
		len = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
