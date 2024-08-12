/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:37:41 by randrina          #+#    #+#             */
/*   Updated: 2024/08/07 14:10:01 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1len;
	int		s2len;
	char	*new;

	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	new = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		new[i] = s1[i];
		i ++;
	}
	while (i < (s1len + s2len))
	{
		new[i] = s2[i - s1len];
		i ++;
	}
	new[i] = '\0';
	free((char *)s1);
	return (new);
}
