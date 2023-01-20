/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:59:06 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/13 16:59:06 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_free(char *s1, char const *set)
{
	char	*trimed_str;

	trimed_str = ft_strtrim(s1, set);
	free(s1);
	return (trimed_str);
}
