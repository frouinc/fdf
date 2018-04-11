/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:55:36 by cfrouin           #+#    #+#             */
/*   Updated: 2018/01/29 17:52:08 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

# define DEGREESTORADIANS(angleDegrees) ((angleDegrees) * M_PI / 180.0)
# define RADIANSTODEGREES(angleRadians) ((angleRadians) * 180.0 / M_PI)

typedef struct				s_line
{
	t_pos					p;
	t_pos					p0;
	t_pos					p1;
	t_pos					d;
	t_pos					s;
	t_pos					e;
}							t_line;

typedef struct				s_img_data
{
	int						size_x;
	int						size_y;
	char					*start;
	int						bpp;
	int						size;
	int						endian;
}							t_img_data;

typedef struct				s_map
{
	int						size_x;
	int						size_y;
	int						highest;
	int						lowest;
	int						delta;
	int						**map;
	int						**colors;
	t_pos					**pos;
}							t_map;

typedef struct				s_tab_list
{
	char					**tab;
	int						size_x;
	struct s_tab_list		*next;
}							t_tab_list;

typedef struct				s_data
{
	t_map					*map;
	int						size_x;
	int						size_y;
	int						offset_x;
	int						offset_y;
	double					amp;
	int						angle;
	int						zoom;
	bool					change;
	bool					color;
	struct s_key			keys[12];
	void					*mlx;
	void					*win;
	void					*img;
	t_img_data				*img_data;
}							t_data;

/*
** init.c
*/

t_data						*init(char **av);

/*
** coordinates.c
*/

int							init_coordinates(t_map *map);
void						calculate_colors(t_data *data);
void						calculate_coordinates(t_data *data);

/*
** draw.c
*/

void						put_pixel_in_image(t_img_data *img,
								unsigned int color, int x, int y);
void						put_line_in_image(t_data *data,
								t_pos *p1, t_pos *p2);

/*
** read_file.c
*/

t_map						*read_file(char *str);

/*
** display.c
*/

void						draw_map_to_image(t_data *data);
t_img_data					*display_image_info(void *img);
int							loop(void *param);

/*
** free_memory.c
*/

void						free_memory(t_data *data);

/*
** main.c
*/

void						fdf_error(char *str);

#endif
