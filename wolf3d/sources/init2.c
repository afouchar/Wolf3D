/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:21 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:21 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		init_win(t_window *win)
{
	win->state = SDL_WINDOW_SHOWN;
	win->title = "wolf3d";
	win->width = 800;
	win->height = 600;
	win->posx = SDL_WINDOWPOS_CENTERED;
	win->posy = SDL_WINDOWPOS_CENTERED;
	win->run = 1;
	win->win = SDL_CreateWindow(win->title, win->posx, win->posy,
	win->width, win->height, win->state);
	if (win->win == NULL)
		return (-1);
	return (0);
}

void	init_win_surface(t_win_surface *ws, t_window *win, t_player *player)
{
	ws->centerx = (win->width / 2);
	ws->centery = (win->height / 2);
	ws->distance = ws->centerx / tan(player->fov / 2);
	ws->row_angle = (player->fov / win->width);
}

void	values_boxel(t_boxel *boxel, char **num)
{
	boxel->wall = ft_atoi(num[0]);
	boxel->texn = ft_atoi(num[1]);
	boxel->texe = ft_atoi(num[2]);
	boxel->texs = ft_atoi(num[3]);
	boxel->texw = ft_atoi(num[4]);
	boxel->texmid = ft_atoi(num[5]);
	boxel->textop = ft_atoi(num[6]);
	boxel->floor = ft_atoi(num[7]);
	boxel->ceiling = ft_atoi(num[8]);
	boxel->door = ft_atoi(num[9]);
	boxel->values = NULL;
	boxel->textures = NULL;
}

t_boxel	create_boxel(char *str)
{
	int		i;
	char	**num;
	t_boxel	boxel;

	i = 0;
	num = ft_strsplit(str, '.');
	free(str);
	values_boxel(&boxel, num);
	while (i < 10)
	{
		free(num[i]);
		i++;
	}
	free(num);
	return (boxel);
}

int		*get_values(t_boxel **boxel)
{
	int		*values;
	int		i;

	i = 0;
	values = (int *)malloc(sizeof(int) * (boxel[0][0].lines + 1));
	while (i < boxel[0][0].lines)
	{
		values[i] = boxel[i][0].lines;
		i++;
	}
	return (values);
}
