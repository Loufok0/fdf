/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:24:19 by malapoug          #+#    #+#             */
/*   Updated: 2025/11/01 01:13:28 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>

# ifndef WIDTH
#  define WIDTH 1500
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

typedef struct s_br
{
	int		dx;
	int		dy;
	int		tx;
	int		ty;
	int		e;
	int		e2;
}				t_br;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		**arr;
	char	**char_lines;
	int		arr_w;
	int		arr_h;
	t_data	*img;
	double	scale;
	double	z_scale;
	int		color;
	int		diff_x;
	int		diff_y;
	int		max_z;
	int		min_z;
	double	ang_y;
	double	ang_x;
}	t_vars;

//parser
int				**parser(t_vars *vars, const char *file);

//parser_utils
void			ft_free_arr_i(int **arr, int i);
int				arr_size(char **arr);
int				arr_size_i(int **arr);

//fdf_init
void			find_extrms(t_vars *vars);
int				win_init(t_vars *vars);
int				init(t_vars *vars);

//main
void			update_img(t_vars *vars);

//fdf_draw
t_data			*drawer(t_vars *vars);
void			put_pxl(t_vars *vars, t_br br, int x, int y);
int				trgb(int t, int r, int g, int b);

//get_color

unsigned int	get_color(t_vars *vars, t_br br);

//bresenham
void			bresenham(t_vars *vars, int x1, int y1, int x_y);

//fdf_maths
int				transf_x(t_vars *vars, int x, int y);
int				transf_y(t_vars *vars, int x, int y, int z);
int				color(t_vars *vars, int x, int y);
int				trgb(int t, int r, int g, int b);

//fdf_hook
int				close_win(t_vars *vars);
int				key_hook(int key, t_vars *vars);

//fdf_clean
void			ft_free_t_data(void *mlx, t_data *img);
void			ft_free_t_vars(t_vars *vars);

#endif
