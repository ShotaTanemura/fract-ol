/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:09:25 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 11:57:36 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (unsigned char *)ft_calloc((ft_strlen(s) + 1), sizeof(unsigned char));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f((unsigned int)i, s[i]);
		i ++;
	}
	return ((char *)str);
}
