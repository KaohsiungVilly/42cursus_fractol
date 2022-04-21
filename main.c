/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:25:40 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/21 19:54:16 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void leaks(void)
{
	system("leaks fractol");
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	atexit(leaks);
	if (argc > 4)
		return (0);
	vars = init_params(argv);
	fractol(vars);
	mlx_hook(vars.mlx_win, 2, 1L<<0, key_hooks, &vars);
	mlx_mouse_hook(vars.mlx_win, mouse_hooks, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
