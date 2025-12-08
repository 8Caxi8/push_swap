/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caxi <caxi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:22:21 by dansimoe          #+#    #+#             */
/*   Updated: 2025/10/30 09:22:55 by caxi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**stop_free(char **a, int words)
{
	while (--words >= 0)
		free(a[words]);
	free(a);
	return (NULL);
}

char	**split_words(char **a, const char *s, char c)
{
	int		words;
	size_t	len;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			a[words - 1] = malloc(sizeof(char) * (len + 1));
			if (!a[words - 1])
				return (stop_free(a, words));
			ft_strlcpy(a[words - 1], s, len + 1);
			s += len;
		}
		else
			s++;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		i;
	char	**a;

	if (!s)
		return (NULL);
	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	a = malloc(sizeof(char *) * (words + 1));
	if (!a)
		return (NULL);
	a[words] = NULL;
	return (split_words(a, s, c));
}
