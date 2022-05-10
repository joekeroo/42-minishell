/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:53:43 by jhii              #+#    #+#             */
/*   Updated: 2021/07/22 00:17:50 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	count;
	unsigned char	*cdest;
	unsigned char	*csrc;

	count = n;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (dest != NULL || src != NULL)
	{
		if (csrc < cdest)
		{
			csrc += count;
			cdest += count;
			while (count--)
				*--cdest = *--csrc;
		}
		else
		{
			while (count--)
				*cdest++ = *csrc++;
		}
	}
	return (dest);
}
