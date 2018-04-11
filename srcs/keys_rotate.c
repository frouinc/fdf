/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:10:28 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/15 15:17:02 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				key_rotate_clock(t_data *data)
{
	data->angle -= 30;
}

void				key_rotate_anti(t_data *data)
{
	data->angle += 30;
}
