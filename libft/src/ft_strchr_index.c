/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:00:14 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/05 19:04:15 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_index(const char *str, int c)
{
	const unsigned char	*s_casted;
	unsigned char		c_casted;
	size_t				i_s_casted;

	if (!str)
		return (0);
	i_s_casted = 0;
	s_casted = (const unsigned char *)str;
	c_casted = (unsigned char)c;
	while (s_casted[i_s_casted])
	{
		if (s_casted[i_s_casted] == (const unsigned char)c_casted)
			return (i_s_casted);
		i_s_casted ++;
	}
	if (c_casted == '\0' && s_casted[i_s_casted] == '\0')
		return (i_s_casted);
	return (0);
}
