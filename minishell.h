/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:35 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 15:32:13 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define GRNA	"\x1B[38;5;34m"
# define GRNB	"\x1B[38;5;34m"
# define GRNC	"\x1B[38;5;35m"
# define GRND	"\x1B[38;5;35m"
# define GRNE	"\x1B[38;5;36m"
# define GRNF	"\x1B[38;5;36m"
# define WHT	"\x1B[37m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <dirent.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

enum {
	HEREDOC = 1,
	INFILE = 2,
	TRUNC = 3,
	APPEND = 4,
	PATH_MAX = 4096
};

typedef struct s_env
{
	int		size;
	char	**key;
	char	**value;
}	t_env;

typedef struct s_files
{
	int	infile;
	int	outfile;
	int	in_status;
	int	out_status;
	int	heredoc_status;
	int	curr_stdin;
	int	curr_stdout;
}	t_files;

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
	int		executed;
	int		*type;
	char	*cmd;
	char	*heredoc;
	char	**args;
	char	**token;
	t_files	files;
	t_redir	redir;
}	t_group;

typedef struct s_array
{
	int		i;
	int		exit;
	int		size;
	int		fd[2];
	int		n_cmdln;
	int		cd_count;
	int		toggle_info;
	int		filenumber;
	int		*process;
	char	*pwd;
	char	*home;
	char	*old_pwd;
	char	*temp;
	char	*line;
	char	**token;
	char	**en_var;
	t_env	env;
	t_group	*cmd_group;
}	t_array;

int	g_exitstat;

// minishell functions
void	minishell(char **envp);
void	handle_signals(int signum);

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
char	*get_next_line(int fd);
void	free_array(char **array, int size);
void	free_cmdgrp(t_array *array);
void	print_array(char **array);
void	print_cmdln(t_array *array);
void	print_args(t_array *array, int i);
void	print_redir(t_array *array, int i);

// builtin functions
int		checkfiles(t_array *array, int prc);
int		redir_file(t_array *array, int prc);
int		exit_minishell(t_array *array, int prc);
void	change_in_out_fd(t_array *array, int prc, int type);
void	echo(t_array *array, int prc);
void	cd_path(t_array *array, int prc);
void	print_cd_err(char *str, int type);
void	save_file(t_array *array, int prc);
void	print_pwd(t_array *array, int prc);
void	print_env(t_array *array, int prc);
void	unset_env(t_array *array, int prc);
void	export_env(t_array *array, int prc);
void	save_heredoc(t_array *array, int prc);
void	builtin(t_array *array, int prc);
void	check_dup(t_array *array, int prc);
void	init_env(t_array *array, char **envp);
void	remove_key_value(t_array *array, char *key);
void	add_env(t_array *array, char *str);
void	add_key_value(t_array *array, char *key, char *value);
char	*get_env_value(t_array *array, char *str);
char	*create_filename(t_array *array, int prc);

// executor functions
char	*re_path(char *str1, char *str2);
char	**get_path(t_array *array, int prc);
char	**get_arguments(t_array *array, int prc);
void	pipex(t_array *array);
void	run_pipex(t_array *array);
void	fork_exec(t_array *array, int prc);
void	extra_waitpid(t_array *array, int prc);
void	print_cmd_error(char *cmd);
void	close_dup(t_array *array, int prc);
void	closefds(t_array *array, int *lastfd, int i, int size);

#endif
