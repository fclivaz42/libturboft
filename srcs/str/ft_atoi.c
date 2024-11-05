/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:49:14 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/05 01:48:35 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_atoi(const char *nptr)
{
	int	x;
	int	neg;
	int	nbr;

	neg = 1;
	nbr = 0;
	x = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == ' ')
		++x;
	if (nptr[x] == '-')
		neg *= -1;
	if (nptr[x] == '-' || nptr[x] == '+')
		++x;
	while (nptr[x] >= '0' && nptr[x] <= '9')
		nbr = (nbr * 10) + (nptr[x++] - '0');
	return (nbr * neg);
}
