/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/01 14:30:21 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		put_color_to_pixel(int iter)
{
	t_color color;
	int	color_pix;
	init_color(&color, iter);
	color_pix = (color.R << 16) | (color.G << 8) | color.B;
	return(color_pix);
}
