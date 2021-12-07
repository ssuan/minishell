/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:57:47 by suan              #+#    #+#             */
/*   Updated: 2020/12/30 19:02:11 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr1;
	const char	*ptr2;

	if (!dst && !src)
		return (0);
	if (dst <= src)
	{
		ptr1 = dst;
		ptr2 = src;
		while (len--)
			*ptr1++ = *ptr2++;
	}
	else
	{
		ptr1 = dst + len;
		ptr2 = src + len;
		while (len--)
			*--ptr1 = *--ptr2;
	}
	return (dst);
}
