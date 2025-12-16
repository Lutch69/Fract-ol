/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:28:12 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/16 15:14:10 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	init_image(t_data *data)
{
	ft_memset(&data->img, 0, sizeof(&data->img));
	data->palette_id = 0;
	data->zoom = 1.00;
	data->max_iter = 100;
	data->flag_tui = 1;
	data->tui.width_ui = WIDTH / 5;
	change_palette(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	data->img.ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

void	range_setup(t_data *data)
{
	data->view.real_range = 3.5 / data->zoom;
	data->view.imag_range = data->view.real_range * (double)HEIGHT
		/ (double)WIDTH;
}

void	setup_re_im(t_data *data, int flag)
{
	range_setup(data);
	if (flag == 1)
		setup_center(data);
	data->view.min_re = data->center_re - data->view.real_range / 2.00;
	data->view.max_re = data->center_re + data->view.real_range / 2.00;
	data->view.min_im = data->center_im - data->view.imag_range / 2.00;
	data->view.max_im = data->center_im + data->view.imag_range / 2.00;
}

void	setup_center(t_data *data)
{
	data->center_re = data->mouse.complex_x - (data->mouse.ratio_x
			* data->view.real_range);
	data->center_im = data->mouse.complex_y + (data->mouse.ratio_y
			* data->view.imag_range);
}

void	event_mlx(t_data *data)
{
	mlx_hook(data->win_ptr, ON_MOUSEDOWN, 1L << 2, mouse_hook, data);
	mlx_hook(data->win_ptr, ON_MOUSEUP, 1L << 3,
		mouse_button_release, data);
	mlx_hook(data->win_ptr, ON_MOUSEMOVE, 1L << 6, mouse_move, data);
	mlx_hook(data->win_ptr, KEY_PRESS, 1L << 0, key_press, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, close_prog, data);
	mlx_loop_hook(data->mlx_ptr, render, data);
	mlx_loop(data->mlx_ptr);
}
