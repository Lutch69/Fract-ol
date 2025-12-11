/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:46 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/10 13:21:27 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [parameters]\nAvailable fractals:\n\t\t   mandelbrot\n\t\t   julia [c_real] [c_imaginary]\n"
	, 2);
	exit(EXIT_FAILURE);
}

// Rotate fractal julia stay with angle under 0 and 2pi and calcul new position de c on circle
void	rotate_julia(t_data *data)
{
	data->julia.angle += 0.015;
	if (data->julia.angle >= 2 * M_PI)
		data->julia.angle = 0;
	data->julia.complex.re = data->julia.center_re + data->julia.radius * cos(data->julia.angle);
	data->julia.complex.im = data->julia.center_im + data->julia.radius * sin(data->julia.angle);
}
void	is_burningship(int ac, t_data *data)
{
	if (ac == 2)
	{
		data->center_re = -1.75;
		data->center_im = -0.03;
		init_image(data);
		data->zoom *= 1.6;
		setup_re_im(data, 0);
		palette_warm(&data->palette);
		event_mlx(data);
	}
	else
		print_usage();
}

void	init_julia(t_data *data)
{
	data->julia.angle = 0;
	data->julia.radius = 0.08;
	data->julia.auto_rotate = 0;
	data->julia.center_re = data->julia.complex.re;
	data->julia.center_im = data->julia.complex.im;
}
// convert coordinate for julia
void	convert_julia(char **av, t_data *data)
{
	data->julia.complex.re = atof(av[2]); //ft_atof
	data->julia.complex.im = atof(av[3]);
	if (data->julia.complex.re > INT_MAX || data->julia.complex.re < INT_MIN)
	{
		printf("Invalid int : [%f]\n", data->julia.complex.re); //ft_printf
		print_usage();
	}
	if (data->julia.complex.im > INT_MAX || data->julia.complex.im < INT_MIN)
	{
		printf("Invalid int : [%f]\n", data->julia.complex.im);
		print_usage();
	}
}
// Close & free
int	close_prog(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
