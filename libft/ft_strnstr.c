/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:22:57 by suan              #+#    #+#             */
/*   Updated: 2021/08/03 00:28:18 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;

	if (!*needle)
		return ((char *)haystack);
	l = ft_strlen(needle);
	while (*haystack && len)
	{
		if (len < l)
			break ;
		if (!ft_strncmp(haystack, needle, l))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (0);
}
