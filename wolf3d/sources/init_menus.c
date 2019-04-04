/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:11 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:11 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_menu	init_menu(void)
{
	t_menu	m;

	m.img = create_rect(100, 80, 120, 90);
	m.object = create_rect(0, 0, 120, 90);
	m.select = create_rect(0, 0, 124, 94);
	m.hover = create_rect(98, 78, 124, 94);
	m.text_object = create_rect(240, 120, 120, 90);
	m.price_object = create_rect(240, 155, 120, 90);
	m.wallet_object = create_rect(580, 500, 120, 90);
	m.wallet_color = set_font_color(32, 32, 32, 255);
	m.font = TTF_OpenFont("kelmscot.ttf", 18);
	m.font_select = TTF_OpenFont("kelmscot.ttf", 20);
	return (m);
}

t_menu	init_craft_menu(void)
{
	t_menu	m;

	m.img = create_rect(100, 80, 120, 90);
	m.object = create_rect(0, 0, 120, 90);
	m.select = create_rect(0, 0, 124, 94);
	m.hover = create_rect(98, 78, 124, 94);
	m.text_object = create_rect(240, 120, 120, 90);
	m.price_object = create_rect(240, 155, 120, 90);
	m.wallet_object = create_rect(580, 500, 120, 90);
	m.arrow_object = create_rect(580, 480, 120, 90);
	m.wallet_color = set_font_color(32, 32, 32, 255);
	m.arrow_color = set_font_color(32, 32, 32, 255);
	m.font = TTF_OpenFont("kelmscot.ttf", 18);
	m.font_select = TTF_OpenFont("kelmscot.ttf", 20);
	return (m);
}

void	init_hud2(SDL_Surface **image, t_player *player)
{
	char *tmp;

	tmp = ft_itoa(player->items.ammo);
	player->hud.ammo = ft_strjoin("arrows: ", tmp);
	player->hud.ammo_object = create_rect(20, 510, 120, 90);
	player->hud.ammo_color = set_font_color(212, 212, 212, 255);
	player->hud.ammo_surface = TTF_RenderText_Blended(player->hud.font,
	player->hud.ammo, player->hud.ammo_color);
	SDL_BlitSurface(player->hud.ammo_surface, NULL, (*image),
	&player->hud.ammo_object);
	free(tmp);
	free(player->hud.ammo);
	tmp = ft_itoa(player->items.hp);
	player->hud.hp = ft_strjoin("health: ", tmp);
	player->hud.hp_object = create_rect(20, 30, 120, 90);
	player->hud.hp_color = set_font_color(212, 212, 212, 255);
	if (player->items.hp <= 100)
		player->hud.hp_color = set_font_color(255, 92, 92, 255);
	player->hud.hp_surface = TTF_RenderText_Blended(player->hud.font,
	player->hud.hp, player->hud.hp_color);
	SDL_BlitSurface(player->hud.hp_surface, NULL, (*image),
	&player->hud.hp_object);
	free(tmp);
	free(player->hud.hp);
}

void	init_hud1(SDL_Surface **image, t_player *player)
{
	char *tmp;

	tmp = ft_itoa(player->items.money);
	player->hud.font = TTF_OpenFont("kelmscot.ttf", 20);
	player->hud.wallet = ft_strjoin("wallet: ", tmp);
	player->hud.wallet_object = create_rect(20, 570, 120, 90);
	player->hud.wallet_color = set_font_color(212, 212, 212, 255);
	player->hud.wallet_surface = TTF_RenderText_Blended(player->hud.font,
	player->hud.wallet, player->hud.wallet_color);
	SDL_BlitSurface(player->hud.wallet_surface, NULL, (*image),
	&player->hud.wallet_object);
	free(tmp);
	free(player->hud.wallet);
	tmp = ft_itoa(player->items.toolbox);
	player->hud.tbox = ft_strjoin("toolbox: ", tmp);
	player->hud.tbox_object = create_rect(20, 540, 120, 90);
	player->hud.tbox_color = set_font_color(212, 212, 212, 255);
	player->hud.tbox_surface = TTF_RenderText_Blended(player->hud.font,
	player->hud.tbox, player->hud.tbox_color);
	SDL_BlitSurface(player->hud.tbox_surface, NULL, (*image),
	&player->hud.tbox_object);
	free(tmp);
	free(player->hud.tbox);
}

void	init_hud(SDL_Surface **image, t_player *player)
{
	init_hud1(image, player);
	init_hud2(image, player);
	player->hud.act_object = create_rect(WINW2 -
	((ft_strlen(player->hud.act) * 8) / 2), 570, 120, 90);
	player->hud.act_color = set_font_color(212, 212, 212, 255);
	player->hud.act_surface = TTF_RenderText_Blended(player->hud.font,
	player->hud.act, player->hud.act_color);
	SDL_BlitSurface(player->hud.act_surface, NULL, (*image),
	&player->hud.act_object);
	free(player->hud.act);
	SDL_FreeSurface(player->hud.ammo_surface);
	SDL_FreeSurface(player->hud.tbox_surface);
	SDL_FreeSurface(player->hud.hp_surface);
}
