/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:58:17 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 16:14:42 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, unsigned long size)
{
	int				dlen;
	int				slen;
	unsigned long	count;

	dlen = 0;
	count = 0;
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
