/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:52:28 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/22 17:25:48 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(unsigned char t,
	unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	key_hooks(int keycode, t_vars *vars)
{
	int	random;

	random = (1 + rand()) % 256;
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		vars->pos_x += 0.8 / vars->zoom;
	else if (keycode == 124)
		vars->pos_x -= 0.8 / vars->zoom;
	else if (keycode == 6)
		vars->zoom *= 1.5;
	else if (keycode == 7)
		vars->zoom /= 1.5;
	else if (keycode == 126)
		vars->pos_y += 0.8 / vars->zoom;
	else if (keycode == 125)
		vars->pos_y -= 0.8 / vars->zoom;
	else if (keycode == 8)
		vars->color *= -1;
	vars->pixel.y = 0;
	fractol(*vars);
	return (0);
}

t_vars	*new_coordanates(t_vars *vars, int x, int y)
{
	vars->pos_x = (x - WIDTH / HEIGHT) * WIDTH / 0.5 * vars->zoom * WIDTH;
	vars->pos_y = (y * HEIGHT / 0.5 * vars->zoom * HEIGHT);
	return (vars);
}

int	mouse_hooks(int mousecode, int x, int y, t_vars *vars)
{
	y = x;
	if (!vars)
		exit(1);
	if (mousecode == 5)
		vars->zoom *= 1.5;
	else if (mousecode == 4)
		vars->zoom /= 1.5;
	fractol(*vars);
	return (0);
}
