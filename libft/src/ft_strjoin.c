/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:57:17 by shtanemu          #+#    #+#             */
/*   Updated: 2022/10/12 14:57:17 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*saved;

	str = ft_calloc((ft_strlen(s2) + ft_strlen(s1) + 1), sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	saved = str;
	while (s1 && *s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (s2 && *s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	return (saved);
}
