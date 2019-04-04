/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_house.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:13 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:13 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_deco_bis(t_boxel **b_map, t_point pt)
{
	if (b_map[pt.x][pt.y].texw == 10)
		b_map[pt.x][pt.y].texw = 49;
	if (b_map[pt.x][pt.y].texn == 10)
		b_map[pt.x][pt.y].texn = 49;
	if (b_map[pt.x][pt.y].texs == 10)
		b_map[pt.x][pt.y].texs = 49;
	if (b_map[pt.x][pt.y].texe == 10)
		b_map[pt.x][pt.y].texe = 49;
	if (b_map[6][4].floor == 2)
		b_map[6][4].floor = 52;
	if (b_map[6][3].floor == 2)
		b_map[6][3].floor = 53;
}

void	get_deco(t_player *player, t_boxel **b_map)
{
	t_point		pt;

	pt = create_point(0, 0);
	if (is_owned(player, DECO) == 1 && b_map[0][0].islevel == HOUSE)
	{
		b_map[0][0].sprite = (t_sprite *)malloc(sizeof(t_sprite) * (3));
		b_map[0][0].sprite[0] = create_sprite_line("2.5 3.5 12", b_map);
		b_map[0][0].sprite[1] = create_sprite_line("1.5 7.5 12", b_map);
		b_map[0][0].nb_sprites = 2;
		while (pt.x < b_map[0][0].lines)
		{
			while (pt.y < b_map[0][0].values[pt.x])
			{
				get_deco_bis(b_map, pt);
				pt.y++;
			}
			pt.y = 0;
			pt.x++;
		}
	}
}

void	get_wall_stuff(t_boxel **b_map, t_point pt)
{
	if (b_map[pt.x][pt.y].texs == 39)
		b_map[pt.x][pt.y].texs = 38;
	if (b_map[pt.x][pt.y].texw == 4)
		b_map[pt.x][pt.y].texw = 41;
	if (b_map[pt.x][pt.y].texs == 36)
		b_map[pt.x][pt.y].texs = 42;
	if (b_map[pt.x][pt.y].texn == 36)
		b_map[pt.x][pt.y].texn = 42;
	if (b_map[pt.x][pt.y].texw == 35)
		b_map[pt.x][pt.y].texw = 43;
	if (b_map[pt.x][pt.y].texe == 47)
		b_map[pt.x][pt.y].texe = 48;
	if (b_map[pt.x][pt.y].texw == 49)
		b_map[pt.x][pt.y].texw = 50;
	if (b_map[pt.x][pt.y].texn == 49)
		b_map[pt.x][pt.y].texn = 50;
	if (b_map[pt.x][pt.y].texs == 49)
		b_map[pt.x][pt.y].texs = 50;
	if (b_map[pt.x][pt.y].texe == 49)
		b_map[pt.x][pt.y].texe = 50;
}

void	get_wallpaper(t_player *player, t_boxel **b_map)
{
	t_point		pt;

	pt = create_point(0, 0);
	if (is_owned(player, PAPER) == 1 && b_map[0][0].islevel == HOUSE)
	{
		while (pt.x < b_map[0][0].lines)
		{
			while (pt.y < b_map[0][0].values[pt.x])
			{
				if (b_map[pt.x][pt.y].texw == 10)
					b_map[pt.x][pt.y].texw = 37;
				if (b_map[pt.x][pt.y].texn == 10)
					b_map[pt.x][pt.y].texn = 37;
				if (b_map[pt.x][pt.y].texs == 10)
					b_map[pt.x][pt.y].texs = 37;
				if (b_map[pt.x][pt.y].texe == 10)
					b_map[pt.x][pt.y].texe = 37;
				get_wall_stuff(b_map, pt);
				pt.y++;
			}
			pt.y = 0;
			pt.x++;
		}
	}
}

void	get_floor_ceiling(t_player *player, t_boxel **b_map)
{
	t_point		pt;

	pt = create_point(0, 0);
	if (is_owned(player, FLOOR) == 1 && b_map[0][0].islevel == HOUSE)
	{
		while (pt.x < b_map[0][0].lines)
		{
			while (pt.y < b_map[0][0].values[pt.x])
			{
				b_map[pt.x][pt.y].floor = 44;
				b_map[pt.x][pt.y].ceiling = 45;
				if (pt.x == 6)
				{
					if (pt.y == 4)
						b_map[pt.x][pt.y].floor = 54;
					else if (pt.y == 3)
						b_map[pt.x][pt.y].floor = 55;
				}
				pt.y++;
			}
			pt.y = 0;
			pt.x++;
		}
	}
}
