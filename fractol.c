/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/28 16:44:33 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}
int	mouse_press(int mousecode, void *param)
{
	(void) param;
	printf ("%d\n", mousecode);

	return(0);
}

int	key_press(int keycode, void *param)
{
	(void)param;
	printf ("%d\n", keycode);
	if (keycode == 65307)
		close_window(param);
	return (0);
}

void	setup_data(t_data *data)
{
	ft_memset(data, 0, sizeof(data));
;	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	data->center_re = -0.5;
	data->center_im = 0.0;
}

int	main(void)
{
	t_data	data;
	t_view view;

	setup_data(&data);
	setup_re_im(&view, &data);
	loop_to_pixel(&data);
	mlx_key_hook(data.win_ptr, key_press, NULL);
	mlx_hook(data.win_ptr, 17, 0, close_window, NULL);
	mlx_loop(data.mlx_ptr);
}
