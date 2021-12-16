/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodelast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:11:50 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 21:28:08 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*ft_nodelast(t_node *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}
