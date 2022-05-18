/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:53:43 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:53:23 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
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
