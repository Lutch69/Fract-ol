/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/28 16:12:47 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	init_color(t_color *color)
// {
// 	color->R = 255;
// 	color->G = 255;
// 	color->B = 255;
// }

void	put_color_to_pixel(t_data *data, int iter)
{
	int	color;
	if (iter == MAX_ITER)
		color = 0x00000000;
	else
		color = 0x00FFFFFF;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, color);
}
