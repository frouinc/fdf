/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 12:51:16 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/29 17:50:22 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel_in_image(t_img_data *img, unsigned int color,
									int x, int y)
{
	int			pos;

	if (x < 0 || x >= img->size_x || y < 0 || y >= img->size_y)
		return ;
	pos = (y * img->size) + 4 * x;
	img->start[pos] = color & 0x0000ff;
	img->start[pos + 1] = (color & 0x00ff00) >> 8;
	img->start[pos + 2] = (color & 0xff0000) >> 16;
}

static int		color(t_data *data, t_pos *p0, t_pos *p1, double ratio)
{
	int			dr;
	int			db;
	int			result;

	if (data->map->colors[p1->y][p1->x] == data->map->colors[p0->y][p0->x])
		return (data->map->colors[p1->y][p1->x]);
	dr = ((data->map->colors[p1->y][p1->x] & 0xFF0000) >> 16)
		- ((data->map->colors[p0->y][p0->x] & 0xFF0000) >> 16);
	db = (data->map->colors[p1->y][p1->x] & 0x0000FF)
		- (data->map->colors[p0->y][p0->x] & 0x0000FF);
	dr = abs(dr);
	db = abs(db);
	dr *= (1 - ratio);
	db *= ratio;
	result = ((((data->map->colors[p0->y][p0->x] & 0xFF0000) >> 16)
		+ dr) << 16);
	result += (data->map->colors[p0->y][p0->x] & 0x0000FF) + db;
	return (result);
}

static void		init_line(t_data *data, t_pos *pos0, t_pos *pos1, t_line *l)
{
	l->p0.x = data->map->pos[pos0->y][pos0->x].x;
	l->p0.y = data->map->pos[pos0->y][pos0->x].y;
	l->p1.x = data->map->pos[pos1->y][pos1->x].x;
	l->p1.y = data->map->pos[pos1->y][pos1->x].y;
	l->p.x = l->p0.x;
	l->p.y = l->p0.y;
	l->s.x = l->p0.x < l->p1.x ? 1 : -1;
	l->s.y = l->p0.y < l->p1.y ? 1 : -1;
	l->d.x = abs(l->p1.x - l->p0.x);
	l->d.y = abs(l->p1.y - l->p0.y);
	l->e.x = (l->d.x > l->d.y ? l->d.x : -l->d.y) / 2;
}

static void		put_lpoint(t_data *data, t_pos *pos0, t_pos *pos1, t_line *l)
{
	double		ratio;

	if (data->color == true)
	{
		ratio = 1;
		if (l->p1.x - l->p.x != 0)
			ratio = (double)(l->p0.x - l->p.x) / (double)(l->p1.x - l->p.x);
		put_pixel_in_image(data->img_data, color(data, pos0, pos1, ratio),
			l->p0.x, l->p0.y);
	}
	else
		put_pixel_in_image(data->img_data, 0xffffff, l->p0.x, l->p0.y);
	l->e.y = l->e.x;
	if (l->e.y > -l->d.x)
	{
		l->e.x -= l->d.y;
		l->p0.x += l->s.x;
	}
	if (l->e.y < l->d.y)
	{
		l->e.x += l->d.x;
		l->p0.y += l->s.y;
	}
}

void			put_line_in_image(t_data *data, t_pos *pos0, t_pos *pos1)
{
	t_line		l;

	init_line(data, pos0, pos1, &l);
	while (l.p0.x != l.p1.x || l.p0.y != l.p1.y)
	{
		put_lpoint(data, pos0, pos1, &l);
	}
	if (data->color == true)
		put_pixel_in_image(data->img_data, data->map->colors[pos1->y][pos1->x],
			l.p0.x, l.p0.y);
	else
		put_pixel_in_image(data->img_data, 0xffffff, l.p0.x, l.p0.y);
}
