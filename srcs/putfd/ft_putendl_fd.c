/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:53:26 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 02:28:51 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

inline int	ft_putendl_fd(char *s, int fd)
{
	return (ft_putstr_fd(s, fd) + write(fd, "\n", 1));
}
