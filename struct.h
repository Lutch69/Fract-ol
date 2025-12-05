/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:24:16 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/04 12:30:35 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum
{
	MANDELBROT = 1,
	JULIA = 2
};

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_color
{
	int	R;
	int	G;
	int	B;
}			t_color;

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

typedef struct s_mouse
{
	int	x;
	int	y;
	double	ratio_x;
	double	ratio_y;
	double	complex_y;
	double	complex_x;

}		t_mouse;

typedef struct s_data
{
	int			ac;
	char		**av;
	int			x;
	int			y;

	void		*mlx_ptr;
	void		*win_ptr;

	double		center_re;
	double		center_im;
	double		zoom;
	double		step;

	t_view		view;
	t_img		img;
	t_mouse		mouse;
}				t_data;

#endif
