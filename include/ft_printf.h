/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:16:34 by ttakami           #+#    #+#             */
/*   Updated: 2023/02/26 14:16:18 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*ft_uitoa_base(uintptr_t num, size_t rx, const char *base);
ssize_t	ft_put_char(int c);
ssize_t	ft_put_sth(int c, va_list *args);
int		ft_printf(const char *fmt, ...);
#endif
