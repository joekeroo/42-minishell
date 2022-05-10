/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 21:28:11 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 04:38:57 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len >= (size_t)ft_strlen(needle))
	{
		if (*haystack == *needle)
			if (ft_strncmp(haystack, needle, (size_t)ft_strlen(needle)) == 0)
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
