/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/29 13:46:12 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_color_to_pixel(t_data *data, int iter)
{
	t_color color;
	int	color_pix;
	init_color(&color, iter);
	if (iter == MAX_ITER)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, 0x00FFFFFF);
	else
	{
		color_pix = (color.R << 16) | (color.G << 8) | color.B;
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, color_pix);
	}
}
