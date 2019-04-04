/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:42 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:42 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_loot(t_player *player, int loot)
{
	int		rm;
	int		rt;

	rm = rand() % 30 + 6;
	rt = rand() % 5 + 1;
	if (loot == PURSE)
	{
		Mix_VolumeChunk(player->loot_money, MIX_MAX_VOLUME / 2);
		Mix_PlayChannel(1, player->loot_money, 0);
		player->items.money += rm;
	}
	else if (loot == TOOLBOX)
	{
		Mix_VolumeChunk(player->loot_toolbox, MIX_MAX_VOLUME / 4);
		Mix_PlayChannel(1, player->loot_toolbox, 0);
		player->items.toolbox += rt;
	}
}

int		talk_pos(t_player *player, t_boxel **b_map)
{
	int		i;

	i = 0;
	while (i < b_map[0][0].nb_sprites)
	{
		if (b_map[0][0].sprite[i].texture == 4)
		{
			if (((int)player->pos.x + 1 == (int)b_map[0][0].sprite[i].x
			&& (int)player->pos.y == (int)b_map[0][0].sprite[i].y)
			|| ((int)player->pos.x == (int)b_map[0][0].sprite[i].x
			&& (int)player->pos.y + 1 == (int)b_map[0][0].sprite[i].y))
				return (i);
			else if (((int)player->pos.x - 1 == (int)b_map[0][0].sprite[i].x
			&& (int)player->pos.y == (int)b_map[0][0].sprite[i].y)
			|| ((int)player->pos.x == (int)b_map[0][0].sprite[i].x
			&& (int)player->pos.y - 1 == (int)b_map[0][0].sprite[i].y))
				return (i);
			else if ((int)player->pos.x == (int)b_map[0][0].sprite[i].x
			&& (int)player->pos.y == (int)b_map[0][0].sprite[i].y)
				return (i);
		}
		i++;
	}
	return (-1);
}

void	player_hit(t_player *player, t_boxel **b_map)
{
	int		r;

	r = rand() % 3 + 1;
	if (water_animation(b_map) % 3 == 0)
	{
		if (r == 1)
			Mix_PlayChannel(1, player->hit_1, 0);
		else if (r == 2)
			Mix_PlayChannel(1, player->hit_2, 0);
		else if (r == 3)
			Mix_PlayChannel(1, player->hit_3, 0);
		player->items.hp -= 20;
	}
}

int		loot_pos(t_player *player, t_boxel **b_map)
{
	int		i;

	i = 0;
	while (i < b_map[0][0].nb_sprites)
	{
		if ((int)player->pos.x == (int)b_map[0][0].sprite[i].x
		&& (int)player->pos.y == (int)b_map[0][0].sprite[i].y)
		{
			if (b_map[0][0].sprite[i].loot == 1
			&& b_map[0][0].sprite[i].show == 1)
				return (i);
			else if (b_map[0][0].sprite[i].texture == 22
			&& b_map[0][0].sprite[i].show == 1)
			{
				player_hit(player, b_map);
				return (-1);
			}
		}
		i++;
	}
	return (-1);
}

void	loot_objects(t_player *player, t_boxel **b_map)
{
	int		i;

	i = loot_pos(player, b_map);
	if (i != -1)
	{
		get_loot(player, b_map[0][0].sprite[i].texture);
		b_map[0][0].sprite[i].loot = 0;
		b_map[0][0].sprite[i].show = 0;
	}
}
