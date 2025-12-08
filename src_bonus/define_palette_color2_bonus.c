/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:30 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/08 17:57:20 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	palette_forest(t_color_palette *palette)
{
	palette->hue_start = 150;
	palette->hue_range = 60;
	palette->saturation = 0.5;
	palette->value = 0.9;
	printf("palette forest\n");
}

void	palette_night(t_color_palette *palette)
{
	palette->hue_start = 220;
	palette->hue_range = 60;
	palette->saturation = 1;
	palette->value = 1;
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
	palette->value = 0.1;
	printf("palette grey\n");
}
