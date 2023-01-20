/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:01:10 by shtanemu          #+#    #+#             */
/*   Updated: 2022/10/10 16:01:10 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	unsigned char		*d_casted;
	const unsigned char	*s_casted;

	d_casted = (unsigned char *)dst;
	s_casted = (const unsigned char *)src;
	if (!src || !n)
	{
		return (ft_strlen(src));
	}
	n -= 1;
	while (n && *s_casted != '\0')
	{
		*d_casted = (unsigned char)*s_casted;
		d_casted ++;
		s_casted ++;
		n --;
	}
	*d_casted = '\0';
	return (ft_strlen(src));
}
