/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:54:13 by suan              #+#    #+#             */
/*   Updated: 2021/08/03 00:27:10 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	l;

	if (!dst)
		return (0);
	l = ft_strlen(src);
	if (!dstsize)
		return (l);
	while (*src && dstsize--)
		if (dstsize > 0)
			*dst++ = *src++;
	*dst = 0;
	return (l);
}
