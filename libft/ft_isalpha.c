/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 01:35:28 by jhii              #+#    #+#             */
/*   Updated: 2021/07/21 04:30:42 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	int	lowercase;
	int	uppercase;

	lowercase = 'a';
	uppercase = 'A';
	while (lowercase <= 'z' || uppercase <= 'Z')
	{
		if (c == uppercase)
			return (1);
		if (c == lowercase)
			return (2);
		lowercase++;
		uppercase++;
	}
	return (0);
}
