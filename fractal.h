/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:45:07 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/18 22:06:07 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "minilibx/mlx.h"

# define MAX_ITER 50
# define ZOOM 1.1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		types;
	double	x_center;
	double	y_center;
	double	length;
	double	pixel_rate;
	double	julia_a;
	double	julia_b;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_mlx;

#endif