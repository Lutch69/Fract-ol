/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:22:14 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/28 09:11:38 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	loop_to_pixel(t_data *data)
{
	t_complex	c;

	while(data->x < WIDTH)
	{
		data->y = 0;
		while(data->y < HEIGHT)
		{
			pixel_to_complex(&c, data);
			mandelbrot_iter(c.re, c.im, MAX_ITER);

			data->y++;
		}
		data->x++;
	}
}
int	mandelbrot_iter(double c_re, double c_im, int max_iter)
{
	t_complex	z;
	double		temp_re;
	double		temp_im;
	int			i;

	ft_memset(&z, 0, sizeof(z));
	i = 0;
	while (i < max_iter)
	{
		temp_re = z.re * z.re - z.im * z.im; // calcule de la some au carré
		temp_im = 2 * z.re * z.im;
		z.re = temp_re + c_re;
		z.im = temp_im + c_im; // on ajoute la somme au carré + c;
		if (z.re * z.re + z.im * z.im > 4)
			break ;
		i++;
	}
	return (i);
}
