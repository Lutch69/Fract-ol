/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:47 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/29 13:52:49 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// x = largeur  y = hauteur

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WIDTH
#  define WIDTH 1600
# endif

# ifndef HEIGHT
#  define HEIGHT 1600
# endif

#ifndef MAX_ITER
# define MAX_ITER 200
# endif

# include "minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "struct.h"

int		mandelbrot_iter(double c_re, double c_im);
void	pixel_to_complex(t_complex *c, t_data *data);
void	setup_re_im(t_view *view, t_data *data);
void	put_color_to_pixel(t_data *data, int iter);
void	loop_to_pixel(t_data *data);
void	init_color(t_color *color, int iter);

#endif
