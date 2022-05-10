/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:19:29 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 04:40:00 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	uppercase;

	uppercase = 'A';
	while (uppercase <= 'Z')
	{
		if (c == uppercase)
			return (uppercase + 32);
		uppercase++;
	}
	return (c);
}
