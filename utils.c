/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 21:44:58 by jeounpar          #+#    #+#             */
/*   Updated: 2022/02/19 00:07:50 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdlib.h>

size_t	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i] + 0);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i] + 0);
		i++;
	}
	return (0);
}

int	ft_atof_valid(const char *str)
{
	int	i;
	int	cnt;
	int	flag;

	i = 0;
	cnt = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'
			|| str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '.')
				cnt += 1;
			else if (str[i] == '+' || str[i] == '-')
				flag += 1;
			if (cnt > 2 || flag > 2)
				return (0);
		}
		else
			return (0);
		i += 1;
	}
	return (1);
}

static void	check_flag(const char *str, int *i, double *flag)
{
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*flag *= -1;
		*i += 1;
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	flag;
	double	cord;
	int		i;

	result = 0;
	flag = 1;
	i = 0;
	cord = 0.1;
	check_flag(str, &i, &flag);
	while (str[i] != '.')
	{
		result = result * (double)10 + (str[i] - '0');
		i += 1;
	}
	i += 1;
	while (str[i] != '\0')
	{
		result = result + ((double)(str[i] - '0')) * cord;
		cord *= 0.1;
		i += 1;
	}
	return (result * flag);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
