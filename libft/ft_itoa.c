/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 20:20:15 by suan              #+#    #+#             */
/*   Updated: 2021/08/19 01:20:14 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digit(int n)
{
	size_t	digit;

	digit = 0;
	if (n <= 0)
		digit = 1;
	while (n)
	{
		n /= 10;
		++digit;
	}
	return (digit);
}

static void	ft_store_nbr(char *nbr, int n, unsigned int unbr)
{
	int	i;
	int	div;

	i = 0;
	if (n < 0)
		nbr[i++] = '-';
	div = 1;
	while (unbr / div >= 10)
		div *= 10;
	while (div)
	{
		nbr[i++] = unbr / div + '0';
		unbr = unbr % div;
		div = div / 10;
	}
	nbr[i] = 0;
}

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	unbr;

	nbr = malloc(sizeof(char) * (ft_digit(n) + 1));
	if (!nbr)
		return (0);
	unbr = n;
	if (n < 0)
		unbr = -n;
	ft_store_nbr(nbr, n, unbr);
	return (nbr);
}
