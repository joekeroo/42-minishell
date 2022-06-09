/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:38:09 by jhii              #+#    #+#             */
/*   Updated: 2022/06/09 15:06:43 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	print_export(t_array *array)
{
	int	i;

	i = 0;
	while (i < array->env.size)
	{
		printf("declare -x ");
		printf("%s", array->env.key[i]);
		printf("=\"");
		printf("%s", array->env.value[i]);
		printf("\"\n");
		i++;
	}
}

// type[1 = key, 2 = value]
static	char	*extr_env(char *str, int type)
{
	int		i;
	int		size;
	int		done;
	char	*temp;

	i = 0;
	size = 0;
	done = 0;
	while (str[i])
	{
		if (str[i] == '=')
			done++;
		if (done == 0)
			size++;
		i++;
	}
	if (type == 1)
		temp = ft_substr(str, 0, size);
	else
		temp = ft_substr(str, size + 1, i);
	return (temp);
}

static	void	add_env(t_array *array, char *str)
{
	int		i;
	int		status;
	char	*curr_key;
	char	*curr_value;

	i = 0;
	status = 0;
	curr_key = extr_env(str, 1);
	curr_value = extr_env(str, 2);
	while (i < array->env.size)
	{
		if (ft_strcmp(array->env.key[i], curr_key))
		{
			free(array->env.value[i]);
			array->env.value[i] = ft_strdup(curr_value);
			status = 1;
			break ;
		}
		i++;
	}
	if (status == 0)
		add_key_value(array, curr_key, curr_value);
	free(curr_key);
	free(curr_value);
}

static	void	error_check(t_array *array, int curr)
{
	int	i;

	i = 0;
	while (i < array->cmd_group[curr].n_arg)
	{
		if (ft_isdigit(array->cmd_group[curr].args[i][0]) == 0)
		{
			if (ft_strchr(array->cmd_group[curr].args[i], '='))
				add_env(array, array->cmd_group[curr].args[i]);
		}
		else
			printf("minishell: export: `%s': not a valid identifier\n",
				array->cmd_group[curr].args[i]);
		i++;
	}
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
		}
	}
}
