/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_matrix_row.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:12:37 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/07 22:18:33 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_cnt_matrix_row(char	**matrix)
{
	size_t	cnt_row;

	cnt_row = 0;
	while (matrix[cnt_row])
		cnt_row++;
	return (cnt_row);
}
