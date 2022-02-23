/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:45:07 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/23 20:42:29 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "minilibx/mlx.h"

# define ZOOM 1.1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		types;
	int		max_iter;
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

typedef struct s_doubles
{
	double	a;
	double	b;
}	t_doubles;

#endif