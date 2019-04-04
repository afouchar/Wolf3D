/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_b_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:40 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:40 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_music2(t_player *p)
{
	Mix_FreeChunk(p->loot_toolbox);
	Mix_FreeChunk(p->arrow);
	Mix_FreeChunk(p->boss_hit);
	Mix_FreeChunk(p->boss_die);
	Mix_FreeChunk(p->deer_hit);
	Mix_FreeChunk(p->deer_die);
	Mix_FreeChunk(p->book_open);
	Mix_FreeChunk(p->book_close);
	Mix_FreeChunk(p->door_open);
	Mix_FreeChunk(p->coin_shop);
	Mix_FreeChunk(p->coin_shop_empty);
	Mix_FreeChunk(p->coin_shop_already);
	Mix_FreeChunk(p->people_die);
	Mix_FreeChunk(p->light);
	Mix_FreeChunk(p->boss_song);
	Mix_FreeChunk(p->craft_weapon);
}

void	free_music(t_player *p)
{
	Mix_FreeChunk(p->craft_arrow);
	Mix_FreeChunk(p->monk_haaa);
	Mix_FreeChunk(p->monk_yes);
	Mix_FreeChunk(p->monk_try);
	Mix_FreeChunk(p->monk_morning);
	Mix_FreeChunk(p->hit_1);
	Mix_FreeChunk(p->hit_2);
	Mix_FreeChunk(p->hit_3);
	Mix_FreeChunk(p->walk_church);
	Mix_FreeChunk(p->walk_grass);
	Mix_FreeChunk(p->walk_house);
	Mix_FreeChunk(p->walk_village);
	Mix_FreeChunk(p->walk_water);
	Mix_FreeChunk(p->loot_money);
	free_music2(p);
}

void	free_b_map2(t_boxel **b_map)
{
	int i;

	i = 0;
	while (i < 24)
	{
		SDL_FreeSurface(b_map[0][0].tex_sprite[i]);
		i++;
	}
	free(b_map[0][0].tex_sprite);
	i = 0;
	while (i < 3)
	{
		SDL_FreeSurface(b_map[0][0].tex_weapon[i]);
		i++;
	}
	free(b_map[0][0].tex_weapon);
}

void	free_b_map(t_boxel **b_map)
{
	int i;

	i = 0;
	while (i < 6)
	{
		SDL_FreeSurface(b_map[0][0].tex_sky[i]);
		i++;
	}
	i = 0;
	free(b_map[0][0].tex_sky);
	while (i < 100)
	{
		SDL_FreeSurface(b_map[0][0].textures[i]);
		i++;
	}
	free(b_map[0][0].textures);
	free_b_map2(b_map);
}
