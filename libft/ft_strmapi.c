/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:11:36 by randrina          #+#    #+#             */
/*   Updated: 2024/02/21 12:52:02 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		ret[i] = f(i, s[i]);
		i ++;
	}
	ret[i] = '\0';
	return (ret);
}
