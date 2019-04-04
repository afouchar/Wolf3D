/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:17 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:17 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_objects(t_player *player, t_boxel **b_map)
{
	if (is_owned(player, PAINT) == 1 && b_map[0][0].islevel == HOUSE)
		b_map[0][4].texs = 39;
	if (is_owned(player, FIRE) == 1 && b_map[0][0].islevel == HOUSE)
	{
		b_map[1][3].wall = 1;
		b_map[1][3].texw = 35;
		b_map[1][3].texn = 10;
		b_map[1][3].texs = 10;
		b_map[1][3].texe = 10;
	}
	if (is_owned(player, DEER) == 1 && b_map[0][0].islevel == HOUSE)
		b_map[5][8].texe = 47;
	get_deco(player, b_map);
	get_wallpaper(player, b_map);
	if (is_owned(player, TOOLSHELF) == 1 && b_map[0][0].islevel == HOUSE)
		b_map[7][5].texn = 51;
	get_floor_ceiling(player, b_map);
}

int		is_owned(t_player *player, int select)
{
	int		i;

	i = 0;
	while (i < player->items.nb_owned)
	{
		if (player->items.owned[i] == select)
			return (1);
		i++;
	}
	return (0);
}

void	buy_objects(t_player *player, int select)
{
	if (player->items.money >= player->items.objects[select - 1].price
	&& is_owned(player, select + 10) == 0)
	{
		player->items.money -= player->items.objects[select - 1].price;
		player->items.owned[player->items.nb_owned] = (select + 10);
		player->items.nb_owned++;
		Mix_PlayChannel(-1, player->coin_shop, 0);
	}
	else if (is_owned(player, select + 10) == 1)
		Mix_PlayChannel(-1, player->coin_shop_already, 0);
	else
		Mix_PlayChannel(-1, player->coin_shop_empty, 0);
}

char	*select_price(t_player *player, int nb)
{
	char	*price;

	price = ft_itoa(player->items.objects[nb - 1].price);
	return (price);
}
