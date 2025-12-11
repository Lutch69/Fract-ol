/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:13:39 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/10 12:43:11 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	key_plusmin(t_data *data, int keycode)
{
	if (keycode == KEY_PLUS)
		data->julia.radius *= 1.2;
	else if (keycode == KEY_MIN)
		data->julia.radius *= 0.8;
}

void	key_r(t_data *data)
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

// Fonction de déplacement grace au flèches
void	define_view(t_data *data, int keycode)
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
	if (keycode == KEY_R && data->fractal_type == JULIA) // touche R a set avec linux
		data->julia.auto_rotate = !data->julia.auto_rotate;
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
// Fonction d'évènement pour touche appuyer
int	key_press(int keycode, void *param)
{
	t_data	*data;
	data = (t_data *)param;
	data->step = 0.1 / data->zoom;
	if (keycode == KEY_SPACE)
		change_palette(data);
	if (keycode == KEY_MIN || keycode == KEY_PLUS)
		key_plusmin(data, keycode);
	define_view(data, keycode);
	setup_re_im(data, 0);
	return (0);
}

