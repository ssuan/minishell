/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:37:18 by suan              #+#    #+#             */
/*   Updated: 2021/12/29 22:34:47 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	get_line(char **line)
{
	*line = readline("\033[34mminishell$ \033[0m");
	if (*line == NULL)
	{
		ft_putstr_fd("\033[1A", 1);
		ft_putstr_fd("\033[11C", 1);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
}

void	launch_minishell(char *line)
{
	t_cmd	*tcmd;

	if (!check_space(line))
	{
		tcmd = parsing(line);
		if (!tcmd)
		{
			free_cmd(tcmd);
			return ;
		}
		//get_env(tcmd);
		add_history(line);
		execute(tcmd);
		free_cmd(tcmd);
	}
}

void	prompt(void)
{
	char	*line;

	while (1)
	{
		get_line(&line);
		launch_minishell(line);
		free(line);
	}
}
