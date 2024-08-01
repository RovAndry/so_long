/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:40:58 by randrina          #+#    #+#             */
/*   Updated: 2024/02/26 14:45:13 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_in(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_strlentrim(char const *s, char const *t)
{
	size_t	start;
	size_t	end;

	start = 0;
	while (is_in(t, s[start]))
		start ++;
	if (start == ft_strlen((char *)s))
		return (0);
	end = ft_strlen((char *)s);
	end --;
	while (is_in(t, s[end]))
		end --;
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*final;

	if (!s1 && !set)
		return (ft_strdup(""));
	len = ft_strlentrim(s1, set);
	final = ft_calloc(len + 1, sizeof(char));
	if (final == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (is_in(set, s1[j]))
		j++;
	while (i < len)
	{
		final[i] = s1[j];
		i++;
		j++;
	}
	return (final);
}
