/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:40:46 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/16 14:15:18 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

// Fonction for Mandelbrot
void	is_mandelbrot(int ac, t_data *data)
{
	if (ac == 2)
	{
		data->tui.type = "Type : MANDELBROT";
		data->center_re = -0.05;
		data->center_im = 0.0;
		init_image(data);
		get_coordinate_tui(data, data->center_re, data->center_im);
		setup_re_im(data, 0);
		event_mlx(data);
	}
	else
		print_usage();
}

// The Mandelbrot algorithm calculates the square of the sum and adds c
int	iter_mandelbrot(t_data *data, double c_re, double c_im)
{
	t_complex	z;
	double		temp_re;
	double		temp_im;
	int			i;

	ft_memset(&z, 0, sizeof(z));
	i = 0;
	while (i < data->max_iter)
	{
		temp_re = (z.re * z.re - z.im * z.im);
		temp_im = (2 * z.re * z.im);
		z.re = temp_re + c_re;
		z.im = temp_im + c_im;
		if (z.re * z.re + z.im * z.im > 4.00)
			break ;
		i++;
	}
	return (i);
}
