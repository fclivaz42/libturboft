/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:03 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/18 04:00:18 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strtol(char *nptr, long *nbr, const int base)
{
	long		i;
	int			neg;

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
	while (ft_memchr(ALNUM, ft_toupper(*nptr), base))
	{
		if (ft_isdigit(*nptr))
			i = (i * base) + *nptr++ - '0';
		else
			i = (i * base) + ft_toupper(*nptr++) - 'A' + 10;
	}
	*nbr = i * neg;
	return (nptr);
}
