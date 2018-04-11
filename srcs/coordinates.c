/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:22:49 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/24 09:01:41 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					init_coordinates(t_map *map)
{
	int				y;

	if ((map->pos = malloc(sizeof(t_pos*) * map->size_y)) == NULL)
		return (-1);
	y = -1;
	while (++y < map->size_y)
	{
		if ((map->pos[y] = malloc(sizeof(t_pos) * map->size_x)) == NULL)
		{
			while (--y >= 0)
			{
				free(map->pos[y]);
			}
			free(map->pos);
			return (-1);
		}
	}
	return (1);
}

int					init_colors(t_map *map)
{
	int				y;

	if ((map->colors = malloc(sizeof(int*) * map->size_y)) == NULL)
		return (-1);
	y = -1;
	while (++y < map->size_y)
	{
		if ((map->colors[y] = malloc(sizeof(int) * map->size_x)) == NULL)
		{
			while (--y >= 0)
			{
				free(map->colors[y]);
			}
			free(map->colors);
			return (-1);
		}
	}
	return (1);
}

void				calculate_colors(t_data *data)
{
	int				x;
	int				y;
	double			tmp;

	if (init_colors(data->map) == -1)
	{
		data->map->colors = NULL;
		return ;
	}
	y = -1;
	while (++y < data->map->size_y)
	{
		x = -1;
		while (++x < data->map->size_x)
		{
			tmp = 0;
			if ((data->map->highest - data->map->lowest) != 0)
				tmp = (double)(data->map->map[y][x] - data->map->lowest)
					/ (double)(data->map->highest - data->map->lowest);
			data->map->colors[y][x] = ((int)(0xFF0000 / (1 - tmp)) & 0xFF0000)
									| ((int)(0x0000FF / tmp) & 0x0000FF);
		}
	}
}

void				calculate_coordinates(t_data *data)
{
	int				x;
	int				y;
	int				z;

	y = -1;
	while (++y < data->map->size_y)
	{
		x = -1;
		while (++x < data->map->size_x)
		{
			z = data->map->map[y][x];
			data->map->pos[y][x].x = (x * cos(DEGREESTORADIANS(data->angle))
				+ y * cos(DEGREESTORADIANS(data->angle + 120))
				+ (z * data->amp) * cos(DEGREESTORADIANS(data->angle - 120)))
				* data->zoom + data->offset_x;
			data->map->pos[y][x].y = (x * sin(DEGREESTORADIANS(data->angle))
				+ y * sin(DEGREESTORADIANS(data->angle + 120))
				+ (z * data->amp) * sin(DEGREESTORADIANS(data->angle - 120)))
				* data->zoom + data->offset_y;
		}
	}
}
