/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 16:31:24 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:53:59 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, int n)
{
	unsigned long	count;
	unsigned char	*dest;

	count = 0;
	dest = (unsigned char *)str;
	while (count < n)
	{
		dest[count] = (unsigned char)c;
		count++;
	}
	return (dest);
}
