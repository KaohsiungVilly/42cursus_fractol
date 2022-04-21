/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:21:46 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/21 20:00:01 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	calc_pix(t_vars vars)
{
	int		i;
	double	temp;

	i = -1;
	vars = pix_to_nbr(vars);
	if (vars.cte.a == 0 && vars.cte.bi == 0)
	{
		vars.cte.a = vars.c.a;
		vars.cte.bi = vars.c.bi;
		vars.c.a = 0;
		vars.c.bi = 0;
	}
	while (++i < vars.maxi && vars.c.a * vars.c.a + vars.c.bi * vars.c.bi < 4)
	{
		temp = vars.c.a * vars.c.a - vars.c.bi * vars.c.bi + vars.cte.a;
		vars.c.bi = 2 * vars.c.a * vars.c.bi + vars.cte.bi;
		vars.c.a = temp;
	}
	return (i);
	//return (color_frac(i));
}

void	fractol(t_vars vars)
{
	int		color;

	vars.pixel.y = 0;
	while (vars.pixel.y < HEIGHT)
	{
		vars.pixel.x = 0;
		while (vars.pixel.x < WIDTH)
		{
			color = calc_pix(vars);
			paint_pix(color, vars);
			vars.pixel.x++;
		}
		vars.pixel.y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
}
