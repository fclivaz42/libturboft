/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:42:29 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 03:07:56 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*splitter(const char *str, char c)
{
	int		i;
	char	*ret;

	i = -1;
	while (str[++i] != 0)
		if (str[i] == c)
			break ;
	ret = (char *)ft_calloc(i + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, str, i);
	return (ret);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	w;

	i = -1;
	w = 0;
	while (str[++i] != 0)
		if (i > 1 && str[i] == c && str[i - 1] != c)
			++w;
	if (str[i - 1] != c && i > 1)
		++w;
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word;
	size_t	x;

	x = -1;
	word = count_words(s, c);
	array = (char **)ft_calloc((word + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (word-- != 0)
	{
		while (*s == c)
			s++;
		array[++x] = splitter(s, c);
		if (array[x] == NULL)
		{
			ft_arrayfree(array);
			return (NULL);
		}
		while (*s++ != c)
			if (*s == 0)
				break ;
	}
	return (array);
}
