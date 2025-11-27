/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:47 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/27 15:32:11 by ludebarn         ###   ########.fr       */
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

# include "minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_complex
{
	double	re;
	double	im;
	double	real_range;
	double	imag_range;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}			t_complex;

typedef struct s_data
{
	int			x;
	int			y;
	void		*mlx_ptr;
	void		*win_ptr;
	double		center_re;
	double		center_im;
	double		real_range;
	t_complex	complex;
}				t_data;

#endif
