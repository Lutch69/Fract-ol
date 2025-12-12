/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:01:23 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/12 14:25:15 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	init_phoenix(t_data *data);
void	random_phoenix(t_data *data, int random_index);

void	is_phoenix(int ac, t_data *data)
{
	if (ac == 2)
	{
		init_phoenix(data);
		init_image(data);
		setup_re_im(data, 0);
		event_mlx(data);
	}
	else
		print_usage();
}

int	iter_phoenix(double c_re, double c_im, t_data *data)
{
	double	z[4];
	double	temp_re;
	double	temp_im;
	int		i;

	z[0] = c_re;
	z[1] = c_im;
	z[2] = 0.0;
	z[3] = 0.0;
	i = 0;
	while (i < MAX_ITER)
	{
		temp_re = z[0];
		temp_im = z[1];
		z[0] = temp_re * temp_re - temp_im * temp_im + data->phoenix.c.re
			+ (data->phoenix.p.re * z[2] - data->phoenix.p.im * z[3]);
		z[1] = 2.0 * temp_re * temp_im + data->phoenix.c.im
			+ (data->phoenix.p.re * z[3] + data->phoenix.p.im * z[2]);
		if (z[0] * z[0] + z[1] * z[1] > 4.0)
			break ;
		z[2] = temp_re;
		z[3] = temp_im;
		i++;
	}
	return (i);
}

void	init_phoenix(t_data *data)
{
	int	random_index;

	random_index = rand() % 3;
	data->tui.type = "Type : PHOENIX";
	data->phoenix.angle = 0.0;
	data->phoenix.auto_rotate = 0;
	random_phoenix(data, random_index);
	data->phoenix.c.re = data->phoenix.center_re + data->phoenix.radius
		* cos(data->phoenix.angle);
	data->phoenix.c.im = data->phoenix.center_im + data->phoenix.radius
		* sin(data->phoenix.angle);
	data->center_re = 0.0;
	data->center_im = 0.0;
	get_coordinate_tui(data, data->phoenix.center_re,
		data->phoenix.center_im);
}

void	random_phoenix(t_data *data, int random_index)
{
	if (random_index == 0)
	{
		data->phoenix.center_re = 0.5667;
		data->phoenix.center_im = 0.0;
		data->phoenix.p.re = -0.5;
		data->phoenix.p.im = 0.667;
		data->phoenix.radius = 0.1;
	}
	if (random_index == 1)
	{
		data->phoenix.center_re = 0.2;
		data->phoenix.center_im = 0.0;
		data->phoenix.p.re = -0.6;
		data->phoenix.p.im = 0.2;
		data->phoenix.radius = 0.2;
	}
	if (random_index == 2)
	{
		data->phoenix.center_re = 0.00;
		data->phoenix.center_im = 0.0;
		data->phoenix.p.re = -0.5;
		data->phoenix.p.im = 0.4;
		data->phoenix.radius = 0.15;
	}
}

void	rotate_phoenix(t_data *data)
{
	data->phoenix.angle += 0.015;
	if (data->phoenix.angle >= 2 * M_PI)
		data->phoenix.angle = 0.0;
	data->phoenix.c.re = data->phoenix.center_re + data->phoenix.radius
		* cos(data->phoenix.angle);
	data->phoenix.c.im = data->phoenix.center_im + data->phoenix.radius
		* sin(data->phoenix.angle);
}
