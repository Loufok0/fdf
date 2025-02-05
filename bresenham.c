/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:12:47 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/16 14:56:01 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_br(t_br *br, int dx, int dy)
{
	br->dx = dx;
	br->dy = dy;
	br->e = -dy / 2;
	if (dx > dy)
		br->e = dx / 2;
}

void	comp_tx(t_br *br, int *tx1, int *tx2)
{
	if (br->e2 > -br->dx)
	{
		br->e -= br->dy;
		if (*(tx1) < *(tx2))
			*(tx1) += 1;
		else
			*(tx1) -= 1;
	}
}

void	comp_y(t_br *br, int *y1, int *y2)
{
	if (br->e2 < br->dy && br->e + br->dy < br->dy)
	{
		br->e += br->dx;
		if (*(y1) < *(y2))
			*(y1) += 1;
		else
			*(y1) -= 1;
	}
}

void	br_x_y(t_br *br, int tx, int ty)
{
	br->tx = tx;
	br->ty = ty;
}

void	bresenham(t_vars *vars, int x1, int y1, int x_y)
{
	t_br	br;
	int		y2;
	int		tx1;
	int		tx2;

	if (x_y == 'x')
		tx2 = transf_x(vars, x1 + 1, y1);
	if (x_y == 'x')
		y2 = transf_y(vars, x1 + 1, y1, vars->arr[y1][x1 + 1]);
	else
	{
		tx2 = transf_x(vars, x1, y1 + 1);
		y2 = transf_y(vars, x1, y1 + 1, vars->arr[y1 + 1][x1]);
	}
	br_x_y(&br, x1, y1);
	tx1 = transf_x(vars, x1, y1);
	y1 = transf_y(vars, x1, y1, vars->arr[y1][x1]);
	init_br(&br, abs(tx2 - tx1), abs(y2 - y1));
	while (tx1 != tx2 || y1 != y2)
	{
		br.e2 = br.e;
		put_pxl(vars, br, tx1, y1);
		comp_tx(&br, &tx1, &tx2);
		comp_y(&br, &y1, &y2);
	}
}
