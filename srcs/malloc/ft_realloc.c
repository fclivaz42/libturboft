/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:43:52 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 03:17:44 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_realloc(void *str, size_t add, size_t bsize)
{
	size_t	len;
	void	*ret;

	if (str == NULL)
		return (ft_calloc(add, bsize));
	else
		len = ft_strlen(str);
	ret = ft_calloc(len + add, bsize);
	if (!ret)
		return (NULL);
	if (len > 0)
		ft_memcpy(ret, str, len);
	free(str);
	return (ret);
}
