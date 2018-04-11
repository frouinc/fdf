/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:16:10 by cfrouin           #+#    #+#             */
/*   Updated: 2018/01/23 12:04:28 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_tab_list			*add_tab_list(t_tab_list *list, char *str)
{
	t_tab_list		*new;
	t_tab_list		*tmp;
	int				i;

	i = 0;
	tmp = list;
	if ((new = malloc(sizeof(t_tab_list))) == NULL)
		return (NULL);
	new->next = NULL;
	new->tab = ft_strsplit(str, ' ');
	while (new->tab[i])
		i++;
	new->size_x = i;
	if (list == NULL)
		return (new);
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

t_map				*map_from_list(t_tab_list *list, int height)
{
	t_map			*map;
	int				i;
	int				j;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	map->size_y = height;
	map->size_x = list->size_x;
	if ((map->map = malloc(sizeof(int*) * height)) == NULL)
		return (NULL);
	i = -1;
	while (++i < map->size_y)
	{
		if ((map->map[i] = malloc(sizeof(int) * map->size_x)) == NULL)
			return (NULL);
		j = -1;
		while (++j < map->size_x)
			map->map[i][j] = ft_atoi(list->tab[j]);
		list = list->next;
	}
	return (map);
}

void				delete_list(t_tab_list *list)
{
	t_tab_list		*tmp;
	int				i;

	while (list)
	{
		i = 0;
		while (list->tab[i])
			free(list->tab[i++]);
		free(list->tab);
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void				check_error(t_tab_list *list)
{
	int				i;

	i = -1;
	while (list)
	{
		if (i == -1)
			i = list->size_x;
		if (i != list->size_x)
			fdf_error("Size_x wrong\n");
		list = list->next;
	}
}

t_map				*read_file(char *str)
{
	t_map			*map;
	char			*line;
	t_tab_list		*list;
	int				fd;
	int				i;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	list = NULL;
	i = 0;
	while (get_next_line(fd, &line))
	{
		list = add_tab_list(list, line);
		free(line);
		check_error(list);
		i++;
	}
	if ((map = map_from_list(list, i)) == NULL)
		return (NULL);
	delete_list(list);
	return (map);
}
