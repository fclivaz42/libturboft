/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:21:11 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 02:14:49 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	int				x;
	unsigned char	f;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	f = (unsigned char)c;
	x = ft_strlen(s) + 1;
	while (--x > 0)
		if (str[x] == f)
			return ((char *)str + x);
	if (str[x] == f)
		return ((char *)str + x);
	return (0);
}
