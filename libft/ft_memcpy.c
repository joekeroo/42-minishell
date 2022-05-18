/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:32:15 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:53:12 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
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
