/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:30 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/16 14:14:55 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	palette_forest(t_data *data)
{
	data->palette.hue_start = 45;
	data->palette.hue_range = 135;
	data->palette.saturation = 0.7;
	data->palette.value = 0.85;
	data->tui.palette = "Palette : forest";
	data->tui.title_color = 0x0000FF88;
	data->tui.text_color = 0x0088FFAA;
}

void	palette_night(t_data *data)
{
	data->palette.hue_start = 220;
	data->palette.hue_range = 80;
	data->palette.saturation = 0.7;
	data->palette.value = 0.6;
	data->tui.palette = "Palette : night";
	data->tui.title_color = 0x008888FF;
	data->tui.text_color = 0x00AAAAFF;
}

void	palette_psychedelic(t_data *data)
{
	data->palette.hue_start = 0;
	data->palette.hue_range = 720;
	data->palette.saturation = 1.0;
	data->palette.value = 1.0;
	data->tui.palette = "Palette : psychedelic";
	data->tui.title_color = 0x00FFFFFF;
	data->tui.text_color = 0x00EEEEEE;
}

void	palette_grey(t_data *data)
{
	data->palette.hue_start = 0;
	data->palette.hue_range = 120;
	data->palette.saturation = 0.0;
	data->palette.value = 1.0;
	data->tui.palette = "Palette : grey";
	data->tui.title_color = 0x00FFFFFF;
	data->tui.text_color = 0x00BBBBBB;
}

void	palette_sunset(t_data *data)
{
	data->palette.hue_start = 340;
	data->palette.hue_range = 80;
	data->palette.saturation = 0.9;
	data->palette.value = 0.95;
	data->tui.palette = "Palette : sunset";
	data->tui.title_color = 0x00FF88AA;
	data->tui.text_color = 0x00FFBBCC;
}
