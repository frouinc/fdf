/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:48:53 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/29 17:00:38 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				init_keys(t_data *data)
{
	data->keys[0].keycode = 0;
	data->keys[0].func = &key_move_left;
	data->keys[1].keycode = 1;
	data->keys[1].func = &key_move_down;
	data->keys[2].keycode = 2;
	data->keys[2].func = &key_move_right;
	data->keys[3].keycode = 13;
	data->keys[3].func = &key_move_up;
	data->keys[4].keycode = 12;
	data->keys[4].func = &key_rotate_clock;
	data->keys[5].keycode = 14;
	data->keys[5].func = &key_rotate_anti;
	data->keys[6].keycode = 15;
	data->keys[6].func = &key_zoom_in;
	data->keys[7].keycode = 3;
	data->keys[7].func = &key_zoom_out;
	data->keys[8].keycode = 17;
	data->keys[8].func = &key_amp_in;
	data->keys[9].keycode = 5;
	data->keys[9].func = &key_amp_out;
	data->keys[10].keycode = 53;
	data->keys[10].func = &key_escape;
	data->keys[11].keycode = 8;
	data->keys[11].func = &key_color;
}

void				init_high_low(t_data *data)
{
	int				i;
	int				j;

	j = -1;
	while (++j < data->map->size_y)
	{
		i = -1;
		while (++i < data->map->size_x)
		{
			if (data->map->map[j][i] > data->map->highest)
				data->map->highest = data->map->map[j][i];
			else if (data->map->map[j][i] < data->map->lowest)
				data->map->lowest = data->map->map[j][i];
		}
	}
	data->map->delta = data->map->highest - data->map->lowest;
}

void				init_values(t_data *data)
{
	data->change = true;
	data->angle = 30;
	data->amp = 1;
	data->size_x = 800;
	data->size_y = 600;
	data->offset_x = data->size_x / 2;
	data->offset_y = data->size_y / 3;
	data->color = false;
	data->zoom = data->size_x / (data->map->size_x * 3);
	data->map->highest = 0;
	data->map->lowest = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->img_data = NULL;
	init_high_low(data);
}

t_data				*init(char **av)
{
	t_data			*data;

	data = NULL;
	if ((data = malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->map = NULL;
	if ((data->map = read_file(av[1])) == NULL)
		fdf_error("Given file is fucked up\n");
	data->map->colors = NULL;
	data->map->pos = NULL;
	if (init_coordinates(data->map) == -1)
		fdf_error("Can't malloc the fuck out of the map\n");
	init_values(data);
	init_keys(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->size_x,
								data->size_y, "FDF");
	data->img = mlx_new_image(data->mlx, data->size_x, data->size_y);
	data->img_data = display_image_info(data->img);
	data->img_data->size_x = data->size_x;
	data->img_data->size_y = data->size_y;
	return (data);
}
