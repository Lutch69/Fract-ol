/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:46 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/23 15:28:23 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol_bonus <fractal_type> [parameters]\n", 2);
	ft_putstr_fd("Available fractals:\n\t\t   MANDELBROT\n\t\t   ", 2);
	ft_putstr_fd("JULIA [c_real] [c_imaginary]\n\t\t   TRICORN\n\t\t   ", 2);
	ft_putstr_fd("BURNINGSHIP\n\t\t   PHOENIX\n", 2);
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
	// mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	get_coordinate_tui(t_data *data, double c_re, double c_im)
{
	data->tui.c_re = ft_ftoa(c_re, 4);
	data->tui.c_im = ft_ftoa(c_im, 4);
}
