/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tui_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:13:29 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/11 15:57:11 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	get_zoom(t_data *data)
{
	char	*temp;

	temp = ft_ftoa(data->zoom);
	data->tui.zoom = ft_strjoin("zoom : x", temp);
	free(temp);
}

void	text_user_interface(t_data *data)
{
	int	y;
	int	x;

	y = HEIGHT / 32;
	x = WIDTH / 15;
	get_zoom(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FFFFFF, "FRACTOL V1.0");
	while (y < 22)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FFFFFF, "Fractol v1.0");
		x++;
		mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FFFFFF, "Fractol v1.0");
		y++;
	}
	y += 50;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, 0x00FFFFFF, data->tui.type);
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, 0x00FFFFFF, data->tui.palette);
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, 0x00FFFFFF, data->tui.zoom);
	free(data->tui.zoom);
	y += 30;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, HEIGHT / 5.15, 0x00FFFFFF, "CONTROLS");
	y += 50;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y, 0x00FFFFFF, "move up : Arrow up");
}
