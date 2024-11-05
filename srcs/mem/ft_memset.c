/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:15:00 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 01:13:32 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	x;
	char	*str;

	x = -1;
	str = (char *)b;
	while (++x < len)
		str[x] = c;
	return (str);
}
