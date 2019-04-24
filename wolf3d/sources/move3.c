/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:24 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:24 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_move(t_player *player, t_boxel **b_map)
{
	if (player->press.talk == 0)
	{
		if (player->press.fwd == 1)
			ft_move_forward(player, b_map);
		if (player->press.lft == 1)
			ft_move_left(player);
		if (player->press.rgt == 1)
			ft_move_right(player);
		if (player->press.s_rgt == 1)
			ft_straf_right(player, b_map);
		if (player->press.s_lft == 1)
			ft_straf_left(player, b_map);
		if (player->press.bkwd == 1)
			ft_move_backward(player, b_map);
		player->press.lft = 0;
		player->press.rgt = 0;
	}
}

void	set_talk(SDL_Surface **image, t_player *player)
{
	if (player->press.talk == 1)
		talk(image, player);
}
