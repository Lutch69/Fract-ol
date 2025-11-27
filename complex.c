/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:15:09 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/27 16:23:42 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_complex(t_complex *complex)
{

}

void	setup_complex(t_complex *c, t_data *data)
{
	ft_memset(c, 0, sizeof(c));
	c->imag_range = data->real_range * (double)HEIGHT / (double)WIDTH; // == 3.5
	c->min_re = data->center_re - data->real_range / 2.00; // == -1.25
	c->max_re = data->center_re + data->real_range / 2.00; // == 2.25
	c->min_im = data->center_im - c->imag_range / 2.00; // == -1.75
	c->max_im = data->center_im + c->imag_range / 2.00; //  == 1.75
	c->re = c->min_re + data->x * (c->max_re - c->min_re) / (double)WIDTH; // == -1.25
	c->im = c->max_im - data->y * (c->max_im - c->min_im) / (double) HEIGHT; // == 1.75
}
