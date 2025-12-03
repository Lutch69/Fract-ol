/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:26:31 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/03 09:23:10 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	mouse_move(int x, int y, void *param)
{
	t_data *data;

	data = (t_data *)param;
	data->mouse.x = x;
	data->mouse.y = y;
	return (0);
}

void	mouse_to_complex(t_data *data)
{
	data->mouse.complex_x = data->view.min_re + (data->mouse.x / WIDTH) * (data->view.max_re - data->view.min_re);
	data->mouse.complex_y = data->view.min_im - (data->mouse.y / HEIGHT) * (data->view.max_im - data->view.min_im);
	data->mouse.ratio_x = (data->mouse.x - WIDTH / 2.0) / WIDTH;
	data->mouse.ratio_y = (data->mouse.y - HEIGHT / 2.0) / HEIGHT;
}

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	t_data *data;
	data = (t_data *)param;

	mouse_to_complex(data);
	if (button == 4)
	{
		data->zoom *= 1.1;
		setup_re_im(data, 1);
	}
	else if (button == 5)
	{
		data->zoom /= 1.2;
		if (data->zoom < 0.1)
			data->zoom = 0.1;
		setup_re_im(data, 1);
	}
	return (0);
}
