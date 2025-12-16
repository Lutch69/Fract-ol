/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:24:09 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/12/16 14:15:24 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

int	check_float(char *av);
int	fractal_type(char **av, t_data *data);

int	define_fractale(int ac, char **av, t_data *data)
{
	if (!(ac == 2 || ac == 4))
		print_usage();
	if (fractal_type(av, data) > 0)
		return (1);
	else
	{
		printf("Error: Unknown fractal type '%s'\n", av[1]);
		print_usage();
	}
	return (1);
}

int	check_float(char *av)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while ((av[i] >= 9 && av[i] <= 13) || av[i] == 32)
		i++;
	if (av[i] == '+' || av[i] == '-')
		i++;
	if (!(ft_isdigit(av[i]) == 1))
		print_usage();
	while (av[i])
	{
		if (!(ft_isdigit(av[i]) == 1 || av[i] == '.'))
			print_usage();
		if (av[i] == '.')
			comma++;
		if (comma > 1)
			print_usage();
		i++;
	}
	if (av[i] == '\0')
		return (1);
	else
		return (0);
}

int	fractal_type(char **av, t_data *data)
{
	if (((ft_strncmp(av[1], "MANDELBROT", 11)) == 0) || (ft_strncmp(av[1],
				"Mandelbrot", 11) == 0) || (ft_strncmp(av[1], "mandelbrot",
				11) == 0))
		data->fractal_type = MANDELBROT;
	else if (((ft_strncmp(av[1], "Julia", 6)) == 0) || ft_strncmp(av[1],
			"JULIA", 6) == 0 || ft_strncmp(av[1], "julia", 6) == 0)
		data->fractal_type = JULIA;
	else if (((ft_strncmp(av[1], "BURNINGSHIP", 12)) == 0)
		|| ((ft_strncmp(av[1], "Burningship", 12) == 0))
		|| (ft_strncmp(av[1], "burningship", 12) == 0))
		data->fractal_type = BURNINGSHIP;
	else if (((ft_strncmp(av[1], "Tricorn", 8)) == 0) || ft_strncmp(av[1],
			"TRICORN", 8) == 0 || ft_strncmp(av[1], "tricorn", 6) == 0)
		data->fractal_type = TRICORN;
	else if (((ft_strncmp(av[1], "Phoenix", 8)) == 0) || ft_strncmp(av[1],
			"PHOENIX", 8) == 0 || ft_strncmp(av[1], "phoenix", 6) == 0)
		data->fractal_type = PHOENIX;
	if (data->fractal_type == MANDELBROT || data->fractal_type == JULIA
		|| data->fractal_type == BURNINGSHIP || data->fractal_type == TRICORN
		|| data->fractal_type == PHOENIX)
		return (1);
	else
		return (0);
}
