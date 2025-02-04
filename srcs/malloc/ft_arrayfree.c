/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:55:33 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/10 20:05:03 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_arrayfree(void **array)
{
	char	**fr;

	if (!array)
		return ;
	fr = (char **)array - 1;
	while (*++fr)
		free(*fr);
	free(array);
}
