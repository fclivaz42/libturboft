/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:31:10 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 00:49:58 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		i;
	int		start;

	i = -1;
	while (s1[++i] != 0)
		if (ft_strchr(set, s1[i]) == 0)
			break ;
	start = i;
	i = ft_strlen(s1) + 1;
	while (--i != 0)
		if (ft_strchr(set, s1[i]) == 0)
			break ;
	if (i - start < 0)
		return (ft_calloc(1, 1));
	ret = (char *)ft_substr(s1, start, i - start + 1);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
