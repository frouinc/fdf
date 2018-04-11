/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:22:08 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/29 17:53:09 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

typedef struct s_data		t_data;

typedef struct				s_key
{
	int						keycode;
	void					(*func)(struct s_data *data);
}							t_key;

/*
** keys_misc.c
*/

void						key_color(t_data *data);
void						key_escape(t_data *data);

/*
** keys_move.c
*/

void						key_move_left(t_data *data);
void						key_move_down(t_data *data);
void						key_move_right(t_data *data);
void						key_move_up(t_data *data);

/*
** keys_rotate.c
*/

void						key_rotate_clock(t_data *data);
void						key_rotate_anti(t_data *data);

/*
** keys_zoom.c
*/

void						key_zoom_in(t_data *data);
void						key_zoom_out(t_data *data);
void						key_amp_in(t_data *data);
void						key_amp_out(t_data *data);

/*
** keys.c
*/

int							key_hook(int keycode, t_data *data);

#endif
