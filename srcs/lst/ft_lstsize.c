/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:41 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/10 20:21:07 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	size_t	size;

	if (!lst)
		return (0);
	temp = lst;
	size = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		++size;
	}
	return (size);
}
