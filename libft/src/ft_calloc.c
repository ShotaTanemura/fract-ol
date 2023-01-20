/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:16:09 by shtanemu          #+#    #+#             */
/*   Updated: 2022/10/30 14:45:23 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*addr;

	if (count == 0 && size == 0)
		return (ft_calloc(1, 1));
	if ((size != 0) && (count > (size_t)SIZE_MAX / size))
		return (NULL);
	addr = (char *)malloc(size * count);
	if (!addr)
		return (NULL);
	ft_bzero(addr, size * count);
	return ((void *)addr);
}
