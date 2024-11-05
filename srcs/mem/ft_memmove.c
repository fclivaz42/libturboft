/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:22:07 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 01:12:47 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	str1 = (char *)src;
	str2 = (char *)dest;
	if (src < dest)
		while (n--)
			str2[n] = str1[n];
	else
		while (n--)
			*str2++ = *str1++;
	return (dest);
}
