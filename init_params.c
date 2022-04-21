/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:11:17 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/21 20:03:13 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_vars	init_mandelbrot()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractalan!");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.cte.a = 0;
	vars.cte.bi = 0;
	vars.pos_x = 1.3;
	vars.pos_y = 0;
	vars.zoom = 1;
	vars.color = 116;
	return (vars);
}

t_vars	init_julia(char *argv[])
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractalan!");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	vars.pos_x = 0;
	vars.pos_y = 0;
	vars.zoom = 1;
	vars.color = 226;
	vars.cte.a = -0.835;
	vars.cte.bi = -0.2321;
	if (*argv[0] == 'j')
		return (vars);
	return (vars);
}

t_vars	init_params(char *argv[])
{
	t_vars	vars;
	if (ft_strncmp(argv[1], "mandelbrot", 100) == 0)
		vars = init_mandelbrot();
	else if (ft_strncmp(argv[1], "julia", 100) == 0)
		vars = init_julia(argv);
	else
		exit(1);
	vars.maxi = 200;
	return (vars);
}