/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:32:13 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/16 14:15:11 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

// If fractal is julia
void	is_julia(int ac, char **av, t_data *data)
{
	int	random_index;

	random_index = rand() % 5;
	if (ac == 2)
		random_julia(data, random_index);
	if (ac == 4 && check_float(av[2]) == 1 && check_float(av[3]) == 1)
		convert_julia(av, data);
	data->tui.type = "Type : JULIA";
	init_julia(data);
	init_image(data);
	get_coordinate_tui(data, data->julia.complex.re, data->julia.complex.im);
	setup_re_im(data, 0);
	event_mlx(data);
}

// Julia's algorithm calculates the square of the sum and adds
// the real and imaginary coordinates
int	iter_julia(t_data *data, double c_re, double c_im)
{
	t_complex	z;
	double		temp_re;
	double		temp_im;
	int			i;

	z.re = c_re;
	z.im = c_im;
	i = 0;
	while (i < data->max_iter)
	{
		temp_re = (z.re * z.re - z.im * z.im);
		temp_im = (2 * z.re * z.im);
		z.re = temp_re + data->julia.complex.re;
		z.im = temp_im + data->julia.complex.im;
		if (z.re * z.re + z.im * z.im > 4.00)
			break ;
		i++;
	}
	return (i);
}

// Convert coordinate from av
void	convert_julia(char **av, t_data *data)
{
	data->julia.complex.re = ft_atof(av[2]);
	data->julia.complex.im = ft_atof(av[3]);
	if (data->julia.complex.re > INT_MAX || data->julia.complex.re < INT_MIN)
	{
		ft_printf("Invalid int : [%.2f]\n", data->julia.complex.re);
		print_usage();
	}
	if (data->julia.complex.im > INT_MAX || data->julia.complex.im < INT_MIN)
	{
		ft_printf("Invalid int : [%.2f]\n", data->julia.complex.im);
		print_usage();
	}
}

// Take a random fractal with srand
void	random_julia(t_data *data, int random_index)
{
	if (random_index == 0)
	{
		data->julia.complex.re = -0.8;
		data->julia.complex.im = 0.156;
	}
	if (random_index == 1)
	{
		data->julia.complex.re = 0.285;
		data->julia.complex.im = 0.013;
	}
	if (random_index == 2)
	{
		data->julia.complex.re = -1.476;
		data->julia.complex.im = 0.00;
	}
	if (random_index == 3)
	{
		data->julia.complex.re = 0.4;
		data->julia.complex.im = 0.6;
	}
	if (random_index == 4)
	{
		data->julia.complex.re = -0.7;
		data->julia.complex.im = 0.2705;
	}
}

// Initialization julia's structure
void	init_julia(t_data *data)
{
	data->julia.angle = 0;
	data->julia.radius = 0.08;
	data->julia.auto_rotate = 0;
	data->julia.center_re = data->julia.complex.re;
	data->julia.center_im = data->julia.complex.im;
}
