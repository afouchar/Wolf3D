/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:33 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:33 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*select_name(int nb)
{
	if (nb == 1)
		return ("painting");
	else if (nb == 2)
		return ("fireplace");
	else if (nb == 3)
		return ("wallpaper");
	else if (nb == 4)
		return ("floor and ceiling");
	else if (nb == 5)
		return ("hunting trophy");
	else if (nb == 6)
		return ("home decoration");
	else if (nb == 7)
		return ("tool shelf");
	else
		return (" ");
}

void	act_name(t_player *player, t_boxel **b_map)
{
	if (is_owned(player, TOOLSHELF) == 1 && b_map[0][0].islevel == HOUSE
	&& (int)player->pos.x == 6 && (int)player->pos.y == 5)
		player->hud.act = ft_strdup("press 'E' to craft");
	else if (b_map[0][0].islevel == SHOP && (int)player->pos.x == 5
	&& (int)player->pos.y == 2)
		player->hud.act = ft_strdup("press 'E' to shop");
	else if (talk_pos(player, b_map) != -1)
		player->hud.act = ft_strdup("press 'E' to talk");
	else if (loot_pos(player, b_map) != -1)
		player->hud.act = ft_strdup("press 'E' to loot");
	else if (load_level(player, b_map) != NULL)
		player->hud.act = ft_strdup("press 'E' to open");
	else
		player->hud.act = ft_strdup(" ");
}

char	*select_phrase(t_player *player)
{
	int		r;

	if (player->monk_say == 0)
	{
		r = rand() % 4 + 1;
		player->monk_say = r;
	}
	else
		r = player->monk_say;
	if (player->items.boss == 1)
	{
		if (r == 1)
			return ("A giant is somewhere in the fields, please kill him!");
		else if (r == 2)
			return ("The villagers are scared.");
		else if (r == 3)
			return ("You must be stronger to defeat the giant.");
		else
			return ("I will pray for you.");
	}
	else
		return ("Thank You.");
}

void	talk(SDL_Surface **image, t_player *player)
{
	TTF_Font		*font;
	SDL_Rect		talk_object;
	SDL_Surface		*talk_surface;
	SDL_Color		talk_color;
	char			*talk;

	talk = ft_strdup(select_phrase(player));
	font = TTF_OpenFont("kelmscot.ttf", 22);
	talk_object = create_rect(WINW2 -
	((ft_strlen(talk) * 10) / 2), 390, 120, 90);
	talk_color = set_font_color(212, 212, 212, 255);
	talk_surface = TTF_RenderText_Blended(font, talk, talk_color);
	SDL_BlitSurface(talk_surface, NULL, (*image), &talk_object);
	SDL_FreeSurface(talk_surface);
	TTF_CloseFont(font);
	free(talk);
}
