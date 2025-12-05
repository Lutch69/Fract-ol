/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:26:31 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/04 12:12:59 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Fonction d'évènement pour déplacement du curseur
int	mouse_move(int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}
// Definir les coordonnées complex et les ratio par rapport au curseur
void	mouse_to_complex(t_data *data)
{
	// printf ("mouse x = [%d]\n", data->mouse.x);
	// printf ("mouse y = [%d]\n", data->mouse.y);
	data->mouse.complex_x = data->view.min_re + data->mouse.x * (data->view.max_re - data->view.min_re) / (double)WIDTH;
	data->mouse.complex_y = data->view.max_im - data->mouse.y * (data->view.max_im - data->view.min_im) / (double)HEIGHT;
	data->mouse.ratio_x = (data->mouse.x - WIDTH / 2.0) / WIDTH;
	data->mouse.ratio_y = (data->mouse.y - HEIGHT / 2.0) / HEIGHT;
}
//Fonction d'évènement pour scroll
int	mouse_hook(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	t_data *data;

	data = (t_data *)param;
	mouse_to_complex(data);
	if (button == ON_MOUSEDOWN)
	{
		data->zoom *= 1.1;
		printf ("%f\n", data->zoom);
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
