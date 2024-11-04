/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:21:11 by fclivaz           #+#    #+#             */
/*   Updated: 2023/11/28 17:05:11 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	x;

	if (!s)
		return (NULL);
	str = (char *)s;
	x = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == x)
			return (str);
		str++;
	}
	if (*str == x)
		return (str);
	return (0);
}
