/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:33:54 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/28 15:39:32 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	transf_x(t_vars *vars, int x, int y)
{
	return ((int)(vars->ang_y * ((x * vars->scale + vars->diff_x) \
	- (y * vars->scale + vars->diff_y))));
}

int	transf_y(t_vars *vars, int x, int y, int z)
{
	return ((int)(vars->ang_x * ((x * vars->scale + vars->diff_x) \
	+ (y * vars->scale + vars->diff_y)) - (z * vars->z_scale)));
}

int	color(t_vars *vars, int x, int y)
{
	int	z;
	int	a;
	int	b;

	if (vars->z_scale == 0)
		return (42);
	a = x * vars->scale + vars->diff_x;
	b = y * vars->scale + vars->diff_y;
	z = (vars->ang_x * (a + b) - y) / vars->z_scale;
	return ((25 * (z - vars->min_z)) / (vars->max_z - vars->min_z));
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
