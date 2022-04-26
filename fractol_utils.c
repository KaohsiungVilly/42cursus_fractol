/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:30:53 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/22 13:48:36 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_imag	set_imag(double a, double bi)
{
	t_imag	cte;

	cte.a = a;
	cte.bi = bi;
	return (cte);
}

int	ft_color(int color, int c)
{
	int		ret[4];

	if (c == 1)
	{
		ret[0] = 0;
		ret[1] = (int)(sin(0.25 * color + 4) * 127.5 + 127.5);
		ret[2] = (int)(sin(0.15 * color + 4) * 127.5 + 127.5);
		ret[3] = (int)(sin(0.1 * color + 4) * 127.5 + 127.5);
	}
	else
	{
		ret[0] = 0;
		ret[1] = (int)(sin(0.4 * color + 4) * 127.5 + 127.5);
		ret[2] = (int)(sin(0.3 * color + 4) * 127.5 + 127.5);
		ret[3] = (int)(sin(0.01 * color + 4) * 127.5 + 127.5);
	}
	return (create_trgb(ret[0], ret[1], ret[2], ret[3]));
}

void	paint_pix(int color, t_vars vars)
{
	if (color == vars.maxi)
		my_mlx_pixel_put(&vars.img, vars.pixel.x, vars.pixel.y, 0x000000);
	else
		my_mlx_pixel_put(&vars.img, vars.pixel.x,
			vars.pixel.y, ft_color(color, vars.color));
}

t_vars	pix_to_nbr(t_vars vars)
{
	vars.c.a = (vars.pixel.x * WIDTH / HEIGHT - WIDTH / 2)
		/ (0.5 * vars.zoom * WIDTH) - vars.pos_x;
	vars.c.bi = (vars.pixel.y - HEIGHT / 2)
		/ (0.5 * vars.zoom * HEIGHT) - vars.pos_y;
	return (vars);
}
