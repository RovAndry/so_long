/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:45:46 by randrina          #+#    #+#             */
/*   Updated: 2024/08/07 12:44:35 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_get(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strchr_get(char *str, char c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i ++;
	}
	return (NULL);
}

char	*ft_strdup_get(char *s)
{
	int		len;
	char	*new;
	int		i;

	new = NULL;
	len = ft_strlen_get(s);
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i ++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strcpy(char *dest, char *s1, char *s2)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	if (s1)
	{
		len = ft_strlen_get(s1);
		while (i < len)
		{
			dest[i] = s1[i];
			i ++;
		}
	}
	j = 0;
	len = ft_strlen_get(s2);
	while (j < ft_strlen_get(s2))
	{
		dest[i + j] = s2[j];
		j ++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	int		len;
	char	*final;

	final = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	len = ft_strlen_get(s1) + ft_strlen_get(s2);
	final = (char *) malloc(sizeof(char) * (len + 1));
	if (final == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	final = ft_strcpy(final, s1, s2);
	if (s1)
		free(s1);
	return (final);
}
