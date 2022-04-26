/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:25:40 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/25 13:30:40 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_p(t_vars *vars)
{
	if (!vars)
		exit(1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 2)
	{
		printf("mandelbrot	julia	burning_ship\n");
		return (0);
	}
	vars = init_params(argv);
	fractol(vars);
	mlx_hook(vars.mlx_win, 17, 0, exit_p, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_hooks, &vars);
	mlx_mouse_hook(vars.mlx_win, mouse_hooks, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
