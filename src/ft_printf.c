/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:16:28 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/26 14:13:46 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	ssize_t		len;
	ssize_t		tmp;
	ssize_t		i;

	len = 0;
	i = -1;
	va_start(args, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
			tmp = ft_put_sth(fmt[++i], &args);
		else
			tmp = ft_put_char(fmt[i]);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	va_end(args);
	return ((int)len);
}
