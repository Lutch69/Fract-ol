/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:46 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/15 17:03:30 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol_bonus <fractal_type> [parameters]\n", 2);
	ft_putstr_fd("Available fractals:\n\t\t   MANDELBROT\n\t\t   JULIA [c_real]", 2);
	ft_putstr_fd(" [c_imaginary]\n\t\t   TRICORN\n\t\t   BURNINGSHIP\n", 2);
	ft_putstr_fd("\t\t   PHOENIX\n", 2);
	exit(EXIT_FAILURE);
}

// Close & free
int	close_prog(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free(data->tui.c_re);
	free(data->tui.c_im);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	get_coordinate_tui(t_data *data, double c_re, double c_im)
{
	data->tui.c_re = ft_ftoa(c_re, 2);
	data->tui.c_im = ft_ftoa(c_im, 2);
}
