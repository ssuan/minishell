/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:46:17 by suan              #+#    #+#             */
/*   Updated: 2021/08/03 00:28:47 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		++start;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		--end;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
