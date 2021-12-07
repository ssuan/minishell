/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 19:01:47 by suan              #+#    #+#             */
/*   Updated: 2020/12/31 18:19:26 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!dst && !src)
		return (0);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n--)
	{
		if (*ptr2 == (unsigned char)c)
		{
			*ptr1++ = *ptr2++;
			return (ptr1);
		}
		*ptr1++ = *ptr2++;
	}
	return (0);
}
