/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/04 12:36:47 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	wrong_argc(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [parameters]\nAvailable fractals:\n    mandelbrot\n    julia [c_real] [c_imaginary]\n", 2);
	exit(EXIT_FAILURE);
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
	t_data	data;
	if (ac < 2)
		wrong_argc();
	setup_data(&data, ac, av);
	init_image(&data);
	setup_re_im(&data, 0);
	event_mlx(&data);
}
