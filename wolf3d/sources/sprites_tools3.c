/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tools3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:15 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:15 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_pos_sprite3(t_boxel **b_map, t_player *player, int i)
{
	if (b_map[0][0].sprite[i].texture < 9)
	{
		Mix_PlayChannel(-1, player->people_die, 0);
		Mix_VolumeChunk(player->people_die, MIX_MAX_VOLUME -
		player->dist_vol_sprite);
	}
	if (b_map[0][0].sprite[i].texture == 21)
	{
		Mix_PlayChannel(-1, player->deer_die, 0);
		Mix_VolumeChunk(player->deer_die, MIX_MAX_VOLUME -
		player->dist_vol_sprite);
		player->items.hp += 10;
		player->items.max_hp = player->items.hp;
	}
	else if (b_map[0][0].sprite[i].texture == 22)
	{
		Mix_VolumeChunk(player->boss_die, MIX_MAX_VOLUME -
		(player->dist_vol_sprite / 2));
		Mix_PlayChannel(-1, player->boss_die, 0);
		Mix_PlayChannel(-1, player->boss_song, 0);
		player->items.boss = 0;
		player->items.hp = player->items.max_hp + 80;
		player->items.max_hp = player->items.hp;
		player->items.money += 1500;
	}
}

void	check_pos_sprite2(t_boxel **b_map, t_player *player, int i)
{
	b_map[0][0].sprite[i].hp -= player->items.strength;
	player->dist_vol_sprite = ((player->pos.x - b_map[0][0].sprite[i].x) *
	(player->pos.x - b_map[0][0].sprite[i].x) + (player->pos.y -
	b_map[0][0].sprite[i].y) * (player->pos.y - b_map[0][0].sprite[i].y));
	if (b_map[0][0].sprite[i].texture == 22)
	{
		Mix_VolumeChunk(player->boss_hit, MIX_MAX_VOLUME -
		player->dist_vol_sprite);
		Mix_PlayChannel(-1, player->boss_hit, 0);
	}
	else
	{
		Mix_VolumeChunk(player->deer_hit, MIX_MAX_VOLUME -
		player->dist_vol_sprite);
		Mix_PlayChannel(-1, player->deer_hit, 0);
	}
	if (b_map[0][0].sprite[i].hp <= 0)
	{
		check_pos_sprite3(b_map, player, i);
		b_map[0][0].sprite[i].show = 0;
		b_map[0][0].killfog = 15;
	}
	else
		b_map[0][0].killfog = 4;
}

int		check_pos_sprite(t_boxel **b_map, t_player *player, int x, int y)
{
	int i;

	i = 0;
	while (i < b_map[0][0].nb_sprites)
	{
		if (b_map[0][0].sprite[i].texture < 9 ||
b_map[0][0].sprite[i].texture == 21 || b_map[0][0].sprite[i].texture == 22)
		{
			if ((int)(b_map[0][0].sprite[i].x) == x &&
(int)(b_map[0][0].sprite[i].y) == y && b_map[0][0].sprite[i].show == 1)
			{
				check_pos_sprite2(b_map, player, i);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	move_sprites_water(t_boxel **b_map, t_player *player, int i)
{
	if ((int)player->pos.x > (int)(b_map[0][0].sprite[i].x) &&
b_map[(int)(b_map[0][0].sprite[i].x + 1.1)]
[(int)(b_map[0][0].sprite[i].y)].door != 1)
		b_map[0][0].sprite[i].x += 0.4;
	else if ((int)player->pos.x < (int)(b_map[0][0].sprite[i].x) &&
b_map[(int)(b_map[0][0].sprite[i].x - 1.1)]
[(int)(b_map[0][0].sprite[i].y)].door != 1)
		b_map[0][0].sprite[i].x -= 0.4;
	if ((int)player->pos.y > (int)(b_map[0][0].sprite[i].y) &&
b_map[(int)(b_map[0][0].sprite[i].x)]
[(int)(b_map[0][0].sprite[i].y + 1.1)].door != 1)
		b_map[0][0].sprite[i].y += 0.4;
	else if ((int)player->pos.y < (int)(b_map[0][0].sprite[i].y) &&
b_map[(int)(b_map[0][0].sprite[i].x)]
[(int)(b_map[0][0].sprite[i].y - 1.1)].door != 1)
		b_map[0][0].sprite[i].y -= 0.4;
}
