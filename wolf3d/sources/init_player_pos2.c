/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:56 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:56 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_player_pos5(t_player *player, char *file_name)
{
	if (ft_strcmp(file_name, "./maps/shop.w3d") == 0)
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
		player->pos.x = 1.3;
		player->pos.y = 1.5;
	}
	else if (ft_strcmp(file_name, "./maps/fields.w3d") == 0)
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = -0.66;
		player->plane.y = 0;
		player->pos.x = 27.5;
		player->pos.y = 56.5;
	}
}

void	init_player_pos4(t_player *player, int prevlevel, char *file_name)
{
	if (ft_strcmp(file_name, "./maps/church_place.w3d") == 0
	&& prevlevel == VILLAGE)
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
		player->pos.x = 12.5;
		player->pos.y = 1.5;
	}
	else if (ft_strcmp(file_name, "./maps/church_place.w3d") == 0 &&
	prevlevel == CHURCH)
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = -0.66;
		player->plane.y = 0;
		player->pos.x = 14;
		player->pos.y = 33.5;
	}
}

void	init_player_pos3(t_player *player, int prevlevel, char *file_name)
{
	if (ft_strcmp(file_name, "./maps/village.w3d") == 0 && prevlevel == PLACE)
	{
		player->dir.x = 0;
		player->dir.y = -1;
		player->plane.x = -0.66;
		player->plane.y = 0;
		player->pos.x = 10.5;
		player->pos.y = 18.3;
	}
	else if (ft_strcmp(file_name, "./maps/house.w3d") == 0)
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
		player->pos.x = 6.5;
		player->pos.y = 2.5;
	}
}

void	init_player_pos2(t_player *player, int prevlevel, char *file_name)
{
	if (ft_strcmp(file_name, "./maps/village.w3d") == 0 && prevlevel == SHOP)
	{
		player->dir.x = -1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
		player->pos.x = 12.5;
		player->pos.y = 10.5;
	}
	else if (ft_strcmp(file_name, "./maps/village.w3d") == 0
	&& prevlevel == FIELDS)
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
		player->pos.x = 7.5;
		player->pos.y = 2.3;
	}
}

void	init_player_pos1(t_player *player, int prevlevel, char *file_name)
{
	if (ft_strcmp(file_name, "./maps/church.w3d") == 0)
	{
		player->dir.x = 0;
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
		player->pos.x = 8.5;
		player->pos.y = 2.5;
	}
	else if (ft_strcmp(file_name, "./maps/village.w3d") == 0
	&& prevlevel == HOUSE)
	{
		player->dir.x = 1;
		player->dir.y = 0;
		player->plane.x = 0;
		player->plane.y = -0.66;
		player->pos.x = 2.5;
		player->pos.y = 2.3;
	}
}
