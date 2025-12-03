/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:28:12 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/03 17:57:54 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color(t_color *color, int iter)
{
	ft_memset(color, 0, sizeof(color));
	color->R = (iter * 50) % 255;
	color->G = (iter * 5) % 128;
	color->B = (iter * 5) % 128;
}

void init_image(t_data *data)
{
	ft_memset(&data->img, 0, sizeof(&data->img));
	data->img.ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

//setup les pixel en coordonnees complex
void	pixel_to_complex(t_complex *c, t_data *data)
{
	ft_memset(c, 0, sizeof(*c));
	c->re = data->view.min_re + data->x * (data->view.max_re - data->view.min_re) / (double)WIDTH;
	c->im = data->view.max_im - data->y * (data->view.max_im - data->view.min_im) / (double) HEIGHT;
}

//nouveau setup dans du range de l'image par rapport au zoom
void	range_setup (t_data *data)
{
	data->view.real_range = 3.5 / data->zoom;
	data->view.imag_range = data->view.real_range * (double)HEIGHT / (double)WIDTH;
}

//setup la range de la fractale
void	setup_re_im(t_data *data, int flag)
{
	range_setup(data);
	if (flag == 1)
		setup_center(data); // re setup le centre im et re par rapport a l'index du curseur
	data->view.min_re = data->center_re - data->view.real_range / 2.00;
	data->view.max_re = data->center_re + data->view.real_range / 2.00;
	data->view.min_im = data->center_im - data->view.imag_range / 2.00;
	data->view.max_im = data->center_im + data->view.imag_range / 2.00;
}
void setup_center(t_data *data)
{
	printf("AVANT: center_re = %f, center_im = %f\n", data->center_re, data->center_im);
	printf("complex_x = %f, complex_y = %f\n", data->mouse.complex_x, data->mouse.complex_y);
	printf("ratio_x = %f, ratio_y = %f\n", data->mouse.ratio_x, data->mouse.ratio_y);
	printf("range: real = %f, imag = %f\n", data->view.real_range, data->view.imag_range);
	data->center_re = data->mouse.complex_x - (data->mouse.ratio_x * data->view.real_range);
	data->center_im = data->mouse.complex_y + (data->mouse.ratio_y * data->view.imag_range);
	printf("APRES: center_re = %f, center_im = %f\n\n", data->center_re, data->center_im);
}

void	setup_data(t_data *data)
{
	ft_memset(data, 0, sizeof(data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	data->zoom = 1.00;
	data->center_re = -0.5;
	data->center_im = 0.00;
}
