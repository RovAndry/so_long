/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: randrina <randrina@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 08:45:10 by randrina          #+#    #+#             */
/*   Updated: 2024/08/07 13:04:23 by randrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_line(int fd, char *stash)
{
	char	*buffer;
	int		nb_read;

	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	nb_read = 1;
	while (!ft_strchr_get(stash, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		stash = ft_strjoin_get(stash, buffer);
	}
	free(buffer);
	if (stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*ft_def_line(char *str)
{
	char	*line;
	int		i;

	line = NULL;
	if (str == NULL)
		return (NULL);
	if (str[0] == '\n')
		return (ft_strdup_get("\n"));
	i = 0;
	while (str[i] && str[i] != '\n')
		i ++;
	if (str[i])
		i = i + 1;
	line = (char *) malloc (sizeof(char) * (i + 1));
	if (line == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(line, str, i + 1);
	return (line);
}

char	*ft_def_stash(char *str)
{
	int		i;
	char	*stash;

	stash = NULL;
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
		i ++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i = i + 1;
	stash = ft_strdup_get(&str[i]);
	free(str);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	stash = ft_read_line(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = ft_def_line(stash);
	stash = ft_def_stash(stash);
	return (line);
}
