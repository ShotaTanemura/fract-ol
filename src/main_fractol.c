/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shtanemu <shtanemu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:47:31 by shtanemu          #+#    #+#             */
/*   Updated: 2023/01/30 01:47:31 by shtanemu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	**generate_param_sets(void)
{
	char	**param_sets;

	param_sets = (char **)malloc(sizeof(char *) * 3);
	if (!param_sets)
		exit(EXIT_FAILURE);
	param_sets[0] = (char *)ft_calloc(ft_strlen("julia") + 1, sizeof(char));
	if (!param_sets[0])
	{
		free(param_sets);
		exit(EXIT_FAILURE);
	}
	param_sets[1] = (char *)ft_calloc(ft_strlen("mandelbrot") + 1, sizeof(char));
	{
		ft_free(free_matrix(param_sets));
		exit(EXIT_FAILURE);
	}
	param_sets[0] = ft_strdup("julia");
	param_sets[1] = ft_strdup("mandelbrot");
	if (!param_sets[0] || !param_sets[1])
		return (NULL);
	param_sets[2] = NULL;
	return (param_sets);

}

void	validate_args(int argc, char **argv)
{
	char	**param_sets;
	size_t	i_param_sets;

	param_sets = generate_param_sets();
	if (2 == argc)
	{
		i_param_sets = 0;
		while (param_sets[i_param_sets])
		{
			if (!ft_strcmp(argv[1], param_sets[i_param_sets]))
				return (0);
			i_param_sets++;
		}
	}
	free_matrix()
	print_usage(param_sets);
}

void	main_fractol(int argc, char **argv)
{
	validate_args(argc, argv);
}
