/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:44:52 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/23 20:31:37 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia_set(t_doubles d, double a, double b, t_mlx *data)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (d.a * d.a + d.b * d.b <= 4 && iter < data->img.max_iter)
	{
		tmp = d.a * d.a - d.b * d.b + a;
		d.b = 2 * d.a * d.b + b;
		d.a = tmp;
		iter += 1;
	}
	return (iter);
}

int	mandelbrot_set(t_doubles d, t_mlx *data)
{
	double	x_n;
	double	y_n;
	double	tmp;
	int		iter;

	x_n = d.a;
	y_n = d.b;
	iter = 0;
	while (x_n * x_n + y_n * y_n <= 4 && iter < data->img.max_iter)
	{
		tmp = x_n * x_n - y_n * y_n + d.a;
		y_n = 2 * x_n * y_n + d.b;
		x_n = tmp;
		iter += 1;
	}
	return (iter);
}
