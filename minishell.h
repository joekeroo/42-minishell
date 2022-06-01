/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:35 by jhii              #+#    #+#             */
/*   Updated: 2022/06/01 16:15:16 by jhii             ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

enum {
	HEREDOC = 1,
	INFILE = 2,
	TRUNC = 3,
	APPEND = 4
};

typedef struct s_redir
{
	int		size;
	int		*types;
	char	**files;
	char	*infile;
	char	*outfile;
}	t_redir;

typedef struct s_group
{
	int		size;
	char	*cmd;
	char	**token;
	t_redir	redir;
}	t_group;

typedef struct s_array
{
	int		size;
	int		n_cmdln;
	char	*line;
	char	**token;
	t_group	*cmd_group;
}	t_array;

// minishell functions
void	minishell(void);

// lexer functions
int		lexer(t_array *array);
int		checkpipe(char *str, int i);
int		checkcommand(char *str, int i);
int		checkredir(char *str, int i, char type);
int		extraquotes(char *str, int i, int check);
int		checkquotes(char *str, int i, char type);

// parser functions
void	parser(t_array *array);
void	init_cmdgrp(t_array *array);
void	check_files(t_array *array);
void	check_cmd(t_array *array);

// utility functions
void	free_array(char **array, int size);
void	free_cmdgrp(t_array *array);
void	print_array(char **array);
void	print_cmdln(t_array *array);
void	print_redir(t_array *array, int i);

// builtin functions
void	echo(void);

#endif
