/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 03:57:37 by fclivaz           #+#    #+#             */
/*   Updated: 2024/11/26 04:37:32 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long	ft_atol_base(const char *nptr, const int base)
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
	return (i * neg);
}

inline int	ft_atoi_base(const char *nptr, const int base)
{
	return (ft_atol_base(nptr, base));
}
