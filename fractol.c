/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/27 15:32:21 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_data(t_data *data, t_complex *complex)
{
	ft_memset(data, 0, sizeof(data));
;	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x, data->y, "Fract-ol");
	data->center_re = 0.5;
	data->center_im = 0.0;
	data->real_range = 3.5;
}

int	main(void)
{
	t_data	data;
	t_complex number;


	setup_data(&data, &number);


}
