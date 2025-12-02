/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/02 15:37:12 by ludebarn         ###   ########.fr       */
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
	printf ("%d\n", keycode);
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
	render(&data);
	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	mlx_hook(data.win_ptr, 6, 0, mouse_move, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, NULL);
	printf ("mouse x = %d\nmouse y = %d\n", data.mouse.x, data.mouse.y);
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
}
