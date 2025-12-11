/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_palette_color2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:19:30 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/11 13:35:56 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	palette_forest(t_data *data)
{
	data->palette.hue_start = 45;
	data->palette.hue_range = 135;
	data->palette.saturation = 0.7;
	data->palette.value = 0.85;
	data->tui.palette = "Palette : forest";
}

void	palette_night(t_data *data)
{
	data->palette.hue_start = 220;
	data->palette.hue_range = 80;
	data->palette.saturation = 0.7;
	data->palette.value = 0.6;
	data->tui.palette = "Palette : night";
}

void	palette_psychedelic(t_data *data)
{
	data->palette.hue_start = 0;
	data->palette.hue_range = 720;
	data->palette.saturation = 1.0;
	data->palette.value = 1.0;
	data->tui.palette = "Palette : psychedelic";
}

void	palette_grey(t_data *data)
{
	data->palette.hue_start = 0;
	data->palette.hue_range = 120;
	data->palette.saturation = 0.0;
	data->palette.value = 1.0;
	data->tui.palette = "Palette : grey";
}

void	palette_sunset(t_data *data)
{
	data->palette.hue_start = 340;
	data->palette.hue_range = 80;
	data->palette.saturation = 0.9;
	data->palette.value = 0.95;
	data->tui.palette = "Palette : sunset";
}

