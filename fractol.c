/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/28 08:20:39 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_data(t_data *data)
{
	ft_memset(data, 0, sizeof(data));
;	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x, data->y, "Fract-ol");
	data->center_re = 0.5;
	data->center_im = 0.0;
}

int	main(void)
{
	t_data	data;
	t_view view;

	setup_data(&data);
}
