/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:08:41 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/11 21:05:15 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	change_palette(t_data *data)
{
	data->palette_id = (data->palette_id + 1) % 9;
	if (data->palette_id == 0)
		palette_rainbow(data);
	else if (data->palette_id == 1)
		palette_cold(data);
	else if (data->palette_id == 2)
		palette_warm(data);
	else if (data->palette_id == 3)
		palette_forest(data);
	else if (data->palette_id == 4)
		palette_night(data);
	else if (data->palette_id == 5)
		palette_psychedelic(data);
	else if (data->palette_id == 6)
		palette_grey(data);
	else if (data->palette_id == 7)
		palette_ocean(data);
	else
		palette_sunset(data);
}

void	palette_rainbow(t_data *data)
{
	data->palette.hue_start = 0;
	data->palette.hue_range = 360;
	data->palette.saturation = 0.85;
	data->palette.value = 0.90;
	data->tui.palette = "Palette : rainbow";
	data->tui.title_color = 0x00FFFFFF;
	data->tui.text_color = 0x00CCCCCC;
}
void	palette_cold(t_data *data)
{
	data->palette.hue_start = 180;
	data->palette.hue_range = 120;
	data->palette.saturation = 1.0;
	data->palette.value = 1.0;
	data->tui.palette = "Palette : cold";
	data->tui.title_color = 0x0000FFFF;
	data->tui.text_color = 0x0088CCFF;
}
void	palette_warm(t_data *data)
{
	data->palette.hue_start = 0;
	data->palette.hue_range = 60;
	data->palette.saturation = 1.0;
	data->palette.value = 1.0;
	data->tui.palette = "Palette : warm";
	data->tui.title_color = 0x00FFAA00;
	data->tui.text_color = 0x00FFDD88;
}

void	palette_ocean(t_data *data)
{
	data->palette.hue_start = 180;
	data->palette.hue_range = 60;
	data->palette.saturation = 0.8;
	data->palette.value = 0.8;
	data->tui.palette = "Palette : ocean";
	data->tui.title_color = 0x0000DDFF;
	data->tui.text_color = 0x0088DDFF;
}
