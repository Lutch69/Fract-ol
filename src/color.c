/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/16 14:13:40 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	init_color(t_color *color, int iter)
{
	ft_memset(color, 0, sizeof(color));
	color->r = (iter * 0) % 255;
	color->g = (iter * 5) % 128;
	color->b = (iter * 5) % 128;
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	put_color_to_pixel(int iter)
{
	t_color	color;
	int		color_pix;

	init_color(&color, iter);
	color_pix = (color.r << 16) | (color.g << 8) | color.b;
	return (color_pix);
}
