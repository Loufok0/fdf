/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:57:21 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/15 17:55:13 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_extrems(t_vars *vars)
{
	int		x;
	int		y;

	y = 0;
	vars->max_z = vars->arr[0][0];
	vars->min_z = vars->arr[0][0];
	while (y < vars->arr_h)
	{
		x = 0;
		while (x < vars->arr_w)
		{
			if (vars->arr[y][x] > vars->max_z)
				vars->max_z = vars->arr[y][x];
			if (vars->arr[y][x] < vars->min_z)
				vars->min_z = vars->arr[y][x];
			x++;
		}
		y++;
	}
}

int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF by malapoug");
	if (!vars->win)
		return (0);
	vars->img = malloc(sizeof(t_data));
	if (!vars->img)
		return (0);
	vars->img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img->img)
		return (0);
	vars->img->addr = mlx_get_data_addr(vars->img->img, \
		&vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	return (1);
}

int	init(t_vars *vars)
{
	if (!win_init(vars))
		return (0);
	find_extrems(vars);
	vars->color = 0;
	vars->scale = 10;
	vars->z_scale = vars->scale / 2;
	vars->diff_x = WIDTH / 2;
	vars->diff_y = 0;
	vars->ang_y = 0.866;
	vars->ang_x = 0.5;
	return (1);
}
