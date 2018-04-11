/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_misc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:10:19 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/29 16:56:49 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				key_color(t_data *data)
{
	if (data->color == true)
		data->color = false;
	else
		data->color = true;
}

void				key_escape(t_data *data)
{
	free_memory(data);
	exit(0);
}
