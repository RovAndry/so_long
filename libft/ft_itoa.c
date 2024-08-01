/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:49:37 by randrina          #+#    #+#             */
/*   Updated: 2024/02/24 08:49:39 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(long	int n)
{
	int	len;

	len = 0;
	while (n / 10)
	{
		len ++;
		n = n / 10;
	}
	len = len + 1;
	return (len);
}

static int	ft_pow(int length)
{
	int	pow;

	pow = 1;
	while (length > 1)
	{
		pow = pow * 10;
		length --;
	}
	return (pow);
}

static void	ft_insertnb(char *s, long int nb, int n)
{
	int		i;
	int		pow;
	char	c;

	pow = ft_pow(ft_nb_len(nb));
	i = 0;
	if (n < 0)
	{
		s[i] = '-';
		i = 1;
	}
	while (pow > 1)
	{
		c = (nb / pow) + '0';
		s[i] = c;
		nb = nb % pow;
		pow = pow / 10;
		i ++;
	}
	c = nb + '0';
	s[i] = c;
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			length;

	nb = (long int)n;
	if (nb < 0)
	{
		nb = -nb;
		length = ft_nb_len(nb) + 1;
	}
	else
		length = ft_nb_len(nb);
	str = (char *)ft_calloc(length + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_insertnb(str, nb, n);
	return (str);
}
