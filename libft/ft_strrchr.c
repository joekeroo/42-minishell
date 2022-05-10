/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 03:07:53 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 02:57:44 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	chr;
	char	*res;

	res = (char *)str;
	len = ft_strlen(res);
	chr = c;
	while (len >= 0)
	{
		if (res[len] == chr)
			return (&res[len]);
		len--;
	}
	return (NULL);
}
