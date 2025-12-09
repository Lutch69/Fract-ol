/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:56:38 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/09 12:57:55 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void		rgb_converter(t_hsv *hsv, t_rgb *rgb);
static void		rgb_converter2(t_hsv *hsv, t_rgb *rgb);
static void		calcul_part(t_hsv *hsv, double h);
static int		hsv_to_rgb(t_hsv *hsv, double h, double s, double v);

int	to_hsv(t_color_palette *palette , double logari)
{
	double	h;
	double	s;
	double	v;
	int		gray;

	if (logari < 0)
		return (0x00000000);
	h = palette->hue_start + (logari * palette->hue_range); //parcourir le cercle chromatique
	s = palette->saturation;
	v = palette->value;

	if (s == 0)
	{
		gray = (int)(logari * 255);
		return(gray << 16 | gray << 8 | gray);
	}
	while (h >= 360.0)
		h -= 360.0;
	return (hsv_to_rgb(&palette->hsv, h, s, v));
}
static void	rgb_converter2(t_hsv *hsv, t_rgb *rgb)
{
	if (hsv->part == 3)
	{
		rgb->r = (hsv->v_min * 255);
		rgb->g = (hsv->v_decreasing * 255);
		rgb->b = (hsv->v_value * 255);
	}
	else if (hsv->part == 4)
	{
		rgb->r = (hsv->v_increasing * 255);
		rgb->g = (hsv->v_min * 255);
		rgb->b = (hsv->v_value * 255);
	}
	else if (hsv->part == 5)
	{
		rgb->r = (hsv->v_value * 255);
		rgb->g = (hsv->v_min * 255);
		rgb->b = (hsv->v_decreasing * 255);
	}
}

static void	rgb_converter(t_hsv *hsv, t_rgb *rgb)
{
	if (hsv->part == 0)
	{
		rgb->r = (hsv->v_value * 255);
		rgb->g = (hsv->v_increasing * 255);
		rgb->b = (hsv->v_min * 255);
	}
	else if (hsv->part == 1)
	{
		rgb->r = (hsv->v_decreasing * 255);
		rgb->g = (hsv->v_value * 255);
		rgb->b = (hsv->v_min * 255);
	}
	else if (hsv->part == 2)
	{
		rgb->r = (hsv->v_min * 255);
		rgb->g = (hsv->v_value * 255);
		rgb->b = (hsv->v_increasing * 255);
	}
	else
	rgb_converter2(hsv, rgb);
}



static void	calcul_part(t_hsv *hsv, double h)
{
	hsv->h_normalized = h / 60.0;
	hsv->part = (int)hsv->h_normalized;
	hsv->f_part = hsv->h_normalized - hsv->part;
}


static int	hsv_to_rgb(t_hsv *hsv, double h, double s, double v)
{
	// printf("INPUT: h=%.2f s=%.2f v=%.2f\n", h, s, v);
	calcul_part(hsv, h);
	hsv->v_value = v;
	hsv->v_min = v * (1.0 - s);
	hsv->v_decreasing = v * (1.0 -(hsv->f_part * s));
	hsv->v_increasing = v * (1 - ((1.0 - hsv->f_part) * s));
	// printf("PART: %d, h_normalized=%.2f, f_part=%.2f\n",
	// 		hsv->part, hsv->h_normalized, hsv->f_part);
	// printf("v_value=%.2f, v_min=%.2f, v_dec=%.2f, v_inc=%.2f\n",
	// 		hsv->v_value, hsv->v_min, hsv->v_decreasing, hsv->v_increasing);
	rgb_converter(hsv, &hsv->rgb);
	return (hsv->rgb.r << 16 | hsv->rgb.g << 8 | hsv->rgb.b);
}
