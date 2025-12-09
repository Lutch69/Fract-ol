/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:24:09 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/09 12:41:32 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	check_float(char *av)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
		i++;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i])
	{
		if (!(ft_isdigit(av[i]) == 1 || av[i] == '.'))
			print_usage();
		if (av[i] == '.')
			comma++;
		if (comma > 1)
			print_usage();
		i++;
	}
	if (av[i] == '\0')
		return (1);
	else
		return (0);
}

int	define_fractale(int ac, char **av, t_data *data)
{
	if (ac == 2 || ac == 4)
	{
		if (((ft_strncmp(av[1], "MANDELBROT", 11)) == 0) || ft_strncmp(av[1],
				"Mandelbrot", 11) == 0 || ft_strncmp(av[1], "mandelbrot",
				11) == 0)
		{
			data->fractal_type = MANDELBROT;
			data->center_re = -0.5;
			return (1);
		}
		else if (((ft_strncmp(av[1], "Julia", 6)) == 0) || ft_strncmp(av[1],
				"JULIA", 6) == 0 || ft_strncmp(av[1], "julia", 6) == 0)
		{
			data->fractal_type = JULIA;
			data->center_re = 0.0;
			return (1);
		}
		else
		{
			printf("Error: Unknown fractal type '%s'\n", av[1]);
			print_usage();
		}
	}
	return (0);
}
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

void	is_julia(int ac, char **av, t_data *data)
{
	int	random_index;

	random_index = rand() % 5;
	if (ac == 2)
	{

		random_julia(data, random_index);
		// A changer en ft_printf
		printf("c_real = [%f]\nc_imaginary = [%f]\n",data->julia.complex.re, data->julia.complex.im);
	}
	if (ac == 4 && check_float(av[2]) == 1 && check_float(av[3]) == 1)
		convert_julia(av, data);
	init_julia(data);
	init_image(data);
	setup_re_im(data, 0);
	event_mlx(data);
}

void	is_mandelbrot(int ac, t_data *data)
{
	if (ac == 2)
	{
		init_image(data);
		setup_re_im(data, 0);
		event_mlx(data);
	}
	else
		print_usage();
}
