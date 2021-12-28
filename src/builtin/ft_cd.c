/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:02:52 by suan              #+#    #+#             */
/*   Updated: 2021/12/28 15:56:33 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	cd_home(void)
{
	char	*path;
	char	*old;

	path = find_value("HOME");
	if (path == NULL)
	{
		print_error("cd", "HOME not set");
		return (1);
	}
	old = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		print_error2("cd", path, "No such file or directory");
		free(old);
		return (1);
	}
	env_update("PWD", path);
	env_update("OLDPWD", old);
	free(old);
	return (0);
}

static int	cd_oldpwd(void)
{
	char	*path;
	char	*old;

	path = find_value("OLDPWD");
	if (path == NULL)
	{
		print_error("cd", "OLDPWD not set");
		return (1);
	}
	old = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		print_error2("cd", path, "No such file or directory");
		free(old);
		return (1);
	}
	env_update("PWD", path);
	env_update("OLDPWD", old);
	free(old);
	return (0);
}

static int	cd_path(char *path)
{
	char	*old;
	int		ret;

	old = getcwd(NULL, 0);
	ret = chdir(path);
	if (ret == -1)
	{
		print_error2("cd", path, strerror(errno));
		free(old);
		return (1);
	}
	env_update("PWD", path);
	env_update("OLDPWD", old);
	free(old);
	return (0);
}

// | 처리
int	ft_cd(t_cmd *cmd)
{
	char	*path;

	if (cmd->size == 1)
		return (cd_home());
	path = cmd->node->next->str;
	if (ft_strlen(path) == 0)
		return (cd_home());
	if (!ft_strcmp(path, "-") || !ft_strcmp(path, "--"))
		return (cd_oldpwd());
	if (*path == '-' && ft_strlen(path) > 1)
	{
		print_error2("cd", path + 1, "invalid option");
		print_error2("cd", "usage", "cd [dir]");
		return (1);
	}
	return (cd_path(path));
}
