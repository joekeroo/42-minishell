/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:39:14 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:52:32 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, int n)
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
