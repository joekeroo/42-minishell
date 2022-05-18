/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 05:54:24 by jhii              #+#    #+#             */
/*   Updated: 2022/05/18 15:53:04 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigit(int n)
{
	int	count;
	int	temp;

	count = 0;
	temp = n;
	if (temp == 0)
		return (1);
	if (temp < 0)
		temp = -temp;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	if (n < 0)
		return (count + 1);
	return (count);
}

static char	*ft_checknegative(char *str, int negative, int i)
{
	if (negative)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		negative;
	long	nbr;
	char	*res;

	nbr = n;
	i = ft_countdigit(nbr);
	negative = 0;
	res = malloc(ft_countdigit(nbr) + 1);
	if (!res)
		return (NULL);
	res[i--] = '\0';
	if (nbr == 0)
		res[i] = '0';
	if (nbr < 0)
	{
		negative = 1;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		res[i--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (ft_checknegative(res, negative, i));
}
