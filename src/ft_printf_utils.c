/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 01:29:05 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/26 14:16:46 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	ssize_t	ft_put_string(char *str)
{
	ssize_t	len;

	if (!str)
		len = write(1, "(null)", 6);
	else
		len = write(1, str, ft_strlen(str));
	return (len);
}

static	ssize_t	ft_put_int(int num)
{
	ssize_t	len;
	char	*str;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	len = ft_put_string(str);
	free(str);
	return (len);
}

static	ssize_t	ft_put_point(uintptr_t point, const char *base)
{
	ssize_t	len;
	char	*str;

	str = ft_uitoa_base(point, ft_strlen(base), base);
	if (!str)
		return (-1);
	len = ft_put_string("0x");
	if (len == -1)
	{
		free(str);
		return (-1);
	}
	len += ft_put_string(str);
	free(str);
	if (len == 1)
		return (-1);
	return (len);
}

static	ssize_t	ft_put_uint_base(unsigned int num, const char *base)
{
	ssize_t	len;
	char	*str;

	str = ft_uitoa_base(num, ft_strlen(base), base);
	if (!str)
		return (-1);
	len = ft_put_string(str);
	free(str);
	return (len);
}

ssize_t	ft_put_sth(int c, va_list *args)
{
	va_list	temp;
	ssize_t	len;

	len = 0;
	va_copy(temp, *args);
	if (c == 'c')
		len = ft_put_char(va_arg(temp, int));
	else if (c == 's')
		len = ft_put_string(va_arg(temp, char *));
	else if (c == 'p')
		len = ft_put_point((uintptr_t)va_arg(temp, void *), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		len = ft_put_int(va_arg(temp, int));
	else if (c == 'u')
		len = ft_put_uint_base(va_arg(temp, unsigned int), "0123456789");
	else if (c == 'x')
		len = ft_put_uint_base(va_arg(temp, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_put_uint_base(va_arg(temp, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len = ft_put_char(c);
	va_end(temp);
	return (len);
}
