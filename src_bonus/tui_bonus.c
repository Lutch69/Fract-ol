/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:13:29 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/12 15:53:22 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	get_zoom(t_data *data);
void	fractol_v1(int *x, int *y, t_data *data);
void	get_controls(int *x, int *y, t_data *data);
void	others_controls(int *y, t_data *data);

void	text_user_interface(t_data *data)
{
	int	y;
	int	x;

	y = HEIGHT / 32;
	x = WIDTH / 15;
	get_zoom(data);
	fractol_v1(&x, &y, data);
	get_controls(&x, &y, data);
	others_controls(&y, data);
}

void	get_zoom(t_data *data)
{
	char	*temp;

	temp = ft_ftoa(data->zoom, 2);
	data->tui.zoom = ft_strjoin("zoom : x", temp);
	free(temp);
}

void	fractol_v1(int *x, int *y, t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, *x, *y, data->tui.title_color,
		"FRACTOL V1.0");
	mlx_string_put(data->mlx_ptr, data->win_ptr, *x + 1, *y + 1,
		data->tui.title_color, "FRACTOL V1.0");
	*y += 50;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		data->tui.type);
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		data->tui.palette);
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
		data->tui.text_color, data->tui.zoom);
	free(data->tui.zoom);
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
		data->tui.text_color, "Coordinate complex :");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
		data->tui.text_color, data->tui.c_re);
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
		data->tui.text_color, data->tui.c_im);
	*y += 50;
}

void	get_controls(int *x, int *y, t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, *x, *y,
		data->tui.title_color, "CONTROLS");
	mlx_string_put(data->mlx_ptr, data->win_ptr, *x + 1, *y + 1,
		data->tui.title_color, "CONTROLS");
	*y += 50;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Move up : Arrow up");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Move down : Arrow down");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Move left : Arrow left");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Move right : Arrow right");
	*y += 30;
}

void	others_controls(int *y, t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Zoom in : W");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Zoom out : S");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Change palette : P");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Increase radius : +");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"decrease radius : -");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Rotate Julia : R");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Display TUI : SPACE");
}
