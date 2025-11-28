/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:47 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/28 09:09:17 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// x = largeur  y = hauteur

#ifndef FRACTOL_H
# define FRACTOL_H

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef HEIGHT
#  define HEIGHT 800
# endif

#ifndef MAX_ITER
# define MAX_ITER 200
# endif

// # include "minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	re;
	double	im;

}			t_complex;

typedef struct	s_view
{
	double	real_range;
	double	imag_range;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}			t_view;

typedef struct s_data
{
	int			x;
	int			y;

	void		*mlx_ptr;
	void		*win_ptr;

	double		center_re;
	double		center_im;
	double		zoom;

	t_view		view;
}				t_data;

int	mandelbrot_iter(double c_re, double c_im, int max_iter);
void	pixel_to_complex(t_complex *c, t_data *data);
void	setup_re_im(t_view *view, t_data *data);

#endif
