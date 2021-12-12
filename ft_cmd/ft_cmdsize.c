/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:30:15 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 13:43:25 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	ft_cmdsize(t_cmd *cmd)
{
	int	size;

	size = 0;
	while (cmd)
	{
		++size;
		cmd = cmd->next;
	}
	return (size);
}