/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:24:55 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/21 19:59:22 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# define WIDTH 1020
# define HEIGHT 580

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	point {
	int	x;
	int	y;
}				point;

typedef struct	imag {
	double	a;
	double	bi;
}				imag;

typedef struct	s_vars {
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	imag	cte;
	point	pixel;
	imag	c;
	double	pos_x;
	double	pos_y;
	double	zoom;
	int		color;
	int		maxi;
}				t_vars;


enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_vars	pix_to_nbr(t_vars vars);
int		color_frac(int i);
int		color_frac(int i);
void	paint_pix(int color, t_vars vars);
void	fractol(t_vars vars);
int		key_hooks(int keycode, t_vars *vars);
t_vars	init_mandelbrot();
t_vars	init_params(char *argv[]);
int	mouse_hooks(int mousecode, int x, int y, t_vars *vars);
#endif