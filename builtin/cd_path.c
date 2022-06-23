/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhii <jhii@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:31:32 by jhii              #+#    #+#             */
/*   Updated: 2022/06/23 18:00:39 by jhii             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static	void	add_path(t_array *array)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strjoin("PWD=", array->pwd);
	temp2 = ft_strjoin("OLDPWD=", array->old_pwd);
	if (checkpwd(array, "PWD"))
		add_env(array, temp1);
	if (checkpwd(array, "OLDPWD"))
		add_env(array, temp2);
	free(temp1);
	free(temp2);
}

static	void	cd_env(t_array *array, char *dir)
{
	char	*temp;
	DIR		*directory;

	directory = NULL;
	temp = NULL;
	if (checkpwd(array, dir) == 1)
	{
		temp = get_env_value(array, dir);
		directory = opendir(temp);
		if (directory)
		{
			chdir(temp);
			closedir(directory);
		}
		else if (ENOENT == errno && ft_strlen(temp) > 0)
			print_cd_err(temp, 1);
		else if (ft_strlen(temp) > 0)
			print_cd_err(temp, 2);
	}
	else
		print_cd_err(dir, 3);
	free(temp);
}

static	void	cd_dir(t_array *array, int prc)
{
	DIR	*dir;

	dir = opendir(array->cmd_group[prc].args[0]);
	if (dir)
	{
		chdir(array->cmd_group[prc].args[0]);
		closedir(dir);
	}
	else if (ENOENT == errno)
		print_cd_err(array->cmd_group[prc].args[0], 1);
	else
		print_cd_err(array->cmd_group[prc].args[0], 2);
}

static	void	run_cd(t_array *array, int prc)
{
	if (array->cmd_group[prc].n_arg > 0
		&& !ft_strcmp(array->cmd_group[prc].args[0], "~")
		&& !ft_strcmp(array->cmd_group[prc].args[0], "-"))
		cd_dir(array, prc);
	else if ((array->cmd_group[prc].n_arg > 0
			&& ft_strcmp(array->cmd_group[prc].args[0], "-")))
		cd_env(array, "OLDPWD");
	else if ((array->cmd_group[prc].n_arg > 0
			&& ft_strcmp(array->cmd_group[prc].args[0], "~"))
		|| array->cmd_group[prc].n_arg == 0)
	{
		if (array->cmd_group[prc].n_arg == 0)
			cd_env(array, "HOME");
		else if (ft_strcmp(array->cmd_group[prc].args[0], "~") == 1)
			chdir(array->home);
	}
}

// update array->pwd && array->old_pwd && env
void	cd_path(t_array *array, int prc)
{
	char	cwd[PATH_MAX];

	if (!array->cmd_group[prc].cmd)
		return ;
	if (ft_strcmp(array->cmd_group[prc].cmd, "cd"))
	{
		array->cd_count++;
		if (array->old_pwd)
			free(array->old_pwd);
		array->old_pwd = ft_strdup(getcwd(cwd, sizeof(cwd)));
		run_cd(array, prc);
		if (array->pwd)
			free(array->pwd);
		array->pwd = ft_strdup(getcwd(cwd, sizeof(cwd)));
		add_path(array);
		array->cmd_group[prc].executed = 1;
	}
}
