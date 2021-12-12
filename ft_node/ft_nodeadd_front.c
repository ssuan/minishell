/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:24:30 by suan              #+#    #+#             */
/*   Updated: 2021/12/12 21:27:55 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_nodeadd_front(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	new->next = *node;
	new->prev = NULL;
	(*node)->prev = new;
	*node = new;
}
