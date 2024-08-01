/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:55:47 by randrina          #+#    #+#             */
/*   Updated: 2024/02/23 17:18:33 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*l;

	l = (char *)s;
	i = ft_strlen(s) - 1;
	if ((char)c == 0)
		return (&l[i + 1]);
	while (i >= 0)
	{
		if (l[i] == (char)c)
			return (&l[i]);
		i--;
	}
	return (NULL);
}
