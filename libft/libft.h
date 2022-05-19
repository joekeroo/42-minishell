/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:09:39 by jhii              #+#    #+#             */
/*   Updated: 2022/05/19 15:31:24 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../minishell.h"

int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int n);
int		ft_isprint(int c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_strlcat(char *dst, const char *src, unsigned long size);
int		ft_strlcpy(char *dst, const char *src, unsigned long size);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_memcmp(const void *str1, const void *str2, int n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, int len);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, unsigned long l);
void	ft_bzero(void *s, unsigned long n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(unsigned long count, unsigned long size);
void	*ft_memset(void *str, int c, int n);
void	*ft_memchr(const void *str, int c, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memmove(void *dest, const void *src, int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
