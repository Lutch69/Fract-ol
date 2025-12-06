/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:47 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/06 16:23:14 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// x = largeur  y = hauteur

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# ifndef WIDTH
#  define WIDTH 600
# endif

# ifndef HEIGHT
#  define HEIGHT 600
# endif

#ifndef MAX_ITER
# define MAX_ITER 1000
# endif

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include "mlx.h"
# include "../../libft/libft.h"
# include "../../printf/ft_printf.h"
# include "struct_bonus.h"
# include "../src/event.h"

int		put_color_to_pixel(int iter);
int		render(t_data *data);
void	pixel_to_complex(t_complex *c, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		mouse_hook(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		key_press(int keycode, void *param);
void	define_view(t_data *data, int keycode);
int		close_prog(void *param);
void	print_usage(void);
int		define_fractale(int ac, char **av, t_data *data);
int		check_float(char *av);
void	is_julia(int ac, char **av, t_data *data);
void	is_mandelbrot(int ac, t_data *data);
void	event_mlx(t_data *data);
void	convert_julia(char **av, t_data *data);

// set up struct
void	setup_re_im(t_data *data, int flag);
void	init_color(t_color *color, int iter);
void	init_image(t_data *data);
void	range_setup (t_data *data);
void	setup_center(t_data *data);

#endif
