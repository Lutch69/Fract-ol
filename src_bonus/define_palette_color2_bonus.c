/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:30 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/07 17:27:18 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	palette_forest(t_color_palette *palette)
{
	palette->hue_start = 60;
	palette->hue_range = 120;
	palette->saturation = 0.8;
	palette->value = 0.9;
}

void	palette_night(t_color_palette *palette)
{
	palette->hue_start = 220;
	palette->hue_range = 80;
	palette->saturation = 0.7;
	palette->value = 0.6;
}

void	palette_psychedelic(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 720;
	palette->saturation = 1.0;
	palette->value = 1.0;
}

void	palette_grey(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 0;
	palette->saturation = 0.0;
	palette->value = 1.0;
}
