/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:13:39 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/04 12:15:55 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Close et free le programme
int	close_prog(void *param)
{
	t_data *data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}
// Fonction de déplacement grace au flèches
void	define_view(t_data *data, int keycode)
{
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
	define_view(data, keycode);
	setup_re_im(data, 0);
	return (0);
}
