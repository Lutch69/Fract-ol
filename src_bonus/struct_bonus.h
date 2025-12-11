/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:24:16 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/11 21:20:06 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_fractal_type
{
	MANDELBROT =	1,
	JULIA = 		2,
	BURNINGSHIP =	3
}					t_fractal_type;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	double	float_r;
	double	float_g;
	double	float_b;
}			t_rgb;

typedef struct s_hsv
{
	int		part;
	float	f_part;
	double	h_normalized;
	double	v_value;
	double	v_increasing;
	double	v_decreasing;
	double 	v_min;
	t_rgb	rgb;
}			t_hsv;

typedef struct s_color_palette
{
	double	hue_start;
	double	hue_range;
	double	saturation;
	double	value;

	t_hsv	hsv;
}			t_color_palette;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_julia
{
	t_complex	complex;
	double		angle;
	double		radius;
	double		center_re;
	double		center_im;
	int			auto_rotate;
}				t_julia;

typedef struct	s_view
{
	double	real_range;
	double	imag_range;
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
	double	deplacement_re;
	double	deplacement_im;
}			t_view;

typedef struct s_mouse
{
	int	x;
	int	y;
	double	ratio_x;
	double	ratio_y;
	double	complex_y;
	double	complex_x;
	int		delta_x;
	int		delta_y;
	int		flag_drag;
	int		motion_counter;
	int		drag_start_x;
	int		drag_start_y;
	double	center_re_start;
	double	center_im_start;

}		t_mouse;

typedef struct s_tui
{
	char		*type;
	char		*palette;
	char		*zoom;
	int			title_color;
	int			text_color;
	int			width_ui;
}				t_tui;

typedef struct s_data
{
	int				x;
	int				y;

	void			*mlx_ptr;
	void			*win_ptr;

	double			center_re;
	double			center_im;
	double			zoom;
	double			step;
	int				palette_id;
	int				flag_tui;

	t_tui			tui;
	t_view			view;
	t_img			img;
	t_mouse			mouse;
	t_fractal_type	fractal_type;
	t_julia			julia;
	t_color_palette palette;
}					t_data;

#endif
