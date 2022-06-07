/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:59:10 by jhii              #+#    #+#             */
/*   Updated: 2022/06/07 23:12:08 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(char *a, char *b)
{
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	if (ft_strncmp(a, b, ft_strlen(b)) == 0)
		return (1);
	return (0);
}
