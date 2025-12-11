/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:13:29 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/11 22:45:28 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

// void	get_zoom(t_data *data)
// {
// 	char	*temp;

// 	temp = ftoa(data->zoom);
// 	data->tui.zoom = ft_strjoin("zoom : x", temp);
// 	free(temp);
// }

void	text_user_interface(t_data *data)
{
	int	y;
	int	x;

	y = HEIGHT / 32;
	x = WIDTH / 15;
	// get_zoom(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, data->tui.title_color,
		"FRACTOL V1.0");
	mlx_string_put(data->mlx_ptr, data->win_ptr, x + 1, y + 1,
		data->tui.title_color, "FRACTOL V1.0");
	y += 50;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		data->tui.type);
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		data->tui.palette);
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"zooom");
	// data->tui.zoom);
	// free(data->tui.zoom);
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, HEIGHT / 5.15,
		data->tui.title_color, "CONTROLS");
	mlx_string_put(data->mlx_ptr, data->win_ptr, x + 1, HEIGHT / 5.15 + 1,
		data->tui.title_color, "CONTROLS");
	y += 50;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Move up : Arrow up");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Move down : Arrow down");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Move left : Arrow left");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Move right : Arrow right");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Zoom in : W");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Zoom out : S");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Change palette : P");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Increase radius : +");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"decrease radius : -");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Rotate Julia : R");
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, data->tui.text_color,
		"Display TUI : SPACE");
}
