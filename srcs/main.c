/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:32:27 by cfrouin           #+#    #+#             */
/*   Updated: 2018/01/19 18:12:30 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				fdf_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

int					main(int ac, char **av)
{
	t_data			*data;

	if (ac != 2)
		fdf_error("Usage : ./fdf file\n");
	data = init(av);
	mlx_key_hook(data->win, &key_hook, (void*)data);
	mlx_loop_hook(data->mlx, &loop, (void*)data);
	mlx_loop(data->mlx);
	return (1);
}
