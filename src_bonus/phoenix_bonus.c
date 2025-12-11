/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:01:23 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/11 23:30:47 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	is_phoenix(t_data *data)
{
	init_phoenix(data);
}

int	iter_phoenix(double c_re, double c_im, double phoenix_re, double phoenix_im)
{
	t_complex	z;
	double		temp_re;
	double		temp_im;
	int			i;

	z.re = c_re;
	z.im = c_im;
	i = 0;
	while (i < MAX_ITER)
	{
		temp_re = (z.re * z.re - z.im * z.im);
		temp_im = (2 * z.re * z.im);
		z.re = temp_re + phoenix_re;
		z.im = temp_im + phoenix_im;
		if (z.re * z.re + z.im * z.im > 4.00)
			break ;
		i++;
	}
	return (i);
}

void	init_phoenix(t_data *data)
{
	int	random_index;

	random_index = rand() % 5;
	data->center_re = 0.0;
	data->center_im = 0.0;
	data->phoenix.c.re = 0.3;
	data->phoenix.c.im = 0.0;
	data->phoenix.radius = 0.3;
	data->phoenix.angle = 0.0;
	data->phoenix.p.re = -0.5;
	data->phoenix.p.im = 0.0;
	random_phoenix(data, random_index);
}
void	random_phoenix(t_data *data, int random_index)
{
	if (random_index == 0)
	{
		data->phoenix.c.re = 0.56667;
		data->phoenix.c.im = 0.0;
		data->phoenix.p.re = -0.5;
		data->phoenix.p.im = 0.0;
	}
	if (random_index == 1)
	{
		data->phoenix.c.re = 0.2884;
		data->phoenix.c.im = -0.0113;
		data->phoenix.p.re = -0.5;
		data->phoenix.p.im = 0.0;
	}
	if (random_index == 2)
	{
		data->phoenix.c.re = 0.00;
		data->phoenix.c.im = 0.0;
		data->phoenix.p.re = -0.5;
		data->phoenix.p.im = 0.3;
	}
	if (random_index == 3)
	{
		data->phoenix.c.re = 0.4;
		data->phoenix.c.im = 0.0;
		data->phoenix.p.re = -0.6;
		data->phoenix.p.im = 0.0;
	}
}

void	rotate_phoenix(t_data *data)
{
	// Incrémenter l'angle de c
	data->phoenix.angle += 0.015; // Même vitesse que Julia
	if (data->phoenix.angle >= 2 * M_PI)
		data->phoenix.angle = 0.0;
	// Calculer nouvelle position de c
	data->phoenix.c.re = data->phoenix.center_re + data->phoenix.radius
		* cos(data->phoenix.angle);
	data->phoenix.c.im = data->phoenix.center_im + data->phoenix.radius
		* sin(data->phoenix.angle);
	// Si tu veux aussi faire tourner p (optionnel)
	data->phoenix.angle_p += 0.01;
	if (data->phoenix.angle_p >= 2 * M_PI)
		data->phoenix.angle_p = 0.0;
	data->phoenix.p.re = data->phoenix.center_p_re + data->phoenix.radius_p
		* cos(data->phoenix.angle_p);
	data->phoenix.p.im = data->phoenix.center_p_im + data->phoenix.radius_p
		* sin(data->phoenix.angle_p);
}
