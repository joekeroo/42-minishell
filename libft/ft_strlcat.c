/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:58:17 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 04:37:14 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dlen;
	size_t	slen;

	count = 0;
	dlen = 0;
	slen = ft_strlen(src);
	while (*dst && count < size)
	{
		dst++;
		dlen++;
		count++;
	}
	while (*src && count < size - 1 && size != 0)
	{
		*dst++ = *src++;
		count++;
	}
	if (count == size - 1 || *src == '\0')
		*dst = '\0';
	return (dlen + slen);
}
