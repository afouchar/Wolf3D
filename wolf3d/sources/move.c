/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:39 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:39 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_forward(t_player *player, t_boxel **b_map)
{
	walk_sound(player, b_map);
	if (b_map[(int)(player->pos.x + player->dir.x *
	(player->move_speed))][(int)(player->pos.y)].door == 0)
		player->pos.x += player->dir.x * player->move_speed;
	if (b_map[(int)(player->pos.x)][(int)(player->pos.y +
	player->dir.y * (player->move_speed + 0.1))].door == 0)
		player->pos.y += player->dir.y * player->move_speed;
}

void	ft_move_backward(t_player *player, t_boxel **b_map)
{
	walk_sound(player, b_map);
	if (b_map[(int)(player->pos.x - player->dir.x *
	(player->move_speed))][(int)(player->pos.y)].door == 0)
		player->pos.x -= player->dir.x * player->move_speed;
	if (b_map[(int)(player->pos.x)][(int)(player->pos.y - player->dir.y
	* (player->move_speed))].door == 0)
		player->pos.y -= player->dir.y * player->move_speed;
}

void	ft_straf_right(t_player *player, t_boxel **b_map)
{
	walk_sound(player, b_map);
	if (b_map[(int)(player->pos.x + player->plane.x *
	(player->move_speed + 0.1))][(int)(player->pos.y)].door == 0)
		player->pos.x += player->plane.x * player->move_speed;
	if (b_map[(int)(player->pos.x)][(int)(player->pos.y +
	player->plane.y * (player->move_speed + 0.1))].door == 0)
		player->pos.y += player->plane.y * player->move_speed;
}

void	ft_straf_left(t_player *player, t_boxel **b_map)
{
	walk_sound(player, b_map);
	if (b_map[(int)(player->pos.x - player->plane.x *
	(player->move_speed + 0.1))][(int)(player->pos.y)].door == 0)
		player->pos.x -= player->plane.x * player->move_speed;
	if (b_map[(int)(player->pos.x)][(int)(player->pos.y -
	player->plane.y * (player->move_speed + 0.1))].door == 0)
		player->pos.y -= player->plane.y * player->move_speed;
}
