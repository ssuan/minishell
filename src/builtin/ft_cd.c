/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:02:52 by suan              #+#    #+#             */
/*   Updated: 2021/12/15 18:24:09 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
cd: cd home
cd ~: cd home
cd ~ 1 1 1: cd home (no error)
cd -: OLDPWD
cd ~-: OLDPWD
bash-3.2$ cd -~


err msg
minishell$ cd
/usr/bin/cd: line 4: cd: HOME not set
ret 1
minishell$ cd -
/usr/bin/cd: line 4: cd: OLDPWD not set
ret 1
minishell$ cd a
/usr/bin/cd: line 4: cd: a: No such file or directory
ret 1

bash: cd: -~: invalid option -> -~, -p, ...
cd: usage: cd [-L|-P] [dir]
*/

#include "../../minishell.h"

int	cd_home(void)
{
	char	*path;
	char	*old;

	path = find_value("HOME");
	if (path == NULL)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	old = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory", 2);
		return (1);
	}
	env_update("PWD", path);
	env_update("OLDPWD", old);
	free(old);
	return (0);
}

int	cd_oldpwd(void)
{
	char	*path;
	char	*old;

	path = find_value("OLDPWD");
	if (path == NULL)
	{
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		return (1);
	}
	old = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory", 2);
		return (1);
	}
	env_update("PWD", path);
	env_update("OLDPWD", old);
	free(old);
	return (0);
}

// | 처리
// ~/Desktop -> $HOME/Desktop -> 환경변수로 바꾸는 곳에서 변경하기
int	ft_cd(t_cmd *cmd)
{
	char	*path;
	char	*old;
	int		ret;

	if (cmd->size == 1)
		return (cd_home());
	path = cmd->node->next->str;
	if (ft_strlen(path) == 0)	
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		return (1);
	}
	if (!ft_strcmp(path, "-") || !ft_strcmp(path, "--"))
		return (cd_oldpwd());
	if (*path == '-' && ft_strlen(path) > 1)
	{
		ft_putstr_fd("bash: cd: --: invalid option", 2);
		ft_putstr_fd("cd: usage: cd [dir]\n", 2);
		return (1);
	}
	old = getcwd(NULL, 0);
	ret = chdir(path);
	if (ret == -1)
	{
		// stat으로 존재x인지 디렉토리 아닌지 확인
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		//strerror(errno)
		return (1);
	}
	env_update("PWD", path);
	env_update("OLDPWD", old);
	free(old);
	return (0);
}