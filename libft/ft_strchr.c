/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:49:12 by randrina          #+#    #+#             */
/*   Updated: 2024/02/23 17:14:42 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*l;

	i = 0;
	l = (char *)s;
	while (l[i])
	{
		if (l[i] == (char)c)
			return (&l[i]);
		i++;
	}
	if ((char)c == 0)
		return (&l[i]);
	return (NULL);
}
