/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:52:28 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/21 20:16:21 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}


int	key_hooks(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 53)
	{
		//mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	else if (keycode == 0 || keycode == 123)
		vars->pos_x += 0.8 / vars->zoom;
	else if (keycode == 2 || keycode == 124)
		vars->pos_x -= 0.8 / vars->zoom;
	else if (keycode == 6)
	{
		vars->zoom *= 1.5;
		if (vars->zoom > 2)
			vars->maxi = 1000;
	}
	else if (keycode == 7)
	{
		vars->zoom /= 1.5;
		if (vars->zoom < 2)
			vars->maxi = 300;
	}
	else if (keycode == 126)
		vars->pos_y += 0.8 / vars->zoom;
	else if (keycode == 125)
		vars->pos_y -= 0.8 / vars->zoom;
	else if (keycode == 8)
	{
		int random = (1 + rand()) % 256;
		vars->color = create_trgb(0, random , 0, 0);
		printf("color: %d\n", vars->color);
	}
	//else if (ke)
	printf("iter: %d\n", vars->maxi);
	fractol(*vars);
	return (0);
}

int	mouse_hooks(int mousecode, int x, int y, t_vars *vars)
{
	printf("my x: %d\n", x);
	printf("my y: %d\n", y);
	printf("mousecode: %d\n", mousecode);
	if (!vars)
		exit(1);
	if (mousecode == 5)
	{
		vars->zoom *= 1.5;
		if (vars->zoom > 2)
			vars->maxi = 1000;
	}
	else if (mousecode == 5)
	{
		vars->zoom /= 1.5;
		if (vars->zoom < 2)
			vars->maxi = 300;
	}
	printf("iter: %d\n", vars->maxi);
	fractol(*vars);
	return (0);
}
