/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:37:33 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/16 15:14:07 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*parse_line_to_ints(t_vars *vars, char *line)
{
	char	**split;
	int		word_count;
	int		*row;

	row = NULL;
	vars->arr_w = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	word_count = arr_size(split);
	row = malloc(sizeof(int) * word_count);
	if (!row)
		return (ft_free_arr(split, arr_size(split)), NULL);
	while (vars->arr_w < word_count && split[vars->arr_w])
	{
		row[vars->arr_w] = ft_atoi(split[vars->arr_w]);
		vars->arr_w++;
	}
	ft_free_arr(split, arr_size(split));
	return (row);
}

int	**parse_text_to_3d_array(t_vars *vars, char *text, int **arr)
{
	char	**lines;
	int		i;

	lines = ft_split(text, '\n');
	if (!lines)
		return (NULL);
	vars->arr_h = arr_size(lines);
	arr = malloc(sizeof(int *) * (vars->arr_h + 1));
	if (!arr)
		return (ft_free_arr(lines, arr_size(lines)), NULL);
	i = 0;
	while (i < vars->arr_h)
	{
		arr[i] = parse_line_to_ints(vars, lines[i]);
		if (!arr[i])
		{
			ft_free_arr_i(arr, i);
			free(lines);
			return (NULL);
		}
		i++;
	}
	vars->char_lines = lines;
	arr[vars->arr_h] = NULL;
	return (arr);
}

char	*read_file(int fd)
{
	char	*buffer;
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(buffer, line);
		free(buffer);
		free(line);
		if (!temp)
			return (NULL);
		buffer = temp;
		line = get_next_line(fd);
	}
	return (buffer);
}

int	**parser(t_vars *vars, const char *file)
{
	char	*text;
	int		**arr;
	int		fd;

	text = NULL;
	arr = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	text = read_file(fd);
	close(fd);
	if (!text)
		return (NULL);
	arr = parse_text_to_3d_array(vars, text, arr);
	free(text);
	return (arr);
}
