/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.s                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:09:07 by shtanemu          #+#    #+#             */
/*   Updated: 2022/11/05 17:37:55 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(long n)
{
	size_t	dig;

	dig = 0;
	if (n < 0)
		dig++;
	while (n != 0)
	{
		n /= 10;
		dig++;
	}
	return (dig);
}

static size_t	get_num(int dig)
{
	size_t	i;

	i = 1;
	dig--;
	while (dig)
	{
		i *= 10;
		dig--;
	}
	return (i);
}

static char	*get_char(char *str, long num, int dig)
{
	size_t	i;
	char	*saved;

	i = 1;
	saved = str;
	if (num < 0)
	{
		*str = '-';
		str ++;
		dig --;
		num *= -1;
	}
	i = get_num(dig);
	while (-- dig)
	{
		*str = (num / i) + '0';
		num %= i;
		str ++;
		i /= 10;
	}
	*str = num + '0';
	str ++;
	return (saved);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	size_t	dig;

	num = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	dig = get_digits(num);
	str = (char *)ft_calloc((dig + 1), sizeof(char));
	if (!str)
		return (NULL);
	return (get_char(str, num, dig));
}
