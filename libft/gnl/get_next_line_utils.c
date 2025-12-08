/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansimoe <dansimoe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:42:20 by dansimoe          #+#    #+#             */
/*   Updated: 2025/12/03 16:24:48 by dansimoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	len_t;
	size_t	len_s1;
	size_t	i;
	char	*a;

	len_s1 = ft_strlen(s1);
	len_t = len_s1 + ft_strlen(s2);
	a = ft_calloc(len_t + 1, sizeof(char));
	if (!a)
		return (NULL);
	i = -1;
	if (s1)
	{
		while (s1[++i])
			a[i] = s1[i];
		free(s1);
	}
	i = -1;
	while (s2[++i])
		a[i + len_s1] = s2[i];
	a[len_t] = 0;
	return (a);
}

int	append_line(char *temp, char **line, char **buffer)
{
	char	*new;

	if (temp)
	{
		*line = ft_strjoin(*line, temp);
		if (!*line)
			return (free(temp), -1);
		new = ft_strjoin(NULL, *buffer + ft_strlen(temp));
		if (!new)
			return (free(temp), -1);
		free(*buffer);
		*buffer = new;
		return (free(temp), 1);
	}
	*line = ft_strjoin(*line, *buffer);
	if (!*line)
		return (free(*buffer), *buffer = NULL, 0);
	if (**line == 0)
	{
		free(*line);
		*line = NULL;
	}
	return (free(*buffer), *buffer = NULL, 0);
}

int	get_line(char **line, char **buffer)
{
	char	*temp;
	int		i;
	int		j;

	if (!*buffer)
		return (0);
	temp = NULL;
	i = -1;
	j = -1;
	while ((*buffer)[++i])
	{
		if ((*buffer)[i] == '\n')
		{
			i++;
			temp = ft_calloc(sizeof(char), i + 1);
			if (!temp)
				return (0);
			while (++j < i)
				temp[j] = (*buffer)[j];
			break ;
		}
	}
	return (append_line(temp, line, buffer));
}
