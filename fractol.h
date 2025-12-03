/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:47 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/03 17:59:33 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// x = largeur  y = hauteur

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WIDTH
#  define WIDTH 300
# endif

# ifndef HEIGHT
#  define HEIGHT 300
# endif

#ifndef MAX_ITER
# define MAX_ITER 1000
# endif

# include "minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "struct.h"
# include "event.h"

int		put_color_to_pixel(int iter);
int		render(t_data *data);
int		mandelbrot_iter(double c_re, double c_im);
void	pixel_to_complex(t_complex *c, t_data *data);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		mouse_hook(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);

// set up struct
void	setup_re_im(t_data *data, int flag);
void	init_color(t_color *color, int iter);
void	init_image(t_data *data);
void	setup_data(t_data *data);
void	range_setup (t_data *data);
void	setup_center(t_data *data);

#endif
