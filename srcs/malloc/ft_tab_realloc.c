/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:43:52 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/10 19:43:37 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	**ft_tab_realloc(void **tab, size_t add, size_t bsize)
{
	size_t	len;
	void	**ret;

	if (tab == NULL)
		return (ft_calloc(add, bsize));
	else
		len = ft_tablen((const void **)tab);
	ret = ft_calloc(len + add, bsize);
	if (!ret)
		return (NULL);
	if (len > 0)
		ft_memcpy(ret, tab, len);
	free(tab);
	return (ret);
}
