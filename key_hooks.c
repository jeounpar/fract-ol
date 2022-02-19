/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:45:03 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/19 14:49:16 by jeounpar         ###   ########.fr       */
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
}

static void	event_5(t_mlx *data, double mouse_x, double mouse_y)
{
	data->img.x_center += mouse_x * (ZOOM - 1);
	data->img.y_center += mouse_y * (ZOOM - 1);
	data->img.pixel_rate /= ZOOM;
	data->img.length *= ZOOM;
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

int	keyboard_event(int event, t_mlx *data)
{
	if (event == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
