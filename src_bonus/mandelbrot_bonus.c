/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:40:46 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/11 22:22:13 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// Fonction for Mandelbrot
void	is_mandelbrot(int ac, t_data *data)
{
	if (ac == 2)
	{
		data->tui.type = "Type : MANDELBROT";
		data->center_re = -0.05;
		init_image(data);
		setup_re_im(data, 0);
		event_mlx(data);
	}
	else
		print_usage();
}

// The Mandelbrot algorithm calculates the square of the sum and adds c
int	iter_mandelbrot(double c_re, double c_im)
{
	t_complex	z;
	double		temp_re;
	double		temp_im;
	int			i;

	ft_memset(&z, 0, sizeof(z));
	i = 0;
	while (i < MAX_ITER)
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
