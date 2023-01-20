/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:04:41 by shtanemu          #+#    #+#             */
/*   Updated: 2022/10/12 12:04:41 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_num(long long num, int neg, char str)
{
	if (LONG_MAX / 10 < num * neg && str != '\0')
		return (1);
	if (LONG_MAX / 10 == num * neg && str > '7')
		return (1);
	if (LONG_MIN / 10 > num * neg && str != '\0')
		return (-1);
	if (LONG_MIN / 10 == num * neg && str > '8')
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			neg;

	num = 0;
	neg = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str ++;
	}
	while (ft_isdigit(*str))
	{
		num = (*(str) - '0') + (num * 10);
		str++;
		if (check_num(num, neg, *str) == 1)
			return ((int)LONG_MAX);
		if (check_num(num, neg, *str) == -1)
			return ((int)LONG_MIN);
	}
	return (num * neg);
}
