/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:35 by jhii              #+#    #+#             */
/*   Updated: 2022/05/10 15:39:36 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_array
{
	char	**storage;
	int		size;
}	t_array;

// minishell functions
void	minishell(void);

// lexer functions
int		checkcommand(char *str, int i);
int		checkquotes(char *str, int i, char type);
int		checksymbol(char *str, int i, char type);
void	lexer(t_array *array, char *str);

// utility functions
char	*get_next_line(int fd);

#endif