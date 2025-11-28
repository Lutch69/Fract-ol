/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:15:09 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/28 16:04:21 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
