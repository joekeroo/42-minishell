/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:35 by jhii              #+#    #+#             */
/*   Updated: 2022/06/07 23:06:50 by jhii             ###   ########.fr       */
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

typedef struct s_env
{
	int		size;
	char	**key;
	char	**value;
}	t_env;

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
	int		n_arg;
	char	*cmd;
	char	**args;
	char	**token;
	t_redir	redir;
}	t_group;

typedef struct s_array
{
	int		size;
	int		n_cmdln;
	char	*temp;
	char	*line;
	char	**token;
	t_env	env;
	t_group	*cmd_group;
}	t_array;

// minishell functions
void	minishell(char **envp);

// lexer functions
int		lexer(t_array *array);
int		checkpipe(char *str, int i);
int		checkcommand(char *str, int i);
int		checkredir(char *str, int i, char type);
int		extraquotes(char *str, int i, int check);
int		checkquotes(char *str, int i, char type);

// expansion functions
int		envlen(char *str, int i);
int		check_signs(char c, int type);
int		skipquotes(char *str, int i, char c);
char	*extract_env(char *str, int *i);
void	check_expansion(t_array *array);
void	count_expansion(t_array *array, char *str, int *size);
void	replace_char(t_array *array, char *str, int *i, int *j);
void	expand(t_array *array, int curr, int i);

// parser functions
void	parser(t_array *array);
void	check_cmd(t_array *array);
void	check_args(t_array *array);
void	check_files(t_array *array);
void	init_cmdgrp(t_array *array);

// utility functions
int		ft_strcmp(char *a, char *b);
void	free_array(char **array, int size);
void	free_cmdgrp(t_array *array);
void	print_array(char **array);
void	print_cmdln(t_array *array);
void	print_args(t_array *array, int i);
void	print_redir(t_array *array, int i);

// builtin functions
void	echo(t_array *array);
void	builtin(t_array *array, char **envp);
void	export_env(t_array *array, char **envp);
void	add_key_value(t_array *array, char *key, char *value);

#endif
