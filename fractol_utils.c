/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:30:53 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/21 20:00:23 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	color_frac(int i)
{
	while (i > 10)
		i %= 10;
	return (i);
}

void	paint_pix(int color, t_vars vars)
{
	if (color == vars.maxi)
		my_mlx_pixel_put(&vars.img, vars.pixel.x, vars.pixel.y, 0x000000);
	else
		my_mlx_pixel_put(&vars.img, vars.pixel.x, vars.pixel.y, vars.color * color); //process cyan
	return ;
}

t_vars	pix_to_nbr(t_vars vars)
{
	vars.c.a = (vars.pixel.x * WIDTH / HEIGHT - WIDTH / 2) / (0.5 * vars.zoom * WIDTH) - vars.pos_x;
	vars.c.bi = (vars.pixel.y - HEIGHT / 2) / (0.5 * vars.zoom * HEIGHT) - vars.pos_y;
	return (vars);
}

// (-2.8578, 0) (1, 0)
// (-2.8556, 0) (2, 0)
// (-2.8534, 0) (3, 0)