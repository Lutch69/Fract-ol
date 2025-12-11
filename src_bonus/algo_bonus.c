/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:22:14 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/11 22:53:09 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	rotate_julia(t_data *data);
int		iter_fractal(t_data *data, t_complex *c);
void	pixel_to_complex(t_complex *c, t_data *data);

int	render(t_data *data)
{
	t_complex	c;
	int			iter;
	int			color;

	data->x = 0;
	if (data->julia.auto_rotate && data->fractal_type == JULIA)
		rotate_julia(data);
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{
			pixel_to_complex(&c, data);
			iter = iter_fractal(data, &c);
			color = put_color_to_pixel(data, iter);
			my_mlx_pixel_put(&data->img, data->x, data->y, color);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	if (data->flag_tui > 0)
		text_user_interface(data);
	return (0);
}

int	iter_fractal(t_data *data, t_complex *c)
{
	int	iter;

	if (data->fractal_type == MANDELBROT)
		iter = iter_mandelbrot(c->re, c->im);
	else if (data->fractal_type == JULIA)
		iter = iter_julia(c->re, c->im, data->julia.complex.re,
				data->julia.complex.im);
	else if (data->fractal_type == BURNINGSHIP)
		iter = iter_burningship(c->re, c->im);
	else
		iter = iter_tricorn(c->re, c->im);
	return (iter);
}
// Setting up complex coordinates
void	pixel_to_complex(t_complex *c, t_data *data)
{
	ft_memset(c, 0, sizeof(*c));
	c->re = data->view.min_re + data->x * (data->view.max_re
			- data->view.min_re) / (double)WIDTH;
	if (data->fractal_type == BURNINGSHIP)
		c->im = data->view.min_im + data->y * (data->view.max_im
				- data->view.min_im) / (double)HEIGHT;
	else
		c->im = data->view.max_im - data->y * (data->view.max_im
				- data->view.min_im) / (double)HEIGHT;
}
// Rotate fractal julia stay with angle under 0 and 2pi and calcul new position de c on circle
void	rotate_julia(t_data *data)
{
	data->julia.angle += 0.015;
	if (data->julia.angle >= 2 * M_PI)
		data->julia.angle = 0;
	data->julia.complex.re = data->julia.center_re + data->julia.radius
		* cos(data->julia.angle);
	data->julia.complex.im = data->julia.center_im + data->julia.radius
		* sin(data->julia.angle);
}
