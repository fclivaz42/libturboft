/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:06:23 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/26 04:15:55 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*convert(long k, size_t size, size_t *pos, int neg)
{
	char	*ret;

	ret = NULL;
	if (k < 0 && ++neg)
		k *= -1;
	if (k >= 10)
		ret = convert(k / 10, size + 1, pos, neg);
	if (ret == NULL)
	{
		ret = ft_calloc(neg + size + 1, sizeof(char));
		if (ret == NULL)
			return (NULL);
		*pos = 0;
		if (neg)
			ret[(*pos)++] = '-';
	}
	ret[(*pos)++] = (k % 10) + '0';
	return (ret);
}

inline char	*ft_ltoa(long n)
{
	size_t	pos;

	pos = 0;
	return (convert(n, 1, &pos, 0));
}

inline char	*ft_itoa(int n)
{
	return (ft_ltoa(n));
}
