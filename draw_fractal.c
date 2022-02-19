/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:07:46 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/19 16:32:43 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		julia_set(double x_n, double y_n, double a, double b);
int		mandelbrot_set(double a, double b);
int		burnigship_set(double x_n, double y_n);

static int	types_of_set(t_mlx *data, double a, double b)
{
	if (data->img.types == 1)
		return (mandelbrot_set(data->img.x_center
				+ a / data->img.pixel_rate - data->img.length / 2,
				data->img.y_center + b / data->img.pixel_rate
				- data->img.length / 2));
	else if (data->img.types == 2)
		return (julia_set(data->img.x_center
				+ a / data->img.pixel_rate - data->img.length / 2,
				data->img.y_center + b / data->img.pixel_rate
				- data->img.length / 2, data->img.julia_a, data->img.julia_b));
	else if (data->img.types == 3)
		return (burnigship_set(data->img.x_center
				+ a / data->img.pixel_rate - data->img.length / 2,
				data->img.y_center + b / data->img.pixel_rate
				- data->img.length / 2));
	else
		return (0);
}

static int	color_set(int iter)
{
	int	r;
	int	g;
	int	b;
	int	color;

	r = iter << 11;
	g = iter << 7;
	b = iter << 3;
	color = r + g + b;
	return (color);
}

void	draw_fractal(t_mlx *data)
{
	double	a;
	double	b;
	int		iter;

	a = 0;
	while (a < 800)
	{
		b = 0;
		while (b < 800)
		{
			iter = types_of_set(data, a, b);
			if (iter == MAX_ITER)
				my_mlx_pixel_put(&data->img, a, b, color_set(iter));
			else
				my_mlx_pixel_put(&data->img, a, b, color_set(iter));
			b += 1;
		}
		a += 1;
	}
}
