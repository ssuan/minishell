/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:06:42 by suan              #+#    #+#             */
/*   Updated: 2021/12/13 21:32:31 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// -nnnnn, -n -n 전부 허용
int	check_opt_n(char *opt)
{
	if (*opt && *opt == '-')
		++opt;
	else
		return (FALSE);
	while (*opt && *opt != ' ')
	{
		if (*opt == 'n')
			++opt;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	print_env(char *env)
{
	char	*s;

	if (*env != '$')
		return (FAIL);
	++env;
	if (!*env)
	{
		ft_putstr_fd("$", 1);
		return (SUCCESS);
	}
	if (ft_strchr("0123456789?", *env))
	{
		if (*env == '?')
			ft_putnbr_fd(g_state.exit_status, 1);
		if (*env == '0')
			ft_putstr_fd("minishell", 1);
		ft_putstr_fd(env + 1, 1);
		return (SUCCESS);
	}
	s = find_value(env);
	if (s != NULL)
		ft_putstr_fd(s, 1);
	return (SUCCESS);
}

// int ft_~~()해서
// ret 값으로 exit_status 설정?
void	ft_echo(t_cmd *cmd)
{
	int		opt;
	t_node	*curr;

	opt = FALSE;
	curr = NULL;
	if (cmd->size > 1)
		curr = cmd->node->next;
	while (curr && check_opt_n(curr->str))
	{
		opt = TRUE;
		curr = curr->next;
	}
	while (curr)
	{
		if (print_env(curr->str) == FAIL)
			ft_putstr_fd(curr->str, 1);
		curr = curr->next;
		if (curr)
			ft_putchar_fd(' ', 1);
	}
	if (!opt)
		ft_putchar_fd('\n', 1);
	g_state.exit_status = 0;
}
