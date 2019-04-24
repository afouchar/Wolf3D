/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:03 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:03 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void		init_player_song2(t_player *player)
{
	player->craft_arrow = Mix_LoadWAV("./sounds/craft_arrow.wav");
	player->monk_haaa = Mix_LoadWAV("./sounds/monk_haaa.wav");
	player->monk_yes = Mix_LoadWAV("./sounds/monk_yes.wav");
	player->monk_try = Mix_LoadWAV("./sounds/monk_try.wav");
	player->monk_morning = Mix_LoadWAV("./sounds/monk_morning.wav");
	player->hit_1 = Mix_LoadWAV("./sounds/hit_1.wav");
	player->hit_2 = Mix_LoadWAV("./sounds/hit_2.wav");
	player->hit_3 = Mix_LoadWAV("./sounds/hit_3.wav");
	player->walk_church = Mix_LoadWAV("./sounds/walk_church.wav");
	player->walk_grass = Mix_LoadWAV("./sounds/walk_grass.wav");
	player->walk_house = Mix_LoadWAV("./sounds/walk_house.wav");
	player->walk_village = Mix_LoadWAV("./sounds/walk_village.wav");
	player->walk_water = Mix_LoadWAV("./sounds/walk_water.wav");
	player->loot_money = Mix_LoadWAV("./sounds/loot_money.wav");
	player->loot_toolbox = Mix_LoadWAV("./sounds/loot_toolbox.wav");
}

void		init_player_song(t_player *player)
{
	player->arrow = Mix_LoadWAV("./sounds/arrow_shot.wav");
	player->boss_hit = Mix_LoadWAV("./sounds/boss_hit.wav");
	player->boss_die = Mix_LoadWAV("./sounds/boss_die.wav");
	player->deer_hit = Mix_LoadWAV("./sounds/deer_hit.wav");
	player->deer_die = Mix_LoadWAV("./sounds/deer_die.wav");
	player->book_open = Mix_LoadWAV("./sounds/book_open.wav");
	player->book_close = Mix_LoadWAV("./sounds/book_close.wav");
	player->door_open = Mix_LoadWAV("./sounds/door_open.wav");
	player->coin_shop = Mix_LoadWAV("./sounds/coin_shop.wav");
	player->coin_shop_empty = Mix_LoadWAV("./sounds/coin_shop_empty.wav");
	player->coin_shop_already = Mix_LoadWAV("./sounds/coin_shop_already.wav");
	player->people_die = Mix_LoadWAV("./sounds/people_die.wav");
	player->light = Mix_LoadWAV("./sounds/light.wav");
	player->boss_song = Mix_LoadWAV("./sounds/boss_song.wav");
	player->craft_weapon = Mix_LoadWAV("./sounds/craft_weapon.wav");
}

void		init_player_values(t_player *player)
{
	player->plane.y = 0.66;
	player->height = 5;
	player->angle = 45;
	player->side = 0;
	player->mapx = 0;
	player->mapy = 0;
	player->anglesky = 0;
	player->testweapon = 0;
	player->testshoot = 0;
	player->anim = 0;
	player->monk_say = 0;
	player->dash = 5;
}

t_player	init_player(char *file_name, int prevlevel)
{
	t_player	player;

	player.p_time = 0;
	player.old_time = 0;
	player.frame_time = (player.p_time - player.old_time) / 1000.0;
	if (player.frame_time > 0.2)
		player.frame_time = 0.2;
	player.move_speed = player.frame_time * MV_SPEED;
	player.rot_speed = player.frame_time * ROT_SPEED;
	player.fov = 60;
	player.rotate = 0;
	player.pos.x = 1.3;
	player.pos.y = 1.3;
	player.dir.x = -1;
	player.dir.y = 0;
	player.plane.x = 0;
	init_player_values(&player);
	player.dist_vol_sprite = MIX_MAX_VOLUME;
	init_player_song(&player);
	init_player_song2(&player);
	init_player_pos(&player, prevlevel, file_name);
	return (player);
}
