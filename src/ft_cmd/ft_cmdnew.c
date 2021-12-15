/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:13:23 by suan              #+#    #+#             */
/*   Updated: 2021/12/09 18:32:02 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*ft_cmdnew(void *content)
{
	t_cmd	*new;

	new = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
	if (!new)
		return (0);
	new->node = content;
	new->next = 0;
	return (new);
}
