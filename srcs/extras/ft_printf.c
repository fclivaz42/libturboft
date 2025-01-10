/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:59:26 by fclivaz           #+#    #+#             */
/*   Updated: 2025/01/10 21:07:02 by fclivaz          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <unistd.h>

static void	print_hex(unsigned long int ptdr, char str, int *i, int fd)
{
	if (str == 'x' || str == 'X')
		ptdr = (unsigned int)ptdr;
	if (str == 'p')
	{
		*i += write(fd, "0x", 2);
		++str;
	}
	if (ptdr >= 16)
	{
		print_hex(ptdr / 16, str, i, fd);
		print_hex(ptdr % 16, str, i, fd);
	}
	else
	{
		if (ptdr <= 9)
			*i += ft_putchar_fd((ptdr + '0'), fd);
		else
		{
			if (str == 'x' || str == 'p' || str == 'q')
				*i += ft_putchar_fd((ptdr - 10 + 'a'), fd);
			if (str == 'X')
				*i += ft_putchar_fd((ptdr - 10 + 'A'), fd);
		}
	}
}

static void	check_format(va_list ap, const char str, int *i, int fd)
{
	char	*s;

	if (str == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
		{
			*i += write(fd, "(null)", 6);
			return ;
		}
		*i += ft_putstr_fd(s, fd);
	}
	else if (str == 'c')
		*i += ft_putchar_fd(va_arg(ap, int), fd);
	else if (str == 'i' || str == 'd')
		*i += ft_putnbr_fd(va_arg(ap, int), fd);
	else if (str == 'u')
		*i += ft_putnbr_fd(va_arg(ap, unsigned int), fd);
	else if (str == 'x' || str == 'X')
		print_hex(va_arg(ap, int), str, i, fd);
	else if (str == 'p')
		print_hex(va_arg(ap, uintptr_t), str, i, fd);
	else if (str == '%')
		*i += write(1, "%", 1);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			i += ft_putchar_fd(*str, fd);
		if (*str == '%')
		{
			check_format(ap, str[1], &i, fd);
			++str;
		}
		++str;
	}
	va_end(ap);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
			i += ft_putchar_fd(*str, STDOUT_FILENO);
		if (*str == '%')
		{
			check_format(ap, str[1], &i, STDOUT_FILENO);
			++str;
		}
		++str;
	}
	va_end(ap);
	return (i);
}
