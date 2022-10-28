/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touuper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:49:50 by ttakami           #+#    #+#             */
/*   Updated: 2022/04/27 19:49:50 by ttakami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}

/*int main ()
{
	char a = 'a';
	printf("%c\n", ft_toupper(a));
}*/