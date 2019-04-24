/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:45 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:45 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_crosshair(t_player *player, SDL_Rect *srcrect)
{
	if (player->testweapon != 0)
	{
		srcrect->y = 0;
		srcrect->x = (6 - player->testweapon) * 800;
		if (srcrect->x >= 2400)
			srcrect->x = 0;
		if (player->testweapon < 3)
			srcrect->y = 600;
		srcrect->h = 600;
		srcrect->w = 800;
		player->anim++;
		if (player->anim % 2 == 0)
			player->testweapon--;
	}
	else
	{
		player->anim = 0;
		srcrect->x = 0;
		srcrect->y = 0;
		srcrect->h = 600;
		srcrect->w = 800;
	}
}

void	ft_draw_crosshair(SDL_Surface *image, t_boxel **b_map, t_player *player)
{
	SDL_Rect	srcrect;
	SDL_Rect	dstrect;

	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.h = 600;
	dstrect.w = 800;
	if (b_map[0][0].islevel != SHOP && b_map[0][0].islevel != HOUSE
	&& b_map[0][0].islevel != CHURCH)
	{
		init_crosshair(player, &srcrect);
		SDL_SetColorKey(b_map[0][0].tex_weapon[player->items.weapon], SDL_TRUE,
SDL_MapRGB(b_map[0][0].tex_weapon[player->items.weapon]->format, 0, 255, 255));
		SDL_BlitSurface(b_map[0][0].tex_weapon[player->items.weapon], &srcrect,
		image, &dstrect);
	}
}

void	init_shoot(t_boxel **b_map, t_player *player)
{
	int i;

	i = 0;
	b_map[0][0].shoot.act = 10;
	b_map[0][0].shoot.dir.x = player->dir.x;
	b_map[0][0].shoot.dir.y = player->dir.y;
	b_map[0][0].shoot.pos.x = player->pos.x;
	b_map[0][0].shoot.pos.y = player->pos.y;
	b_map[0][0].shoot.move_speed = player->move_speed * 3;
	while (i < b_map[0][0].nb_sprites)
	{
		if (b_map[0][0].sprite[i].texture == 13)
		{
			b_map[0][0].sprite[i].x = player->pos.x;
			b_map[0][0].sprite[i].y = player->pos.y;
			b_map[0][0].sprite[i].show = 1;
		}
		i++;
	}
	player->testweapon = 5;
	player->items.ammo--;
}
