/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:10:25 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/23 12:07:25 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				key_zoom_in(t_data *data)
{
	data->zoom += 5;
}

void				key_zoom_out(t_data *data)
{
	if (data->zoom > 5)
		data->zoom -= 5;
}

void				key_amp_in(t_data *data)
{
	data->amp *= 2;
}

void				key_amp_out(t_data *data)
{
	data->amp /= 2;
}
