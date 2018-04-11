/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:07:27 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/22 18:29:10 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			free_map(t_map *map)
{
	int				i;

	if (map->map != NULL)
	{
		i = -1;
		while (++i < map->size_y)
			free(map->map[i]);
		free(map->map);
	}
	if (map->colors != NULL)
	{
		i = -1;
		while (++i < map->size_y)
			free(map->colors[i]);
		free(map->colors);
	}
	if (map->pos != NULL)
	{
		i = -1;
		while (++i < map->size_y)
			free(map->pos[i]);
		free(map->pos);
	}
	free(map);
}

void				free_memory(t_data *data)
{
	if (data != NULL)
	{
		if (data->map != NULL)
			free_map(data->map);
		if (data->mlx != NULL)
			free(data->mlx);
		if (data->win != NULL)
			free(data->win);
		if (data->img != NULL)
			free(data->img);
		if (data->img_data != NULL)
			free(data->img_data);
		free(data);
	}
}
