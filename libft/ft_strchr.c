/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 03:07:53 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:55:13 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	chr;
	char	*temp;

	chr = c;
	temp = (char *)str;
	while (*temp != chr)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
}
