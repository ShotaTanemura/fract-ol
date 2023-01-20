/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:22:21 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/05 20:27:24 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char	*dst_str, char *src_str)
{
	char	*joined_str;

	joined_str = ft_strjoin(dst_str, src_str);
	free(dst_str);
	return (joined_str);
}
