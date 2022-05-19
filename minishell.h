/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:35 by jhii              #+#    #+#             */
/*   Updated: 2022/05/19 15:29:04 by jhii             ###   ########.fr       */
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

typedef struct s_array
{
	char	*line;
	char	**token;
	int		size;
}	t_array;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// minishell functions
void	minishell(void);

// lexer functions
int		checkcommand(char *str, int i);
int		checkquotes(char *str, int i, char type);
int		checkpipe(char *str, int i);
int		checkredir(char *str, int i, char type);
void	lexer(t_array *array, char *str);

// utility functions
void	free_array(char **tab);
void	print_array(char **array);

// linkedlist functions
int		ft_lstsize(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void*));
void	ft_lstadd_back(t_list **lst, t_list *newl);
void	ft_lstadd_front(t_list **lst, t_list *newl);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

#endif
