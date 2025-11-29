/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:28:12 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/29 13:37:18 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color(t_color *color, int iter)
{
	ft_memset(color, 0, sizeof(color));
	color->R = (iter * 5) % 255;
	color->G = (iter * 10)% 255;
	color->B = (iter * 20)% 255;
}

void init_image(t_data *data)
{
	data->img.ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

void	pixel_to_complex(t_complex *c, t_data *data)
{
	ft_memset(c, 0, sizeof(*c));
	c->re = data->view.min_re + data->x * (data->view.max_re - data->view.min_re) / (double)WIDTH;
	c->im = data->view.max_im - data->y * (data->view.max_im - data->view.min_im) / (double) HEIGHT;
}

void	setup_re_im(t_view *view, t_data *data)
{
	ft_memset(view, 0, sizeof(*view));

	view->real_range = 3.5;
	view->imag_range = view->real_range * (double)HEIGHT / (double)WIDTH; // == 3.5
	if (view->real_range == view->imag_range)
	{
		view->min_re = data->center_re - view->real_range / 2.00; // == -1.25
		view->max_re = data->center_re + view->real_range / 2.00; // == 2.25
		view->min_im = data->center_im - view->imag_range / 2.00; // == -1.75
		view->max_im = data->center_im + view->imag_range / 2.00; //  == 1.75
		data->view = *view;
	}
}
