/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_menus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:01 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:01 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		*select_start_name(int nb)
{
	char	*name;

	if (nb == 0)
		name = ft_strdup("start game");
	else
		name = ft_strdup("quit");
	return (name);
}

SDL_Color	set_font_color(int r, int g, int b, int a)
{
	SDL_Color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

void		set_menu_hud(SDL_Surface **image, t_menu *m, int place)
{
	if (place == SHOP)
		m->esc = ft_strdup("press 'E' to leave shop");
	else if (place == HOUSE)
		m->esc = ft_strdup("press 'E' to leave craft shelf");
	m->esc_object = create_rect(WINW2 -
	((ft_strlen(m->esc) * 8) / 2), 570, 120, 90);
	m->esc_color = set_font_color(32, 32, 32, 255);
	m->esc_surface = TTF_RenderText_Blended(m->font, m->esc, m->esc_color);
	SDL_BlitSurface(m->esc_surface, NULL, (*image), &m->esc_object);
	SDL_FreeSurface(m->esc_surface);
	free(m->esc);
}

void		set_wallet(t_player *player, t_menu *m, int nb)
{
	char	*tmp;

	tmp = ft_itoa(player->items.money);
	m->wallet = ft_strjoin("wallet: ", tmp);
	free(tmp);
	m->wallet_object = create_rect(700 -
	(ft_strlen(m->wallet) * 8), 500, 120, 90);
	if (player->items.objects[nb - 1].price > player->items.money)
		m->wallet_color = set_font_color(165, 48, 30, 255);
	else
		m->wallet_color = set_font_color(32, 32, 32, 255);
	m->wallet_surface = TTF_RenderText_Blended(m->font_select,
	m->wallet, m->wallet_color);
	free(m->wallet);
}

void		align_selection(t_menu *m, int nb)
{
	if (nb == 4)
	{
		m->img = create_rect(WINW2 + 40, 80, 120, 90);
		m->hover = create_rect(WINW2 + 40 - 2, 78, 124, 94);
		m->text_object = create_rect(WINW2 + 180, 120, 120, 90);
		m->price_object = create_rect(WINW2 + 180, 155, 120, 90);
	}
	else
	{
		m->img.y += 100;
		m->hover.y += 100;
		m->text_object.y += 100;
		m->price_object.y += 100;
	}
}
