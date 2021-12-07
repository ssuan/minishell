/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:44:41 by suan              #+#    #+#             */
/*   Updated: 2021/08/03 00:25:40 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
