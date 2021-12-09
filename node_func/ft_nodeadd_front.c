/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodeadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:24:30 by suan              #+#    #+#             */
/*   Updated: 2021/12/07 17:12:00 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_lstadd_front(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	new->next = *node;
	new->prev = NULL;
	(*node)->prev = new;
	*node = new;
}
