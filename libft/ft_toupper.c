/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:39:50 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 04:40:14 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	lowercase;

	lowercase = 'a';
	while (lowercase <= 'z')
	{
		if (c == lowercase)
			return (lowercase - 32);
		lowercase++;
	}
	return (c);
}
