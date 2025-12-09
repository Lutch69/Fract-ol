/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/09 13:01:52 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// int	low_iter(double iter)
// {
// 	if (iter == 0)
// 		return(0x00000000);
// 	else if (iter == 1)
// 		return(0x00111111);
// 	else if (iter == 2)
// 		return(0x00222222);
// 	else if (iter == 3)
// 		return (0x00333333);
// 	else if (iter == 4)
// 		return(0x00444444);
// 	else
// 		return(0x00555555);
// }
double	normalize_iteration(int iter)
{
	double	valeur_log;
	if (iter == MAX_ITER)
		return(-1);
	valeur_log = log(iter + 1) / log(MAX_ITER + 1);
	return(valeur_log);
}

// Fonction pour garder en mémoire la positions des pixels
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Fonction pour coloré les pixels par rapport au positionnement dans la fractal
int	put_color_to_pixel(t_data *data, int iter)
{
	int		color_pix;
	double	logari;

	logari = normalize_iteration(iter);
	color_pix = to_hsv(&data->palette, logari);
	return (color_pix);
}
