/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:14:28 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/15 18:05:49 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(t_vars *vars)
{
	ft_free_t_vars(vars);
	exit(EXIT_SUCCESS);
}

void	reset(t_vars *vars)
{
	vars->color = 0;
	vars->scale = 10;
	vars->z_scale = vars->scale / 2;
	vars->diff_x = WIDTH / 2;
	vars->diff_y = 0;
	vars->ang_y = 0.866;
	vars->ang_x = 0.5;
}

int	key_hook2(int key, t_vars *vars)
{
	if (key == 65363)
	{
		vars->diff_x -= 10;
		vars->diff_y += 10;
	}
	else if (key == 65364)
	{
		vars->diff_x -= 10 * (1 / vars->ang_x);
		vars->diff_y -= 10 * (1 / vars->ang_x);
	}
	else if (key == 119 && vars->ang_x > 0.2)
		vars->ang_x -= 0.1;
	else if (key == 115 && vars->ang_x < 1)
		vars->ang_x += 0.1;
	else if (key == 114)
		reset(vars);
	else if (key == 99)
		vars->color = !vars->color;
	if (vars->img->img)
		update_img(vars);
	return (1);
}

int	key_hook(int key, t_vars *vars)
{
	if (key == 65307)
		close_win(vars);
	if (key == 65451)
	{
		vars->scale++;
		vars->z_scale = vars->scale / 2;
	}
	else if (key == 65453 && vars->scale > 3)
	{
		vars->scale--;
		vars->z_scale = vars->scale / 2;
	}
	else if (key == 65361)
	{
		vars->diff_x += 10;
		vars->diff_y -= 10;
	}
	else if (key == 65362)
	{
		vars->diff_x += 10 * (1 / vars->ang_x);
		vars->diff_y += 10 * (1 / vars->ang_x);
	}
	return (key_hook2(key, vars));
}
