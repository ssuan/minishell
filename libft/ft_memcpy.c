/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:46:40 by suan              #+#    #+#             */
/*   Updated: 2020/12/31 14:13:32 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*ptr1;
	const char	*ptr2;

	if (!dst && !src)
		return (0);
	ptr1 = dst;
	ptr2 = src;
	while (n--)
		*ptr1++ = *ptr2++;
	return (dst);
}
