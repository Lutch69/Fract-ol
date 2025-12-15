/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:39:34 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/15 16:33:27 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	normalize_iteration(t_data *data, int iter);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// Fonction pour coloré les pixels par rapport au positionnement dans la fractal
int	put_color_to_pixel(t_data *data, int iter)
{
	int		color_pix;
	double	logari;

	if (data->flag_tui > 0 && data->x < data->tui.width_ui && data->y < HEIGHT
		/ 20)
		return (0x00000000);
	if (data->flag_tui > 0 && data->x < data->tui.width_ui && data->y < 330
		&& data->y > 280)
		return (0x00000000);
	else if (data->flag_tui > 0 && data->x < WIDTH / 5)
		return (0x00333333);
	else if (data->flag_tui > 0 && data->x < data->tui.width_ui
		&& data->y < HEIGHT - 50)
		return (0x00000000);
	else if (data->flag_tui > 0 && data->x < data->tui.width_ui + 5)
		return (0x00000000);
	else
	{
		logari = normalize_iteration(data, iter);
		color_pix = to_hsv(&data->palette, logari);
	}
	return (color_pix);
}

double	normalize_iteration(t_data *data, int iter)
{
	double	valeur_log;

	if (iter == 0)
		return (-1);
	valeur_log = log(iter + 1) / log(data->max_iter + 1);
	return (valeur_log);
}

// Fonction pour garder en mémoire la positions des pixels
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
