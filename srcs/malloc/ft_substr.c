/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:57:27 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 01:00:08 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;

	size = ft_strlen(s);
	if (size <= start)
		return (ft_calloc(1, 1));
	if (size - start < len)
		len = size - start;
	ret = (char *)ft_calloc(sizeof(char), len + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, &s[start], len);
	return (ret);
}
