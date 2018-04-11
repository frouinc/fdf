/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:00:58 by cfrouin           #+#    #+#             */
/*   Updated: 2018/01/29 16:58:18 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img_data			*display_image_info(void *img)
{
	char			*start;
	int				bpp;
	int				size;
	int				endian;
	t_img_data		*data;

	if ((data = malloc(sizeof(t_img_data))) == NULL)
		return (NULL);
	start = mlx_get_data_addr(img, &bpp, &size, &endian);
	data->start = start;
	data->bpp = bpp;
	data->size = size;
	data->endian = endian;
	return (data);
}

static void			reset_pos(t_pos *pos1, t_pos *pos2, int x, int y)
{
	pos1->x = x;
	pos1->y = y;
	pos2->x = x;
	pos2->y = y;
}

void				draw_map_to_image_pos(t_data *data, int x, int y)
{
	t_pos			pos1;
	t_pos			pos2;

	reset_pos(&pos1, &pos2, x, y);
	if (x + 1 < data->map->size_x)
	{
		if (data->map->map[y][x] > data->map->map[y][x + 1])
			pos1.x = x + 1;
		else
			pos2.x = x + 1;
		put_line_in_image(data, &pos1, &pos2);
	}
	reset_pos(&pos1, &pos2, x, y);
	if (y + 1 < data->map->size_y)
	{
		if (data->map->map[y][x] > data->map->map[y + 1][x])
			pos1.y = y + 1;
		else
			pos2.y = y + 1;
		put_line_in_image(data, &pos1, &pos2);
	}
}

void				draw_map_to_image(t_data *data)
{
	int				x;
	int				y;

	y = -1;
	while (++y < data->map->size_y)
	{
		x = -1;
		while (++x < data->map->size_x)
			draw_map_to_image_pos(data, x, y);
	}
}

int					loop(void *param)
{
	t_data			*data;
	unsigned int	x;

	x = 0;
	data = (t_data*)param;
	if (data->change)
	{
		calculate_coordinates(data);
		calculate_colors(data);
		bzero(data->img_data->start, data->img_data->size * data->size_y);
		draw_map_to_image(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		data->change = false;
	}
	return (1);
}
