/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:17:21 by randrina          #+#    #+#             */
/*   Updated: 2024/02/21 13:47:39 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow(long int n)
{
	int	pow;

	pow = 1;
	while (n / 10)
	{
		pow = pow * 10;
		n = n / 10;
	}
	return (pow);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			pow;
	char		c;

	nb = n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb = -nb;
	}
	pow = ft_pow(nb);
	while (pow > 1)
	{
		c = (nb / pow) + '0';
		write (fd, &c, 1);
		nb = nb % pow;
		pow = pow / 10;
	}
	c = (nb / pow) + '0';
	write (fd, &c, 1);
}
