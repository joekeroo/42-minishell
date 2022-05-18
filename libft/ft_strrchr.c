/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 03:07:53 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:51:50 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	chr;
	char	*res;

	chr = c;
	res = (char *)str;
	len = ft_strlen(res);
	while (len >= 0)
	{
		if (res[len] == chr)
			return (&res[len]);
		len--;
	}
	return (NULL);
}
