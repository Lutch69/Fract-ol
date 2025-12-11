/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:46:21 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/11 22:27:21 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// Fonction for BURNINGSHIP
void	is_burningship(int ac, t_data *data)
{
	if (ac == 2)
	{
		data->center_re = -1.75;
		data->center_im = -0.03;
		init_image(data);
		data->zoom *= 1.6;
		data->tui.type = "Type : BURNINGSHIP";
		setup_re_im(data, 0);
		palette_warm(data);
		event_mlx(data);
	}
	else
		print_usage();
}
// Calculate the coordinate real and imaginary for Burningship
int	iter_burningship(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	temp_re;
	int		i;

	z_re = 0.0;
	z_im = 0.0;
	i = 0;
	while (i < MAX_ITER)
	{
		z_re = fabs(z_re);
		z_im = fabs(z_im);
		temp_re = (z_re * z_re - z_im * z_im);
		z_im = 2.0 * z_re * z_im;
		z_re = temp_re;
		z_re += c_re;
		z_im += c_im;
		if (z_re * z_re + z_im * z_im > 4.0)
			break ;
		i++;
	}
	return (i);
}
