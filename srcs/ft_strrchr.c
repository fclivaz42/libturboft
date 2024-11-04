/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:21:11 by fclivaz           #+#    #+#             */
/*   Updated: 2023/12/08 19:50:01 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	int				x;
	unsigned char	f;

	if (!s)
		return (NULL);
	str = (char *)s;
	f = (unsigned char)c;
	x = ft_strlen(str) + 1;
	while (--x > 0)
		if (str[x] == f)
			return ((char *)str + x);
	if (str[x] == f)
		return ((char *)str + x);
	return (0);
}
