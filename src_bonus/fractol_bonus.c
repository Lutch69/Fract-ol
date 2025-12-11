/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:07:40 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/10 12:16:56 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int ac, char **av)
{
	srand(time(NULL));
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (ac < 2)
		print_usage();
	if (define_fractale(ac, av, &data) == 1)
	{
		if (data.fractal_type == JULIA)
			is_julia(ac, av, &data);
		if (data.fractal_type == MANDELBROT)
			is_mandelbrot(ac, &data);
		if (data.fractal_type == BURNINGSHIP)
			is_burningship(ac, &data);
	}
	return (0);
}
