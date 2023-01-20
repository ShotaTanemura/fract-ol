/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:16:22 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 11:54:51 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char		ch;
	const unsigned char	*s;
	unsigned char		*tmp;

	ch = (unsigned char)c;
	s = (const unsigned char *)str;
	tmp = NULL;
	while (*s)
	{
		if (*s == (const unsigned char)ch)
			tmp = (unsigned char *)s;
		s ++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)tmp);
}
