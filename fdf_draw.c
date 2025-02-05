/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:00:59 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/16 13:58:14 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pxl(t_vars *vars, t_br br, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = vars->img->addr + (y * vars->img->line_length + \
	x * (vars->img->bpp / 8));
	if (vars->color == 1)
		*(unsigned int *)dst = (get_color(vars, br));
	else
		*(unsigned int *)dst = 0xFFFFFF;
}

t_data	*drawer(t_vars *vars)
{
	t_data	*img;
	int		x;
	int		y;

	img = vars->img;
	y = 0;
	while (y < vars->arr_h)
	{
		x = 0;
		while (x < vars->arr_w)
		{
			if (vars->arr[y] != NULL && x + 1 < vars->arr_w)
				bresenham(vars, x, y, 'x');
			if (y + 1 < vars->arr_h)
				bresenham(vars, x, y, 'y');
			x++;
		}
		y++;
	}
	return (img);
}
