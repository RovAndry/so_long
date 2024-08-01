/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:36:39 by randrina          #+#    #+#             */
/*   Updated: 2024/02/22 09:36:59 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;	
	size_t	ret;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	i = 0;
	if (dest_len >= size)
		return (src_len + size);
	ret = src_len + dest_len;
	while (dest_len < (size - 1) && *(src + i) != '\0')
	{
		*(dst + dest_len) = *(src + i);
		i ++;
		dest_len ++;
	}
	*(dst + dest_len) = '\0';
	return (ret);
}
