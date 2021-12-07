/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:34:03 by suan              #+#    #+#             */
/*   Updated: 2021/08/02 23:53:45 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	l;

	if (!dst)
		return (0);
	l = ft_strlen_gnl(src);
	if (!dstsize)
		return (l);
	while (*src && dstsize--)
		if (dstsize > 0)
			*dst++ = *src++;
	*dst = 0;
	return (l);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!s2)
		return (0);
	ft_strlcpy_gnl(s2, s1, ft_strlen_gnl(s1) + 1);
	return (s2);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup_gnl(s2));
	if (!s2)
		return (ft_strdup_gnl(s1));
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	ft_strlcpy_gnl(str, s1, s1_len + 1);
	free(s1);
	ft_strlcpy_gnl(str + s1_len, s2, s2_len + 1);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		++i;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
