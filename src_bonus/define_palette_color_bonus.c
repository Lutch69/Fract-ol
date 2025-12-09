/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:08:41 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/09 11:05:35 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	change_palette(t_data *data)
{
	data->palette_id = (data->palette_id + 1) % 9;
	if (data->palette_id == 0)
		palette_rainbow(&data->palette);
	else if (data->palette_id == 1)
		palette_cold(&data->palette);
	else if (data->palette_id == 2)
		palette_warm(&data->palette);
	else if (data->palette_id == 3)
		palette_forest(&data->palette);
	else if (data->palette_id == 4)
		palette_night(&data->palette);
	else if (data->palette_id == 5)
		palette_psychedelic(&data->palette);
	else if (data->palette_id == 6)
		palette_grey(&data->palette);
	else if (data->palette_id == 7)
		palette_ocean(&data->palette);
	else
		palette_sunset(&data->palette);
}

void	palette_rainbow(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 360;
	palette->saturation = 0.85;
	palette->value = 0.90;
	printf("palette rainbow\n");
}
void	palette_cold(t_color_palette *palette)
{
	palette->hue_start = 180;
	palette->hue_range = 120;
	palette->saturation = 1.0;
	palette->value = 1.0;
	printf("palette cold\n");
}
void	palette_warm(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 60;
	palette->saturation = 1.0;
	palette->value = 1.0;
	printf("palette warm\n");
}
void	palette_ocean(t_color_palette *palette)
{
	palette->hue_start = 180;
	palette->hue_range = 60;
	palette->saturation = 0.8;
	palette->value = 0.8;
	printf ("palette ocean\n");
}
