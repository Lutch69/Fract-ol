/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:46 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/16 14:12:59 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [parameters]\nAvailable ", 2);
	ft_putstr_fd("fractals:\n\t\t   MANDELBROT\n\t\t   JULIA [c_real] ", 2);
	ft_putstr_fd("[c_imaginary]\n", 2);
	exit(EXIT_FAILURE);
}

// convert coordinate for julia
void	convert_julia(char **av, t_data *data)
{
	data->julia.complex.re = atof(av[2]);
	data->julia.complex.im = atof(av[3]);
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

// Close & free
int	close_prog(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
