/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:24:55 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/22 17:19:03 by pvillena         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct point {
	int	x;
	int	y;
}			t_point;

typedef struct imag {
	double	a;
	double	bi;
}			t_imag;

typedef struct s_vars {
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	t_imag	cte;
	t_point	pixel;
	t_imag	c;
	int		color;
	double	pos_x;
	double	pos_y;
	double	zoom;
	int		maxi;
	int		type;
	int		julia;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_vars	pix_to_nbr(t_vars vars);
t_imag	set_imag(double a, double bi);
int		color_frac(int i);
int		color_frac(int i);
void	paint_pix(int color, t_vars vars);
void	fractol(t_vars vars);
int		key_hooks(int keycode, t_vars *vars);
t_vars	init_mandelbrot(void);
t_vars	init_julia(char *argv[]);
t_vars	init_julia2(void);
t_vars	init_params(char *argv[]);
int		mouse_hooks(int mousecode, int x, int y, t_vars *vars);
int		create_trgb(unsigned char t,
			unsigned char r, unsigned char g, unsigned char b);
#endif