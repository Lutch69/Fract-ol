/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:22:14 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/11 21:08:59 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int		burningship_iter(double c_re, double c_im);
int		mandelbrot_iter(double c_re, double c_im);
int		julia_iter(double c_re, double c_im, double julia_re, double julia_im);
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
			if (data->fractal_type == MANDELBROT)
				iter = mandelbrot_iter(c.re, c.im);
			else if (data->fractal_type == JULIA)
				iter = julia_iter(c.re, c.im, data->julia.complex.re,
						data->julia.complex.im);
			else if (data->fractal_type == BURNINGSHIP)
				iter = burningship_iter(c.re, c.im);
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

// The Mandelbrot algorithm calculates the square of the sum and adds c
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
// Julia's algorithm calculates the square of the sum and adds the real and imaginary coordinates
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
int	burningship_iter(double c_re, double c_im)
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
			break;
		i++;
	}
	return (i);
}
