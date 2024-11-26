/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:39:19 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/26 05:23:25 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strncat(char *dst, const char *src, size_t ssize)
{
	size_t	s;
	size_t	i;

	if (!dst || !src)
		return (0);
	s = ft_strlen(dst);
	i = -1;
	while (++i < ssize && *src != 0)
		dst[s + i] = *src++;
	dst[s + i] = 0;
	return (dst);
}
