/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:18:12 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 12:00:54 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	const unsigned char	*s;
	unsigned char		ch;

	s = (const unsigned char *)str;
	ch = (unsigned char)c;
	while (*s)
	{
		if (*s == (const unsigned char)ch)
			return ((char *)s);
		s ++;
	}
	if (ch == '\0' && *s == '\0')
		return ((char *)s);
	return (NULL);
}
