/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:44:52 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/19 16:21:41 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <math.h>

int	julia_set(double x_n, double y_n, double a, double b)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (x_n * x_n + y_n * y_n <= 4 && iter < MAX_ITER)
	{
		tmp = x_n * x_n - y_n * y_n + a;
		y_n = 2 * x_n * y_n + b;
		x_n = tmp;
		iter += 1;
	}
	return (iter);
}

int	mandelbrot_set(double a, double b)
{
	double	x_n;
	double	y_n;
	double	tmp;
	int		iter;

	x_n = a;
	y_n = b;
	iter = 0;
	while (x_n * x_n + y_n * y_n <= 4 && iter < MAX_ITER)
	{
		tmp = x_n * x_n - y_n * y_n + a;
		y_n = 2 * x_n * y_n + b;
		x_n = tmp;
		iter += 1;
	}
	return (iter);
}

int	burnigship_set(double x_n, double y_n)
{
	double	x;
	double	y;
	double	tmp;
	int		iter;

	x = x_n;
	y = y_n;
	iter = 0;
	while (x_n * x_n + y_n * y_n <= 4 && iter < MAX_ITER)
	{
		tmp = x_n * x_n - y_n * y_n + x;
		y_n = fabs(2 * x_n * y_n) + y;
		x_n = tmp;
		iter += 1;
	}
	return (iter);
}
