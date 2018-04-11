/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:10:34 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/19 18:08:55 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				key_move_left(t_data *data)
{
	data->offset_x += (data->map->size_x * data->zoom) / 10;
}

void				key_move_down(t_data *data)
{
	data->offset_y -= (data->map->size_y * data->zoom) / 10;
}

void				key_move_right(t_data *data)
{
	data->offset_x -= (data->map->size_x * data->zoom) / 10;
}

void				key_move_up(t_data *data)
{
	data->offset_y += (data->map->size_y * data->zoom) / 10;
}
