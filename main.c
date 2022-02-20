/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:44:36 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/20 18:11:55 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	parse_command(int argc, char *argv[], t_mlx *data);
int		mouse_event(int event, int x, int y, t_mlx *data);
int		keyboard_event(int event, t_mlx *data);
void	draw_fractal(t_mlx *data);

static void	init_imagedata(t_mlx *data)
{
	data->img.x_center = 0;
	data->img.y_center = 0;
	data->img.pixel_rate = 200;
	data->img.length = 4;
	data->img.julia_a = 0.285;
	data->img.julia_b = 0.01;
	data->img.types = 0;
}

static void	init_mlxdata(t_mlx *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 800, "Fractal");
	data->img.img = mlx_new_image(data->mlx, 800, 800);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

int	main(int argc, char *argv[])
{
	t_mlx	data;

	init_imagedata(&data);
	parse_command(argc, argv, &data);
	init_mlxdata(&data);
	draw_fractal(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, keyboard_event, &data);
	mlx_mouse_hook(data.win, mouse_event, &data);
	mlx_loop(data.mlx);
	return (0);
}
