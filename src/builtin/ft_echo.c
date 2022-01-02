/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:06:42 by suan              #+#    #+#             */
/*   Updated: 2022/01/02 20:25:23 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// -nnnnn, -n -n 전부 허용
static int	check_opt_n(char *opt)
{
	if (*opt && *opt == '-')
		++opt;
	else
		return (FALSE);
	while (*opt)
	{
		if (*opt == 'n')
			++opt;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	ft_echo(t_cmd *cmd)
{
	int		opt;
	t_node	*curr;

	opt = FALSE;
	curr = NULL;
	printf("size = %d\n",cmd->size);
	if (cmd->size > 1)
		curr = cmd->node->next;
	while (curr && check_opt_n(curr->str))
	{
		opt = TRUE;
		curr = curr->next;
	}
	while (curr)
	{
		ft_putstr_fd(curr->str, 1);
		if (curr->next)
			ft_putchar_fd(' ', 1);
		curr = curr->next;
	}
	if (!opt)
		ft_putchar_fd('\n', 1);
	return (0);
}
