/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:13:39 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/15 16:25:57 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// Fonction d'évènement pour touche appuyer
int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->step = 0.1 / data->zoom;
	if (keycode == KEY_P)
		change_palette(data);
	if (keycode == KEY_SPACE)
		data->flag_tui *= -1;
	if (keycode == KEY_MIN || keycode == KEY_PLUS)
		key_plusmin(data, keycode);
	if (keycode == KEY_Q)
		data->max_iter += 50;
	if (keycode == KEY_A)
		data->max_iter -= 50;
	define_keypress(data, keycode);
	setup_re_im(data, 0);
	return (0);
}

void	key_plusmin(t_data *data, int keycode)
{
	if (data->fractal_type == JULIA)
	{
		if (keycode == KEY_PLUS)
			data->julia.radius *= 1.2;
		else if (keycode == KEY_MIN)
			data->julia.radius *= 0.8;
	}
	if (data->fractal_type == PHOENIX)
	{
		if (keycode == KEY_PLUS)
			data->phoenix.radius *= 1.2;
		else if (keycode == KEY_MIN)
			data->phoenix.radius *= 0.8;
	}
}

void	key_r(t_data *data)
{
	if (data->fractal_type == JULIA)
	{
		data->julia.auto_rotate = !data->julia.auto_rotate;
		if (data->julia.auto_rotate)
		{
			data->center_re = 0.0;
			data->center_im = 0.0;
			data->zoom = 1.0;
			setup_re_im(data, 0);
		}
	}
	if (data->fractal_type == PHOENIX)
	{
		data->phoenix.auto_rotate = !data->phoenix.auto_rotate;
		if (data->phoenix.auto_rotate)
		{
			data->center_re = 0.0;
			data->center_im = 0.0;
			data->zoom = 1.0;
			setup_re_im(data, 0);
		}
	}
}

void	define_keypress(t_data *data, int keycode)
{
	if (keycode == KEY_W)
	{
		data->zoom *= 1.1;
		setup_re_im(data, 0);
	}
	else if (keycode == KEY_S)
	{
		data->zoom /= 1.2;
		if (data->zoom < 0.1)
			data->zoom = 0.1;
		setup_re_im(data, 0);
	}
	if (keycode == KEY_R)
		key_r(data);
	if (keycode == KEY_LEFT)
		data->center_re -= data->step;
	if (keycode == KEY_RIGHT)
		data->center_re += data->step;
	if (keycode == KEY_UP)
		data->center_im += data->step;
	if (keycode == KEY_DOWN)
		data->center_im -= data->step;
	if (keycode == KEY_ESC)
		close_prog(data);
}
