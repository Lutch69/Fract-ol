/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/05 21:47:06 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [parameters]\nAvailable fractals:\n\t\t   mandelbrot\n\t\t   julia [c_real] [c_imaginary]\n"
	, 2);
	exit(EXIT_FAILURE);
}
// Close & free
int	close_prog(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	event_mlx(t_data *data)
{
	mlx_hook(data->win_ptr, ON_MOUSEMOVE, MOUSE_MASK, mouse_move, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_key_hook(data->win_ptr, key_press, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, close_prog, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	srand(time(NULL));
	t_data	data;

	if (ac < 2)
		print_usage();
	setup_data(&data, ac, av);
	if (define_fractale(ac, av, &data) == 1)
	{
		if (data.fractal_type == JULIA)
			is_julia(ac, av, &data);
		init_image(&data);
		setup_re_im(&data, 0);
		event_mlx(&data);
	}
	return (0);
}
