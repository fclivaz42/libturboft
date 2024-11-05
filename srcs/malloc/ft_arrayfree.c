/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:55:33 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 03:16:25 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_arrayfree(void *array)
{
	char	**fr;

	if (!array)
		return ;
	fr = (char **)array - 1;
	while (*++fr)
		free(*fr);
	free(array);
}
