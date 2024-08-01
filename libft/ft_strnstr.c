/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:38:33 by randrina          #+#    #+#             */
/*   Updated: 2024/02/23 17:25:44 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	char	*bigg;
	int		flag;

	bigg = (char *)big;
	if (!little[0] || little == big)
		return (bigg);
	i = 0;
	while (bigg[i] && (i + ft_strlen((char *)little) <= len))
	{
		j = 0;
		flag = 1;
		while (j < (int)ft_strlen((char *)little))
		{
			if (bigg[i + j] != little[j])
				flag = 0;
			j ++;
		}
		if (flag == 1)
			return (&bigg[i]);
		i ++;
	}
	return (NULL);
}
