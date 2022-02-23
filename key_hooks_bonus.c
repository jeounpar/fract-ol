/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:45:03 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/23 20:40:32 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>

void	draw_fractal(t_mlx *data);

static void	event_4(t_mlx *data, double mouse_x, double mouse_y)
{
	data->img.x_center += mouse_x * (1 - 1 / ZOOM);
	data->img.y_center += mouse_y * (1 - 1 / ZOOM);
	data->img.pixel_rate *= ZOOM;
	data->img.length /= ZOOM;
	data->img.max_iter += 5;
}

static void	event_5(t_mlx *data, double mouse_x, double mouse_y)
{
	data->img.x_center += mouse_x * (ZOOM - 1);
	data->img.y_center += mouse_y * (ZOOM - 1);
	data->img.pixel_rate /= ZOOM;
	data->img.length *= ZOOM;
	if (data->img.max_iter <= 50)
		data->img.max_iter = 50;
	else
		data->img.max_iter -= 5;
}

int	mouse_event(int event, int x, int y, t_mlx *data)
{
	double	mouse_x;
	double	mouse_y;

	if (event == 4 || event == 5 || event == 1)
	{
		mouse_x = x / data->img.pixel_rate - data->img.length / 2;
		mouse_y = y / data->img.pixel_rate - data->img.length / 2;
		if (event == 4)
			event_4(data, mouse_x, mouse_y);
		else if (event == 5)
			event_5(data, mouse_x, mouse_y);
		else
		{
			data->img.x_center += x / data->img.pixel_rate
				- data->img.length / 2;
			data->img.y_center += y / data->img.pixel_rate
				- data->img.length / 2;
		}
		draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (event);
}

void	reset_fractal(t_mlx *data)
{
	data->img.x_center = 0;
	data->img.y_center = 0;
	data->img.pixel_rate = 200;
	data->img.length = 4;
	data->img.max_iter = 50;
}

int	keyboard_event(int event, t_mlx *data)
{
	if (event == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (event == 15 || event == 18 || event == 19 || event == 20)
	{
		reset_fractal(data);
		if (event == 18)
			data->img.types = 1;
		else if (event == 19)
			data->img.types = 2;
		else if (event == 20)
			data->img.types = 3;
		draw_fractal(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	return (0);
}
