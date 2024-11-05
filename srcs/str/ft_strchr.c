/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:21:11 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 01:57:55 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	x;

	if (!s)
		return (NULL);
	str = (unsigned char *)s - 1;
	x = (unsigned char)c;
	while (*++str != 0)
		if (*str == x)
			return ((char *)str);
	if (*str == x)
		return ((char *)str);
	return (NULL);
}
