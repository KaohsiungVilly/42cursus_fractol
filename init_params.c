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

t_imag	set_cte(char *argv[])
{
	t_imag	cte;

	if (argv[2] == NULL)
		cte = set_imag(0, -0.8);
	else if (ft_strncmp(argv[2], "1", 100) == 0)
		cte = set_imag(-0.4, 0.6);
	else if (ft_strncmp(argv[2], "2", 100) == 0)
		cte = set_imag(0.285, 0);
	else if (ft_strncmp(argv[2], "3", 100) == 0)
		cte = set_imag(0.285, 0.01);
	else if (ft_strncmp(argv[2], "4", 100) == 0)
		cte = set_imag(-0.835, -0.232);
	else
		cte = set_imag(0, -0.8);
	return (cte);
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
	vars.cte = set_cte(argv);
	vars.type = 0;
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
