/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:08:18 by randrina          #+#    #+#             */
/*   Updated: 2024/02/23 11:45:52 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i ++;
	}
	return ((void *)dest);
}
