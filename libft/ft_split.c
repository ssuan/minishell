/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:42:13 by suan              #+#    #+#             */
/*   Updated: 2021/08/19 01:31:14 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
	return (0);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

static int	ft_store_word(char **word, const char *src, size_t len)
{
	char	*dst;

	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	ft_strlcpy(dst, src, len + 1);
	*word = dst;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**words;
	char const	*pos;
	size_t		idx;
	size_t		len;

	words = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s || !words)
		return (0);
	idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			pos = s;
			len = 0;
			while (*s && *s++ != c)
				++len;
			if (!ft_store_word(&words[idx++], pos, len))
				return (ft_malloc_error(words));
		}
		else
			++s;
	}
	words[idx] = 0;
	return (words);
}
