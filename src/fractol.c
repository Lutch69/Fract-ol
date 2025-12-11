/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/06 16:23:32 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	srand(time(NULL));
	ft_memset(&data, 0, sizeof(data));
	if (ac < 2)
		print_usage();
	if (define_fractale(ac, av, &data) == 1)
	{
		if (data.fractal_type == JULIA)
			is_julia(ac, av, &data);
		if (data.fractal_type == MANDELBROT)
			is_mandelbrot(ac, &data);
	}
	return (0);
}
