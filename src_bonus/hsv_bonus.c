/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:56:38 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/08 17:00:10 by ludebarn         ###   ########.fr       */
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

	h = palette->hue_start + (logari * palette->hue_range); //parcourir le cercle chromatique
	s = palette->saturation;
	v = palette->value;
	// gray = (int)(v * 255);
	// printf ("h = %f\n", h);
	// printf ("s = %f\n", s);
	// printf ("v = %f\n", v);
	// if (s == 0)
	// 	return(gray << 16 | gray << 8 | gray);
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
		rgb->b = (hsv->v_max);
	}
	else if (hsv->part == 4)
	{
		rgb->r = (hsv->v_increasing * 255);
		rgb->g = (hsv->v_min * 255);
		rgb->b = (hsv->v_max);
	}
	else if (hsv->part == 5)
	{
		rgb->r = (hsv->v_max * 255);
		rgb->g = (hsv->v_min * 255);
		rgb->b = (hsv->v_decreasing * 255);
	}
}

static void	rgb_converter(t_hsv *hsv, t_rgb *rgb)
{
	if (hsv->part == 0)
	{
		rgb->r = (hsv->v_max * 255);
		rgb->g = (hsv->v_increasing * 255);
		rgb->b = (hsv->v_min * 255);
	}
	else if (hsv->part == 1)
	{
		rgb->r = (hsv->v_decreasing * 255);
		rgb->g = (hsv->v_max * 255);
		rgb->b = (hsv->v_min * 255);
	}
	else if (hsv->part == 2)
	{
		rgb->r = (hsv->v_min * 255);
		rgb->g = (hsv->v_max * 255);
		rgb->b = (hsv->v_increasing * 255);
	}
	else
	rgb_converter2(hsv, rgb);
}



static void	calcul_part(t_hsv *hsv, double h)
{
	hsv->v_max = h / 60.0;
	hsv->part = (int)hsv->v_max;
	hsv->f_part = hsv->v_max - hsv->part;
}


static int	hsv_to_rgb(t_hsv *hsv, double h, double s, double v)
{
	calcul_part(hsv, h);
	hsv->v_min = v * (1.0 - s);
	hsv->v_decreasing = v * (1.0 -(hsv->f_part * 1));
	hsv->v_increasing = v * (1 - ((1.0 - hsv->f_part) * 1));
	// printf ("v_max = %f\n part = %d\nf_part = %f\n v_min = %f\nv_decreasing %f\nv_increasing = %f\n", hsv->v_decreasing, hsv->part, hsv->f_part, hsv->v_min, hsv->v_decreasing, hsv->v_increasing);
	rgb_converter(hsv, &hsv->rgb);
	// hsv->rgb.r = (hsv->rgb.float_r * 255);
	// hsv->rgb.g = (hsv->rgb.float_g * 255);
	// hsv->rgb.b = (hsv->rgb.float_b * 255);
	// printf ("r = %d\ng = %d\nb = %d\n", hsv->rgb.r, hsv->rgb.g, hsv->rgb.b);
	return (hsv->rgb.r << 16 | hsv->rgb.g << 8 | hsv->rgb.b);
}
