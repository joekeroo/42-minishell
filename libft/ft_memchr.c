/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:39:14 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 04:32:21 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned long	count;
	unsigned char	*cstr;

	count = 0;
	cstr = (unsigned char *)str;
	while (count < n)
	{
		if (cstr[count] == (unsigned char)c)
			return (cstr + count);
		count++;
	}
	return (NULL);
}
