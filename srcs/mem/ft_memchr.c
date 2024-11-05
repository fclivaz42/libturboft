/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:10:52 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 01:04:30 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = -1;
	str = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (++i < n - 1)
		if ((unsigned char)c == str[i])
			return (&str[i]);
	if ((unsigned char)c == str[i])
		return (&str[i]);
	return (NULL);
}
