/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:04:16 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/29 16:57:03 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					key_hook(int keycode, t_data *data)
{
	int				i;

	data->change = false;
	i = -1;
	while (++i < 12)
		if (keycode == data->keys[i].keycode)
		{
			data->keys[i].func(data);
			data->change = true;
		}
	return (1);
}
