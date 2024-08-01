/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:12:58 by randrina          #+#    #+#             */
/*   Updated: 2024/02/23 17:20:48 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n && !((s1[len] == s2[len]) && !(s2[len])))
	{
		if (s1[len] != s2[len])
			return ((unsigned char )s1[len] - (unsigned char)s2[len]);
		len ++;
	}
	return (0);
}
