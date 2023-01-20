/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:56:50 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 12:16:13 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t slen)
{
	size_t	len;

	len = ft_strlen(little);
	if (!big && !slen)
		return (NULL);
	while (ft_strncmp(big, little, len) != 0)
	{
		if (len > slen || *big == '\0')
			return (NULL);
		slen --;
		big ++;
	}
	if (len > slen)
		return (NULL);
	return ((char *)big);
}
