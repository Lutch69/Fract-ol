/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:47 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/10 12:14:24 by lucasdebarn      ###   ########.fr       */
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

# define MAX_ITER 100

# ifndef M_PI
# define M_PI 3.14159265358979323846
# endif

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include "mlx.h"
# include "../../libft/libft.h"
# include "../../printf/ft_printf.h"
# include "struct_bonus.h"
# include "../event.h"

int		to_hsv(t_color_palette *palette , double logari);
int		put_color_to_pixel(t_data *data, int iter);
int		render(t_data *data);
void	pixel_to_complex(t_complex *c, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		mouse_hook(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		key_press(int keycode, void *param);
void	key_r(t_data *data);
void	define_view(t_data *data, int keycode);
int		close_prog(void *param);
void	print_usage(void);
int		define_fractale(int ac, char **av, t_data *data);
int		check_float(char *av);
void	is_julia(int ac, char **av, t_data *data);
void	rotate_julia(t_data *data);
void	is_mandelbrot(int ac, t_data *data);
void	event_mlx(t_data *data);
void	convert_julia(char **av, t_data *data);
void	init_julia(t_data *data);
int		mouse_button_press(int x, int y, t_data *data);
int		mouse_button_release(int button, int x, int y, void *param);
void	is_burningship(int ac, t_data *data);

// set up struct
void	setup_re_im(t_data *data, int flag);
void	init_image(t_data *data);
void	range_setup (t_data *data);
void	setup_center(t_data *data);

// define palette
void	change_palette(t_data *data);
void	palette_rainbow(t_color_palette *palette);
void	palette_cold(t_color_palette *palette);
void	palette_warm(t_color_palette *palette);
void	palette_forest(t_color_palette *palette);
void	palette_night(t_color_palette *palette);
void	palette_psychedelic(t_color_palette *palette);
void	palette_grey(t_color_palette *palette);
void	palette_ocean(t_color_palette *palette);
void	palette_sunset(t_color_palette *palette);


void	rotate_julia(t_data *data);
#endif
