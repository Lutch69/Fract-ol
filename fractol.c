/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/03 15:33:45 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		close_window(param);
	return (0);
}

int	main(void)
{
	t_data	data;

	setup_data(&data);
	init_image(&data);
	setup_re_im(&data, 0);
	mlx_hook(data.win_ptr, ON_MOUSEMOVE, 1L << 6, mouse_move, &data);
	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	mlx_key_hook(data.win_ptr, key_press, &data);
	mlx_hook(data.win_ptr, ON_DESTROY, 0, close_window, &data);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
}
