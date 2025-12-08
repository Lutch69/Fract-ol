/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:08:41 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/07 17:52:06 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	change_palette(t_data *data)
{
	data->palette.palette_id = (data->palette.palette_id + 1) % 7;
	if (data->palette.palette_id == 0)
		palette_rainbow(&data->palette);
	else if (data->palette.palette_id == 1)
		palette_cool(&data->palette);
	else if (data->palette.palette_id == 2)
		palette_warm(&data->palette);
	else if (data->palette.palette_id == 3)
		palette_forest(&data->palette);
	else if (data->palette.palette_id == 4)
		palette_night(&data->palette);
	else if (data->palette.palette_id == 5)
		palette_psychedelic(&data->palette);
	else
		palette_grey(&data->palette.palette_id);
}

void	palette_rainbow(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 360;
	palette->saturation = 1.0;
	palette->value = 1.0;
}
void	palette_cool(t_color_palette *palette)
{
	palette->hue_start = 180;
	palette->hue_range = 120;
	palette->saturation = 1.0;
	palette->value = 1.0;
}
void	palette_warm(t_color_palette *palette)
{
	palette->hue_start = 0;
	palette->hue_range = 60;
	palette->saturation = 1.0;
	palette->value = 1.0;
}
