/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:19:19 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/15 16:12:35 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	is_tricorn(int ac, t_data *data)
{
	if (ac == 2)
	{
		data->tui.type = "Type : TRICORN";
		data->center_re = -0.05;
		data->center_im = 0.0;
		get_coordinate_tui(data, data->center_re, data->center_im);
		init_image(data);
		setup_re_im(data, 0);
		event_mlx(data);
	}
	else
		print_usage();
}

int	iter_tricorn(t_data *data, double c_re, double c_im)
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
		temp_im = -(2 * z.re * z.im);
		z.re = temp_re + c_re;
		z.im = temp_im + c_im;
		if (z.re * z.re + z.im * z.im > 4.00)
			break ;
		i++;
	}
	return (i);
}
