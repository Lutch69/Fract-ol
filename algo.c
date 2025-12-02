/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:22:14 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/01 17:59:59 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(t_data *data)
{
	t_complex	c;
	int			iter;
	int			color;
	data->x = 0;

	while(data->x < WIDTH)
	{
		data->y = 0;
		while(data->y < HEIGHT)
		{
			pixel_to_complex(&c, data);
			iter = mandelbrot_iter(c.re, c.im);
			color = put_color_to_pixel(iter);
			my_mlx_pixel_put(&data->img, data->x, data->y, color);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
	return(0);
}
int	mandelbrot_iter(double c_re, double c_im)
{
	t_complex	z;
	double		temp_re;
	double		temp_im;
	int			i;

	ft_memset(&z, 0, sizeof(z));
	i = 0;
	while (i < MAX_ITER)
	{
		temp_re = (z.re * z.re - z.im * z.im); // calcule de la some au carré
		temp_im = (2 * z.re * z.im);
		z.re = temp_re + c_re;
		z.im = temp_im + c_im; // ajoute la somme au carré + c;
		if (z.re * z.re + z.im * z.im > 4.00)
			break ;
		i++;
	}
	return (i);
}
