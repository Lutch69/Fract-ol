/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:47 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/12 13:27:26 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// x = largeur  y = hauteur

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# ifndef WIDTH
#  define WIDTH 900
# endif

# ifndef HEIGHT
#  define HEIGHT 900
# endif

# define MAX_ITER 100

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# include "../../libft/libft.h"
# include "../../printf/ft_printf.h"
# include "../event.h"
# include "mlx.h"
# include "struct_bonus.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

// Fonction for JULIA
void	is_julia(int ac, char **av, t_data *data);
void	convert_julia(char **av, t_data *data);
void	init_julia(t_data *data);
int		iter_julia(double c_re, double c_im, double julia_re, double julia_im);
void	random_julia(t_data *data, int random_index);
void	rotate_julia(t_data *data);

// Fonction for MANDELBROT
int		iter_mandelbrot(double c_re, double c_im);
void	is_mandelbrot(int ac, t_data *data);

// Fonction for BURNINGSHIP
void	is_burningship(int ac, t_data *data);
int		iter_burningship(double c_re, double c_im);

// Fonction for TRICORN
void	is_tricorn(int ac, t_data *data);
int		iter_tricorn(double c_re, double c_im);

// Fonction for phoenix
void	is_phoenix(int ac, t_data *data);
int		iter_phoenix(double c_re, double c_im, t_data *data);
void	rotate_phoenix(t_data *data);

// Fonction KEYBOARD
void	key_plusmin(t_data *data, int keycode);
void	key_r(t_data *data);
void	define_keypress(t_data *data, int keycode);
int		key_press(int keycode, void *param);

// Fonction for MOUSE
int		mouse_button_press(int x, int y, t_data *data);
int		mouse_button_release(int button, int x, int y, void *param);
int		mouse_hook(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
void	mouse_to_complex(t_data *data);

// Fonction for TUI && COLOR
void	text_user_interface(t_data *data);
void	get_coordinate_tui(t_data *data, double c_re, double c_im);
int		to_hsv(t_color_palette *palette, double logari);
int		put_color_to_pixel(t_data *data, int iter);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// Fonction for RENDERING
int		render(t_data *data);
void	define_rotate(t_data *data);
void	pixel_to_complex(t_complex *c, t_data *data);

// Fonction for PARSING && UTILITY
int		close_prog(void *param);
void	print_usage(void);
int		define_fractale(int ac, char **av, t_data *data);
int		check_float(char *av);

// Fonction FOR SETUP STRUCT
void	event_mlx(t_data *data);
void	setup_re_im(t_data *data, int flag);
void	init_image(t_data *data);
void	range_setup(t_data *data);
void	setup_center(t_data *data);

// Fonction for PALETTE
void	change_palette(t_data *data);
void	palette_rainbow(t_data *data);
void	palette_cold(t_data *data);
void	palette_warm(t_data *data);
void	palette_forest(t_data *data);
void	palette_night(t_data *data);
void	palette_psychedelic(t_data *data);
void	palette_grey(t_data *data);
void	palette_ocean(t_data *data);
void	palette_sunset(t_data *data);

#endif
