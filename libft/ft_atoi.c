/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 22:49:56 by suan              #+#    #+#             */
/*   Updated: 2021/08/20 20:59:37 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str++ - '0');
		if (num > 2147483647 && sign == 1)
			return (0);
		if (num > 2147483648 && sign == -1)
			return (0);
	}
	if (*str)
		return (0);
	return (num * sign);
}
