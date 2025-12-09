/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:30 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/09 11:05:13 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	palette_forest(t_color_palette *palette)
{
	palette->hue_start = 45;
	palette->hue_range = 135;
	palette->saturation = 0.7;
	palette->value = 0.85;
	printf("palette forest\n");
}

void	palette_night(t_color_palette *palette)
{
	palette->hue_start = 220;
	palette->hue_range = 80;
	palette->saturation = 0.7;
	palette->value = 0.6;
	printf ("palette night\n");
}

void	palette_psychedelic(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 720;
	palette->saturation = 1.0;
	palette->value = 1.0;
	printf ("palette psychedelic\n");
}

void	palette_grey(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 120;
	palette->saturation = 0.0;
	palette->value = 1.0;
	printf("palette grey\n");
}

void	palette_sunset(t_color_palette *palette)
{
	palette->hue_start = 340;
	palette->hue_range = 80;
	palette->saturation = 0.9;
	palette->value = 0.95;
	printf ("palette sunset\n");
}

