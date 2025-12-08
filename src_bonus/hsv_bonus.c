/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:56:38 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/07 18:07:33 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	to_hsv(t_color_palette *palette , double logari, int *color_pix)
{
	double	h;
	double	s;
	double	v;
	int		gray;

	h = palette->hue_start + (logari * palette->hue_range); //parcourir le cercle chromatique
	s = palette->saturation;
	v = palette->value;
	gray = (int)(v * 255);
	if (s == 0)
		return(gray << 16 | gray << 8 | gray);
	while (h >= 360.0)
		h -= 360.0;
	color_pix = hsv_to_rgb(h, s, v);
}
double	calcul_teinture(double h)
{
	double	h_temp;
	int		i;
	double	f;

	h_temp = h / 60.0;
	i = (int)h_temp;
	f = h_temp - i;
	return(f);
}


int	hsv_to_rgb(double h, double s, double v)
{
	int f;
	double	p;
	double	q;
	double	t;

	f = calcul_teinture(h);
	p = v * (1.0 - s);
	q = v * (1.0 -(f * s));
	t = v * (1 * - ((1.0 - f) * s));
}
