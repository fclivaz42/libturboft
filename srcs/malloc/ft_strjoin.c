/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:39:59 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 02:19:20 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	sl1;
	size_t	sl2;

	sl1 = ft_strlen(s1);
	sl2 = ft_strlen(s2);
	ret = (char *)ft_calloc(sl1 + sl2 + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, sl1);
	ft_memcpy(ret + sl1, s2, sl2);
	return (ret);
}
