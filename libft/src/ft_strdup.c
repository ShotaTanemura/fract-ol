/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:41:31 by shtanemu          #+#    #+#             */
/*   Updated: 2022/10/12 13:41:31 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*cpy;

	len = ft_strlen(src);
	i = 0;
	cpy = ft_calloc((len + 1), sizeof(char));
	if (!cpy)
		return (NULL);
	while (len)
	{
		cpy[i] = src[i];
		i ++;
		len --;
	}
	return (cpy);
}
