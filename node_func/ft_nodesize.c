/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:30:15 by suan              #+#    #+#             */
/*   Updated: 2021/12/07 17:32:21 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	ft_nodesize(t_node *node)
{
	int	size;

	size = 0;
	while (node)
	{
		++size;
		node = node->next;
	}
	return (size);
}
