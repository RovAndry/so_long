/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:56:18 by randrina          #+#    #+#             */
/*   Updated: 2024/02/24 14:51:08 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_sign(const char *s, int index)
{
	if (ft_isdigit(s[index]))
		return (1);
	else if (s[index] == '-')
	{
		if (ft_isdigit(s[index + 1]))
			return (-1);
		else
			return (0);
	}
	else if (s[index] == '+')
	{
		if (ft_isdigit(s[index + 1]))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static long int	ft_str_to_nbr(const char *s, int start, int end)
{
	long int	nbr;
	int			n;
	int			pow;

	nbr = 0;
	pow = 1;
	while (end >= start)
	{
		n = s[end] - '0';
		nbr = nbr + (n * pow);
		pow = pow * 10;
		end --;
	}
	return (nbr);
}

static int	ft_get_end(const char *s, int start)
{
	int	end;

	end = start;
	while (ft_isdigit(s[end]))
		end ++;
	return (end);
}

int	ft_atoi(const char *nptr)
{
	long int	nb;
	int			sign;
	int			start;
	int			end;

	start = 0;
	while (ft_is_space(nptr[start]))
		start ++;
	sign = ft_sign(nptr, start);
	if (sign == 0)
		return (0);
	if (nptr[start] == '-' || nptr[start] == '+')
		start = start + 1;
	end = ft_get_end(nptr, start + 1);
	nb = ft_str_to_nbr(nptr, start, end - 1);
	return ((int)nb * sign);
}
