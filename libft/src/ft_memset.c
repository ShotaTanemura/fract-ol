/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:28:44 by shtanemu          #+#    #+#             */
/*   Updated: 2022/10/08 18:28:44 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	while (n)
	{
		*ptr = (unsigned char)c;
		ptr ++;
		n --;
	}
	return (dst);
}
