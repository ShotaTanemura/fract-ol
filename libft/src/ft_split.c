/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:08:44 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 20:19:38 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_free(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free((void *)arr[i ++]);
	free((void *)arr);
	arr = NULL;
	return (0);
}

static int	get_word(char const *s, char c, char **chararr, size_t cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < cnt && *s != '\0')
	{
		while (*s == c)
			s ++;
		j = 0;
		while (s[j] != c && s[j] != '\0')
			j ++;
		chararr[i] = ft_calloc((j + 1), sizeof(char));
		if (!chararr[i])
		{
			get_free(chararr, i);
			return (0);
		}
		j = 0;
		while (*s != c && *s != '\0')
			chararr[i][j ++] = *s ++;
		i ++;
	}
	return (1);
}

static size_t	get_cnt_word(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s ++;
		while (*s != c && *s != '\0')
			s ++;
		if (*(s - 1) != c)
			cnt ++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	size_t	cnt;
	char	**chararr;

	if (!s)
		return (NULL);
	cnt = get_cnt_word(s, c);
	chararr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!chararr)
		return (NULL);
	if (!get_word(s, c, chararr, cnt))
		return (NULL);
	chararr[cnt] = NULL;
	return (chararr);
}
