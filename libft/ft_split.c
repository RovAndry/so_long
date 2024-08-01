/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:13:39 by randrina          #+#    #+#             */
/*   Updated: 2024/02/26 15:58:51 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[0] != c)
	{
		i = 1;
		count = 1;
	}
	while (*(s + i))
	{
		if (*(s + i) != c && *(s + i -1) == c)
			count ++;
		i ++;
	}
	return (count);
}

static int	ft_get_len(char const *s, char c)
{
	int	length;

	length = 0;
	while (s[length] && s[length] != c)
		length ++;
	return (length);
}

static int	ft_condition(char const *s, char **s1)
{
	if (!*s)
	{
		*s1 = NULL;
		return (1);
	}
	return (0);
}

static char	*ft_insert(char const *src, int len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = src[i];
		i ++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		j;
	int		ni;
	int		len;

	new = (char **)ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (new == NULL)
		return (NULL);
	if (ft_condition(s, new))
		return (new);
	j = 0;
	ni = 0;
	while (ni < ft_count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j ++;
		len = ft_get_len(&s[j], c);
		new[ni] = ft_insert(&s[j], len);
		if (new[ni] == NULL)
			free(new[ni]);
		j += len;
		ni ++;
	}
	return (new);
}
