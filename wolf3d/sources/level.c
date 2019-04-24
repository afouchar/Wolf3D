/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:53 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:53 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*load_h_s_f(t_boxel **b, t_point *pt, t_point *pos)
{
	if (b[0][0].islevel == HOUSE && b[pt->x][pos->y - 1].texe == 4)
		return ("./maps/village.w3d");
	else if (b[0][0].islevel == HOUSE && b[pos->x][pt->y - 1].texe == 4)
		return ("./maps/village.w3d");
	else if (b[0][0].islevel == SHOP && b[pt->x - 1][pos->y].texs == 6)
		return ("./maps/village.w3d");
	else if (b[0][0].islevel == SHOP && b[pos->x - 1][pt->y].texs == 6)
		return ("./maps/village.w3d");
	else if (b[0][0].islevel == FIELDS && b[pt->x][pos->y + 1].texw == 5)
		return ("./maps/village.w3d");
	else if (b[0][0].islevel == FIELDS && b[pos->x][pt->y + 1].texw == 5)
		return ("./maps/village.w3d");
	else
		return (NULL);
}

char	*load_village(t_boxel **b, t_point *pt, t_point *pos)
{
	if (b[0][0].islevel == VILLAGE && b[pt->x][pos->y + 1].texe == 5)
		return ("./maps/church_place.w3d");
	else if (b[0][0].islevel == VILLAGE && b[pos->x][pt->y + 1].texe == 5)
		return ("./maps/church_place.w3d");
	else if (b[0][0].islevel == VILLAGE && b[pt->x][pos->y - 1].texw == 5)
		return ("./maps/fields.w3d");
	else if (b[0][0].islevel == VILLAGE && b[pos->x][pt->y - 1].texw == 5)
		return ("./maps/fields.w3d");
	else if (b[0][0].islevel == VILLAGE && b[pt->x + 1][pos->y].texn == 6)
		return ("./maps/shop.w3d");
	else if (b[0][0].islevel == VILLAGE && b[pos->x + 1][pt->y].texn == 6)
		return ("./maps/shop.w3d");
	else if (b[0][0].islevel == VILLAGE && b[pt->x - 1][pos->y].texs == 4)
		return ("./maps/house.w3d");
	else if (b[0][0].islevel == VILLAGE && b[pos->x - 1][pt->y].texs == 4)
		return ("./maps/house.w3d");
	else
		return (NULL);
}

char	*load_church(t_boxel **b, t_point *pt, t_point *pos)
{
	if (b[0][0].islevel == PLACE && b[pt->x][pos->y + 1].texe == 14)
		return ("./maps/church.w3d");
	else if (b[0][0].islevel == PLACE && b[pos->x][pt->y + 1].texe == 14)
		return ("./maps/church.w3d");
	else if (b[0][0].islevel == PLACE && b[pt->x][pos->y - 1].texw == 5)
		return ("./maps/village.w3d");
	else if (b[0][0].islevel == PLACE && b[pos->x][pt->y - 1].texw == 5)
		return ("./maps/village.w3d");
	else if (b[0][0].islevel == CHURCH && b[pt->x][pos->y - 1].texw == 12)
		return ("./maps/church_place.w3d");
	else if (b[0][0].islevel == CHURCH && b[pos->x][pt->y - 1].texw == 12)
		return ("./maps/church_place.w3d");
	else
		return (NULL);
}

char	*load_level(t_player *player, t_boxel **b_map)
{
	char	*level;
	t_point	pt;
	t_point	pos;

	pos.x = (int)(player->pos.x);
	pos.y = (int)(player->pos.y);
	pt.x = (int)(player->pos.x + player->dir.x * player->move_speed);
	pt.y = (int)(player->pos.y + player->dir.y * player->move_speed);
	if (out_of_level(player, b_map) == 0)
	{
		player->prevlevel = b_map[0][0].islevel;
		level = load_church(b_map, &pt, &pos);
		if (level == NULL)
			level = load_village(b_map, &pt, &pos);
		if (level == NULL)
			level = load_h_s_f(b_map, &pt, &pos);
		if (level != NULL)
			return (level);
	}
	return (NULL);
}
