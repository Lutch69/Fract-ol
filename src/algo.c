/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:22:14 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/16 14:13:53 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int		mandelbrot_iter(double c_re, double c_im);
int		julia_iter(double c_re, double c_im, double julia_re, double julia_im);
void	pixel_to_complex(t_complex *c, t_data *data);

int	render(t_data *data)
{
	t_complex	c;
	int			iter;
	int			color;

	data->x = 0;
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{
			pixel_to_complex(&c, data);
			if (data->fractal_type == MANDELBROT)
				iter = mandelbrot_iter(c.re, c.im);
			else if (data->fractal_type == JULIA)
				iter = julia_iter(c.re, c.im, data->julia.complex.re,
						data->julia.complex.im);
			color = put_color_to_pixel(iter);
			my_mlx_pixel_put(&data->img, data->x, data->y, color);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return (0);
}

void	pixel_to_complex(t_complex *c, t_data *data)
{
	ft_memset(c, 0, sizeof(*c));
	c->re = data->view.min_re + data->x * (data->view.max_re
			- data->view.min_re) / (double)WIDTH;
	c->im = data->view.max_im - data->y * (data->view.max_im
			- data->view.min_im) / (double)HEIGHT;
}

int	mandelbrot_iter(double c_re, double c_im)
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

int	julia_iter(double c_re, double c_im, double julia_re, double julia_im)
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
		z.re = temp_re + julia_re;
		z.im = temp_im + julia_im;
		if (z.re * z.re + z.im * z.im > 4.00)
			break ;
		i++;
	}
	return (i);
}
