/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:28:12 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/05 22:15:12 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// Initialisation des pointeurs pour la creation d'image
void	init_image(t_data *data)
{
	ft_memset(&data->img, 0, sizeof(&data->img));
	data->img.ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
}

// Nouveau setup dans du range de l'image par rapport au zoom
void	range_setup(t_data *data)
{
	data->view.real_range = 3.5 / data->zoom;
	data->view.imag_range = data->view.real_range * (double)HEIGHT
		/ (double)WIDTH;
}

// Setup des limites imaginaire et réel pour le positionement dans la fractale
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

// Setup du centre imaginaire et réel
void	setup_center(t_data *data)
{
	data->center_re = data->mouse.complex_x - (data->mouse.ratio_x
			* data->view.real_range);
	data->center_im = data->mouse.complex_y + (data->mouse.ratio_y
			* data->view.imag_range);
}

// Initialisation de la data
void	setup_data(t_data *data, int ac, char **av)
{
	ft_memset(data, 0, sizeof(data));
	data->ac = ac;
	data->av = av;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	data->zoom = 1.00;
	data->center_im = 0.00;
}
