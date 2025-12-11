/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:26:31 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/10 12:44:59 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_button_release(int button, int x, int y, void *param)
{
	t_data *data;
	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 1)
		data->mouse.flag_drag = 0;
	return (0);
}

int	mouse_button_press(int x, int y, t_data *data)
{
	data->mouse.drag_start_x = x;
	data->mouse.drag_start_y = y;
	data->mouse.center_re_start = data->center_re;
	data->mouse.center_im_start = data->center_im;
	data->mouse.flag_drag = 1;
	data->mouse.motion_counter = 0;
	return (0);
}
// Fonction d'évènement pour déplacement du curseur
int	mouse_move(int x, int y, void *param)
{
	t_data	*data;

	// printf("x = %d\ny = %d\n", x, y);
	data = (t_data *)param;
	data->mouse.motion_counter++;
	if (data->mouse.flag_drag == 1 && (data->mouse.motion_counter % 2) == 0)
	{
		data->mouse.delta_x = x - data->mouse.drag_start_x;
		data->mouse.delta_y = y - data->mouse.drag_start_y;
		data->view.deplacement_re = (data->mouse.delta_x / (double)WIDTH) * data->view.real_range;
		data->view.deplacement_im = -(data->mouse.delta_y / (double)HEIGHT) * data->view.imag_range;
		data->center_re = data->mouse.center_re_start - data->view.deplacement_re;
		data->center_im = data->mouse.center_im_start - data->view.deplacement_im;
		setup_re_im(data, 0);
	}
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}
// Definir les coordonnées complex et les ratio par rapport au curseur
void	mouse_to_complex(t_data *data)
{
	data->mouse.complex_x = data->view.min_re + data->mouse.x
		* (data->view.max_re - data->view.min_re) / (double)WIDTH;
	data->mouse.complex_y = data->view.max_im - data->mouse.y
		* (data->view.max_im - data->view.min_im) / (double)HEIGHT;
	data->mouse.ratio_x = (data->mouse.x - WIDTH / 2.0) / WIDTH;
	data->mouse.ratio_y = (data->mouse.y - HEIGHT / 2.0) / HEIGHT;
}
// Fonction d'évènement pour scroll
int	mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
		mouse_button_press(x, y, data);
	else
		mouse_to_complex(data);
	if (button == ON_MOUSEDOWN)
	{
		data->zoom *= 1.1;
		setup_re_im(data, 1);
	}
	else if (button == ON_MOUSEUP)
	{
		data->zoom /= 1.2;
		if (data->zoom < 0.1)
			data->zoom = 0.1;
		setup_re_im(data, 1);
	}
	return (0);
}
