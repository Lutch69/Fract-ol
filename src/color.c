/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/08 18:12:55 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Définitions des couleurs RGB
void	init_color(t_color *color, int iter)
{
	ft_memset(color, 0, sizeof(color));
	color->R = (iter * 0) % 255;
	color->G = (iter * 5) % 128;
	color->B = (iter * 5) % 128;
}
// Fonction pour garder en mémoire la positions des pixels
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Fonction pour coloré les pixels par rapport au positionnement dans la fractal
int	put_color_to_pixel(int iter)
{
	t_color	color;
	int		color_pix;

	init_color(&color, iter);
	color_pix = (color.R << 16) | (color.G << 8) | color.B;
	return (color_pix);
}
