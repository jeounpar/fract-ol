/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:55:42 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/19 20:55:46 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strcmp(const char *s1, const char *s2);
int		ft_atof_valid(const char *str);
double	ft_atof(const char *str);

static void	errors(void)
{
	printf("\t./fractol Mandelbrot\n\t./fractol Julia a(double) b(double)\n");
	printf("\t./fractol BurningShip\n");
	printf("\tJulia Set default value [a = 0.285, b = 0.01]\n");
	exit(1);
}

void	parse_command(int argc, char *argv[], t_mlx *data)
{
	double	a;
	double	b;

	if (argc < 2 || argc > 4)
		errors();
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0 && argc == 2)
		data->img.types = 1;
	else if (ft_strcmp(argv[1], "Julia") == 0 && (argc == 2 || argc == 4))
	{
		if (argc == 4)
		{
			if (ft_atof_valid(argv[2]) != 1 || ft_atof_valid(argv[3]) != 1)
				errors();
			a = ft_atof(argv[2]);
			b = ft_atof(argv[3]);
			data->img.julia_a = a;
			data->img.julia_b = b;
		}
		data->img.types = 2;
	}
	else if (ft_strcmp(argv[1], "BurningShip") == 0 && argc == 2)
		data->img.types = 3;
	else
		errors();
}