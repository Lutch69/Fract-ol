/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:13:29 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/16 14:15:36 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	others_fractol_v1(int *y, t_data *data);
void	fractol_v1(int *x, int *y, t_data *data);
void	get_controls(int *x, int *y, t_data *data);
void	others_controls(int *y, t_data *data);

void	text_user_interface(t_data *data)
{
	int		y;
	int		x;
	char	*temp;
	char	*temp2;

	y = HEIGHT / 32;
	x = WIDTH / 15;
	temp = ft_ftoa(data->zoom, 2);
	data->tui.zoom = ft_strjoin("zoom : x", temp);
	temp2 = ft_itoa(data->max_iter);
	data->tui.max_iter = ft_strjoin("Details lvl : ", temp2);
	free(temp2);
	free(temp);
	fractol_v1(&x, &y, data);
	others_fractol_v1(&y, data);
	get_controls(&x, &y, data);
	others_controls(&y, data);
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
}

void	others_fractol_v1(int *y, t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
		data->tui.text_color, data->tui.c_re);
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
		data->tui.text_color, data->tui.c_im);
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
		data->tui.text_color, data->tui.max_iter);
	free(data->tui.max_iter);
	*y += 30;
	if (data->julia.auto_rotate == 1 || data->phoenix.auto_rotate == 1)
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
			data->tui.text_color, "Rotate : ON");
	else if (data->julia.auto_rotate == 0 || data->phoenix.auto_rotate == 0)
		mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y,
			data->tui.text_color, "Rotate : OFF");
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
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Zoom in : W");
	*y += 30;
}

void	others_controls(int *y, t_data *data)
{
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
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Increase details : Q");
	*y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, *y, data->tui.text_color,
		"Decrease dettails : A");
}
