/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 03:07:53 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 02:58:27 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*temp;
	char	chr;

	temp = (char *)str;
	chr = c;
	while (*temp != chr)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
}
