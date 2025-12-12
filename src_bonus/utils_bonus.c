/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:06:46 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/12 09:29:12 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [parameters]\nAvailable ", 2);
	ft_putstr_fd("fractals:\n\t\t   MANDELBROT\n\t\t   JULIA [c_real]", 2);
	ft_putstr_fd(" [c_imaginary]\n\t\t   TRICORN\n\t\t   BURNINGSHIP\n", 2);
	ft_putstr_fd("\t\t   PHOENIX\n", 2);
	exit(EXIT_FAILURE);
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
