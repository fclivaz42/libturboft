/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:59:36 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 02:20:42 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	i = -1;
	if (!s || !f)
		return (NULL);
	ret = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (s[++i] != 0)
		ret[i] = f(i, s[i]);
	return (ret);
}
