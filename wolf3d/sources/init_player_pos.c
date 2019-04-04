/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:00 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:00 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_player_pos(t_player *player, int prevlevel, char *fname)
{
	if (ft_strcmp(fname, "./maps/church.w3d") == 0
	|| (ft_strcmp(fname, "./maps/village.w3d") == 0 && prevlevel == HOUSE))
		init_player_pos1(player, prevlevel, fname);
	else if ((ft_strcmp(fname, "./maps/village.w3d") == 0 && prevlevel == SHOP)
	|| (ft_strcmp(fname, "./maps/village.w3d") == 0 && prevlevel == FIELDS))
		init_player_pos2(player, prevlevel, fname);
	else if ((ft_strcmp(fname, "./maps/village.w3d") == 0 && prevlevel == PLACE)
	|| ft_strcmp(fname, "./maps/house.w3d") == 0)
		init_player_pos3(player, prevlevel, fname);
	else if ((ft_strcmp(fname, "./maps/church_place.w3d") == 0
	&& prevlevel == VILLAGE)
	|| (ft_strcmp(fname, "./maps/church_place.w3d") == 0
	&& prevlevel == CHURCH))
		init_player_pos4(player, prevlevel, fname);
	else if ((ft_strcmp(fname, "./maps/shop.w3d") == 0)
	|| (ft_strcmp(fname, "./maps/fields.w3d") == 0))
		init_player_pos5(player, fname);
}
