/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:57:09 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/23 20:42:16 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		julia_set(t_doubles d, double a, double b, t_mlx *data);
int		mandelbrot_set(t_doubles d, t_mlx *data);
int		burnigship_set(t_doubles d, t_mlx *data);

static int	types_of_set(t_mlx *data, double a, double b)
{
	t_doubles	d;

	d.a = data->img.x_center + a / data->img.pixel_rate - data->img.length / 2;
	d.b = data->img.y_center + b / data->img.pixel_rate - data->img.length / 2;
	if (data->img.types == 1)
		return (mandelbrot_set(d, data));
	else if (data->img.types == 2)
		return (julia_set(d, data->img.julia_a, data->img.julia_b, data));
	else if (data->img.types == 3)
		return (burnigship_set(d, data));
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
			if (iter == data->img.max_iter)
				my_mlx_pixel_put(&data->img, a, b, color_set(iter));
			else
				my_mlx_pixel_put(&data->img, a, b, color_set(iter));
			b += 1;
		}
		a += 1;
	}
}
