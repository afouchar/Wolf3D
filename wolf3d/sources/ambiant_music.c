/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_music.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 00:59:43 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 00:59:43 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	play_music2(t_player *player, t_boxel **b_map)
{
	if (b_map[0][0].islevel == VILLAGE && b_map[0][0].cur_music != VILLAGE)
	{
		b_map[0][0].cur_music = VILLAGE;
		b_map[0][0].bgm = Mix_LoadMUS("./sounds/village.wav");
		Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		Mix_PlayMusic(b_map[0][0].bgm, -1);
	}
	else if (b_map[0][0].islevel == PLACE && b_map[0][0].cur_music != PLACE)
	{
		b_map[0][0].cur_music = PLACE;
		b_map[0][0].bgm = Mix_LoadMUS("./sounds/church_place.wav");
		Mix_VolumeMusic(MIX_MAX_VOLUME);
		Mix_PlayMusic(b_map[0][0].bgm, -1);
	}
	else if (b_map[0][0].islevel == HOUSE && b_map[0][0].cur_music != HOUSE)
	{
		b_map[0][0].cur_music = HOUSE;
		b_map[0][0].bgm = Mix_LoadMUS("./sounds/house.wav");
		if (is_owned(player, FLOOR) == 1)
			Mix_VolumeMusic(MIX_MAX_VOLUME / 20);
		else
			Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
		Mix_PlayMusic(b_map[0][0].bgm, -1);
	}
}

void	play_music(t_player *player, t_boxel **b_map)
{
	if (b_map[0][0].islevel == FIELDS && b_map[0][0].cur_music != FIELDS)
	{
		b_map[0][0].cur_music = FIELDS;
		b_map[0][0].bgm = Mix_LoadMUS("./sounds/fields.wav");
		Mix_PlayMusic(b_map[0][0].bgm, -1);
	}
	else if (b_map[0][0].islevel == SHOP && b_map[0][0].cur_music != SHOP)
	{
		b_map[0][0].cur_music = SHOP;
		b_map[0][0].bgm = Mix_LoadMUS("./sounds/shop.wav");
		Mix_PlayMusic(b_map[0][0].bgm, -1);
	}
	else if (b_map[0][0].islevel == CHURCH && b_map[0][0].cur_music != CHURCH)
	{
		b_map[0][0].cur_music = CHURCH;
		b_map[0][0].bgm = Mix_LoadMUS("./sounds/church.wav");
		Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
		Mix_PlayMusic(b_map[0][0].bgm, -1);
	}
	else
		play_music2(player, b_map);
}

void	walk_standard(t_player *player, t_boxel **b_map)
{
	if (!Mix_Playing(b_map[0][0].cur_walk))
	{
		Mix_VolumeChunk(player->walk_village, MIX_MAX_VOLUME / 2);
		b_map[0][0].cur_walk = Mix_PlayChannel(-1, player->walk_village, 0);
	}
}

void	walk_fields(t_player *player, t_boxel **b_map)
{
	if (b_map[(int)player->pos.x][(int)player->pos.y].floor == 0
	|| (b_map[(int)player->pos.x][(int)player->pos.y].floor >= 65
	&& b_map[(int)player->pos.x][(int)player->pos.y].floor <= 76))
	{
		if (!Mix_Playing(b_map[0][0].cur_walk))
		{
			Mix_VolumeChunk(player->walk_water, MIX_MAX_VOLUME / 2);
			b_map[0][0].cur_walk = Mix_PlayChannel(-1, player->walk_water, 0);
		}
	}
	else
	{
		if (!Mix_Playing(b_map[0][0].cur_walk))
		{
			Mix_VolumeChunk(player->walk_grass, MIX_MAX_VOLUME / 3);
			b_map[0][0].cur_walk = Mix_PlayChannel(-1, player->walk_grass, 0);
		}
	}
}

void	walk_sound(t_player *player, t_boxel **b_map)
{
	if (b_map[0][0].islevel == CHURCH)
	{
		if (!Mix_Playing(b_map[0][0].cur_walk))
		{
			Mix_VolumeChunk(player->walk_church, MIX_MAX_VOLUME / 2);
			b_map[0][0].cur_walk = Mix_PlayChannel(-1, player->walk_church, 0);
		}
	}
	else if (b_map[0][0].islevel == FIELDS)
		walk_fields(player, b_map);
	else if (b_map[0][0].islevel == HOUSE)
	{
		if (!Mix_Playing(b_map[0][0].cur_walk))
		{
			Mix_VolumeChunk(player->walk_house, MIX_MAX_VOLUME / 2);
			b_map[0][0].cur_walk = Mix_PlayChannel(-1, player->walk_house, 0);
		}
	}
	else
		walk_standard(player, b_map);
}
