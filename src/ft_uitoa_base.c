/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:40:49 by ttakami           #+#    #+#             */
/*   Updated: 2022/09/25 03:23:59 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa_base(uintptr_t num, size_t rx, const char *base)
{
	ssize_t		digit;
	uintptr_t	tmp;
	char		*result;

	tmp = num;
	digit = 0;
	while (digit == 0 || tmp != 0)
	{
		tmp /= rx;
		digit++;
	}
	result = (char *)malloc((sizeof(char) * digit) + 1);
	if (!result)
		return (NULL);
	result[digit] = '\0';
	while (digit-- > 0)
	{
		result[digit] = base[num % rx];
		num /= rx;
	}
	return (result);
}
