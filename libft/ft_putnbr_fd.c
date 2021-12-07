/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suan <suan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 22:04:03 by suan              #+#    #+#             */
/*   Updated: 2021/08/03 00:21:22 by suan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	nbr_to_char(int n, int fd)
{
	char	c;

	if (n >= 10)
		nbr_to_char(n / 10, fd);
	c = '0' + n % 10;
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	nbr_to_char(n, fd);
}
