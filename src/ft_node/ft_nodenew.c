/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:13:23 by suan              #+#    #+#             */
/*   Updated: 2021/12/16 15:45:27 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_node	*ft_nodenew(void *content, int flag)
{
	t_node	*new;

	new = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (!new)
		return (0);
	new->str = content;
	new->flag = flag;
	return (new);
}
