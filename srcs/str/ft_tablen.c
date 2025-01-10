/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:37:29 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/10 19:44:57 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_tablen(const void **tab)
{
	size_t	len;

	if (!tab)
		return (0);
	len = 0;
	while (tab[len] != NULL)
		++len;
	return (len);
}
