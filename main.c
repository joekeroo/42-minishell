/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:45:31 by jhii              #+#    #+#             */
/*   Updated: 2022/06/22 15:27:47 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	print_header(void)
{
	printf("\n\n");
	printf(GRNA"█▀▄▀█ ▄█    ▄   ▄█    ▄▄▄▄▄    ▄  █ ▄███▄   █    █     \n");
	printf(GRNB"█ █ █ ██     █  ██   █     ▀▄ █   █ █▀   ▀  █    █     \n");
	printf(GRNC"█ ▄ █ ██ ██   █ ██ ▄  ▀▀▀▀▄   ██▀▀█ ██▄▄    █    █     \n");
	printf(GRND"█   █ ▐█ █ █  █ ▐█  ▀▄▄▄▄▀    █   █ █▄   ▄▀ ███▄ ███▄  \n");
	printf(GRNE"   █   ▐ █  █ █  ▐               █  ▀███▀       ▀    ▀ \n");
	printf(GRNF"  ▀      █   ██                 ▀                      \n");
	printf(WHT"\n\n");
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	g_filenumber = 0;
	print_header();
	minishell(envp);
	return (0);
}
