/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 20:18:05 by suan              #+#    #+#             */
/*   Updated: 2021/12/07 17:14:12 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

void	ft_nodedelone(t_node *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->contents);
	free(node);
}
