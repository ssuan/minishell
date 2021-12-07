/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:50:49 by suan              #+#    #+#             */
/*   Updated: 2020/12/31 18:22:22 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		++s;
	}
	return (0);
}
