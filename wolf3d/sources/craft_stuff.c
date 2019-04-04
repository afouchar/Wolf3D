/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   craft_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:07:05 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:07:05 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char	*select_craft_name(int nb)
{
	if (nb == 1)
		return ("bow");
	else if (nb == 2)
		return ("crossbow");
	else if (nb == 3)
		return ("arrows");
	else
		return (" ");
}

char	*select_craft_price(t_player *player, int nb)
{
	char	*price;

	price = ft_itoa(player->items.craft_objects[nb].price);
	return (price);
}

int		is_craft_owned(t_player *player, int select)
{
	if (player->items.weapon == select && select != ARROW)
		return (1);
	return (0);
}

void	craft_objects(t_player *player, int select)
{
	if (player->items.toolbox >= player->items.craft_objects[select].price
	&& select == ARROW)
	{
		player->items.toolbox -= player->items.craft_objects[select].price;
		player->items.ammo += 20;
		Mix_PlayChannel(-1, player->craft_arrow, 0);
	}
	else if (player->items.toolbox >= player->items.craft_objects[select].price
	&& is_craft_owned(player, select) == 0)
	{
		if (select > player->items.weapon)
		{
			player->items.toolbox -= player->items.craft_objects[select].price;
			player->items.weapon = select;
			player->items.strength = (10 + (select * 2)) * (select + 1);
			Mix_PlayChannel(-1, player->craft_weapon, 0);
		}
		else
			Mix_PlayChannel(-1, player->coin_shop_already, 0);
	}
	else if (is_craft_owned(player, select) == 1)
		Mix_PlayChannel(-1, player->coin_shop_already, 0);
	else
		Mix_PlayChannel(-1, player->coin_shop_empty, 0);
}

void	set_toolbox(t_player *player, t_menu *m, int nb)
{
	char	*tmp;

	tmp = ft_itoa(player->items.toolbox);
	m->wallet = ft_strjoin("toolbox: ", tmp);
	free(tmp);
	m->wallet_object = create_rect(700 -
	(ft_strlen(m->wallet) * 8), 500, 120, 90);
	if (player->items.craft_objects[nb].price > player->items.toolbox)
		m->wallet_color = set_font_color(165, 48, 30, 255);
	else
		m->wallet_color = set_font_color(32, 32, 32, 255);
	m->wallet_surface = TTF_RenderText_Blended(m->font_select,
	m->wallet, m->wallet_color);
	tmp = ft_itoa(player->items.ammo);
	m->arrow = ft_strjoin("arrows: ", tmp);
	free(tmp);
	m->arrow_object = create_rect(700 -
	(ft_strlen(m->arrow) * 8), 460, 120, 90);
	m->arrow_surface = TTF_RenderText_Blended(m->font_select,
	m->arrow, m->arrow_color);
	free(m->wallet);
	free(m->arrow);
}
