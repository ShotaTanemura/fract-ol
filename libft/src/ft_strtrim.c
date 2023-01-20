/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:41:20 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 19:57:38 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_last(char const *str, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str);
	j = 0;
	while (i != 0 && set[j] != '\0')
	{
		j = 0;
		while (str[i] != '\0' && set[j] != '\0' && str[i] != set[j])
			j ++;
		i --;
	}
	if (i == 0)
		return (0);
	return (i + 1);
}

static size_t	get_first(char const *str, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && set[j] != '\0')
	{
		j = 0;
		while (str[i] != set[j] && set[j] != '\0')
			j ++;
		i ++;
	}
	if (i == 0)
		return (0);
	return (i - 1);
}

static	size_t	get_trim_len(char const *str, char const *set)
{
	int	result;

	result = get_last(str, set) - get_first(str, set);
	if (result >= 0)
		return (result + 1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	len;
	size_t	start;

	trim = NULL;
	if (s1 != NULL)
	{
		i = 0;
		len = get_trim_len(s1, set);
		trim = (char *)ft_calloc((size_t)(len + 1), sizeof(char));
		if (!trim)
			return (NULL);
		start = get_first(s1, set);
		while (i < len)
		{
			trim[i] = s1[start];
			i ++;
			start ++;
		}
	}
	return (trim);
}
