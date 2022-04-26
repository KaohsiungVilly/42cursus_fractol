/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:11:17 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/22 16:50:00 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vars	init_mandelbrot(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractalan!");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	vars.cte.a = 0;
	vars.cte.bi = 0;
	vars.pos_x = 1.3;
	vars.pos_y = 0;
	vars.zoom = 1;
	vars.type = 0;
	return (vars);
}

t_vars	init_burning_ship(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractalan!");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	vars.cte.a = 0;
	vars.cte.bi = 0;
	vars.pos_x = 1.3;
	vars.pos_y = 0;
	vars.zoom = 1;
	vars.type = 1;
	return (vars);
}

t_vars	init_julia(char *argv[])
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractalan!");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	vars.pos_x = 0;
	vars.pos_y = 0;
	vars.zoom = 1;
	vars.cte.a = -0.8;
	vars.cte.bi = 0.156;
	vars.type = 0;
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
	else if (ft_strncmp(argv[1], "burning_ship", 100) == 0)
		vars = init_burning_ship();
	else
	{
		printf("mandelbrot	julia	burning_ship\n");
		exit(0);
	}
	vars.maxi = 500;
	vars.color = 1;
	return (vars);
}
