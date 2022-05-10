/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:32:15 by jhii              #+#    #+#             */
/*   Updated: 2021/07/22 00:16:30 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	count;
	unsigned char	*cdest;
	unsigned char	*csrc;

	count = 0;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (dest != NULL || src != NULL)
	{
		while (count < n)
		{
			cdest[count] = csrc[count];
			count++;
		}
	}
	return (cdest);
}
