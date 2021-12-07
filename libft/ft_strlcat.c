/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:16:10 by suan              #+#    #+#             */
/*   Updated: 2021/08/03 00:27:05 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	l;

	if (!dst && !size)
		return (ft_strlen(src));
	l = ft_strlen(dst);
	if (size <= l)
		return (size + ft_strlen(src));
	return (l + ft_strlcpy(dst + l, src, size - l));
}
