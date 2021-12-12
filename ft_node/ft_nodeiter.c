/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:24:01 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 21:28:05 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_nodeiter(t_node *node, void (*f)(void *))
{
	if (!node || !f)
		return ;
	while (node)
	{
		f(node->str);
		node = node->next;
	}
}
