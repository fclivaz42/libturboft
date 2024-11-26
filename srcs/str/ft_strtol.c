/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:03 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/26 03:56:40 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	ft_strtol(const char *nptr, long *nbr, const int base)
{
	long		i;
	int			neg;
	const char	*e = "0123456789abcdefghijklmnopqrstuvwxyz";

	neg = 1;
	i = 0;
	if (!nptr || base < 2 || base > 36)
		return (0);
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-')
		neg *= -1;
	if (*nptr == '-' || *nptr == '+')
		++nptr;
	while (ft_memchr(e, ft_tolower(*nptr), base))
	{
		if (ft_isdigit(*nptr))
			i = (i * base) + *nptr++ - '0';
		else
			i = (i * base) + ft_tolower(*nptr++) - 'a' + 10;
	}
	*nbr = i * neg;
	return (*nptr);
}
