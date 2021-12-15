/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:37:18 by suan              #+#    #+#             */
/*   Updated: 2021/12/15 15:57:11 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_line(char **line)
{
	*line = readline("\033[34mminishell$ \033[0m");
	if (*line == NULL)
	{
		ft_putstr_fd("\x1b[1A", 1);
		ft_putstr_fd("\x1b[11C", 1);
		ft_putstr_fd("exit\n", 1);
		exit(0);
	}
}

// "\x1b[A": UP, "\x1b[B": DOWN, "\x1b[C": RIGHT, "\x1b[D": LEFT
// \x1b == \033
void	prompt(void)
{
	char	*line;
	t_cmd	*tcmd;

	while (1)
	{
		get_line(&line);
		if (!check_space(line))
		{
			tcmd = parsing(line);
			//dollor_to_env(tcmd);
 			//print_cmd(tcmd);
			add_history(line);
			execution(tcmd);
			//system("leaks minishell");
			//free_cmd(tcmd);
		}
		//free(line);
	}
}
