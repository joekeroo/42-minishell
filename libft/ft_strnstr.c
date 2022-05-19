/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:28:11 by jhii              #+#    #+#             */
/*   Updated: 2022/05/19 12:35:06 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned long l)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && l >= ft_strlen(needle))
	{
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack);
		haystack++;
		l--;
	}
	return (NULL);
}
