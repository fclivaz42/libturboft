/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:21:40 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 01:10:56 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	x;

	x = -1;
	if (!src && !dest)
		return (NULL);
	if (src == dest || n == 0)
		return (dest);
	while (++x < n)
		((unsigned char *)dest)[x] = ((unsigned char *)src)[x];
	return (dest);
}
