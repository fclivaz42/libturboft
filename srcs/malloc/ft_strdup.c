/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:55:49 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 00:45:00 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (str == NULL)
		return (str);
	ft_memcpy(str, s1, ft_strlen(s1));
	return (str);
}
