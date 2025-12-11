/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:13:39 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/10 10:27:28 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	printf("%d\n", keycode);
	data->step = 0.1 / data->zoom;
	define_view(data, keycode);
	setup_re_im(data, 0);
	return (0);
}
