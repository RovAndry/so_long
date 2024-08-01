/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:53:12 by randrina          #+#    #+#             */
/*   Updated: 2024/02/26 15:29:24 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	slen;
	char			*new;
	unsigned int	nlen;

	if (!s || len == 0)
		return (ft_strdup(""));
	slen = ft_strlen((char *)s);
	if (s == NULL || slen <= start)
		return (ft_strdup(""));
	nlen = slen - start + 1;
	if (slen > start + (unsigned int)len)
		nlen = len + 1;
	new = (char *)ft_calloc((size_t)nlen, sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < nlen - 1 && (s[start + i]))
	{
		new[i] = s[start + i];
		i ++;
	}
	return (new);
}
