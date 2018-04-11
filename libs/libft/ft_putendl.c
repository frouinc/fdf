/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:45:47 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:34:38 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl(char const *s)
{
	if (s != NULL)
	{
		if (ft_putstr(s) == -1)
			return (-1);
		return ((int)write(1, "\n", 1));
	}
	return (0);
}
