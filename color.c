/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/29 10:15:40 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_image(t_data *data)
{
	data->img.ptr = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_color(t_color *color, int iter)
{
	ft_memset(color, 0, sizeof(color));
	color->R = (iter * 5) % 255;
	color->G = (iter * 10)% 255;
	color->B = (iter * 20)% 255;
}

int	put_color_to_pixel(t_data *data, int iter)
{
	t_color color;
	int	color;
	init_color(&color, iter);
	if (iter == MAX_ITER)
		return (0x00000000);
	else
		color = (int)(255.0 * iter / max_iter);
	my_mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, color);
}
