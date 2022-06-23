/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:38:09 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 13:18:12 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	print_line(t_array *array, int i)
{
	printf("declare -x ");
	printf("%s", array->env.key[i]);
	printf("=\"");
	printf("%s", array->env.value[i]);
	printf("\"\n");
}

static	void	print_export(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->env.size)
	{
		if (ft_strcmp(array->env.key[i], "OLDPWD"))
		{
			if (array->cd_count == 0)
				printf("declare -x OLDPWD\n");
			else
				print_line(array, i);
		}
		else
			print_line(array, i);
		i++;
	}
	g_exitstat = 0;
}

static	void	error_check(t_array *array, int curr)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < array->cmd_group[curr].n_arg)
	{
		if (ft_isdigit(array->cmd_group[curr].args[i][0]) == 0)
		{
			if (ft_strchr(array->cmd_group[curr].args[i], '='))
				add_env(array, array->cmd_group[curr].args[i]);
		}
		else
		{
			check = 1;
			printf("minishell: export: `%s': not a valid identifier\n",
				array->cmd_group[curr].args[i]);
		}
		i++;
	}
	if (check == 1)
		g_exitstat = 1;
	else
		g_exitstat = 0;
}

void	export_env(t_array *array, int prc)
{
	if (array->cmd_group[prc].cmd)
	{
		if (ft_strcmp(array->cmd_group[prc].cmd, "export"))
		{
			if (array->cmd_group[prc].n_arg == 0)
				print_export(array);
			else
				error_check(array, prc);
			array->cmd_group[prc].executed = 1;
		}
	}
}
