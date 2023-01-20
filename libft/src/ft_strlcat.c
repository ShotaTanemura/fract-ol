/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:42:47 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 17:20:38 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				dlen;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!d && !siz)
		return ((ft_strlen((const char *)src)));
	dlen = ft_strlen((const char *)d);
	if (dlen >= siz)
		return (ft_strlen(src) + siz);
	d += dlen;
	while (*s && (siz > (size_t)d - (size_t)dst + 1))
	{
		*d = *s;
		d ++;
		s ++;
	}
	*d = '\0';
	return (ft_strlen((const char *)dst) + ft_strlen((const char *)s));
}
