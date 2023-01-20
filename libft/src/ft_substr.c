/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:15:08 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 19:47:23 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	subs = (char *)ft_calloc((size_t)(len + 1), sizeof(char));
	if (!subs)
		return (NULL);
	while (start && *s != '\0')
	{
		start --;
		s ++;
	}
	ft_strlcpy(subs, s, len + 1);
	return (subs);
}
