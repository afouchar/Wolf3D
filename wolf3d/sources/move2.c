/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:33 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:33 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_move_right(t_player *player)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = player->dir.x;
	old_planex = player->plane.x;
	player->dir.x = player->dir.x * cos(-player->rot_speed) -
	player->dir.y * sin(-player->rot_speed);
	player->dir.y = old_dirx * sin(-player->rot_speed) +
	player->dir.y * cos(-player->rot_speed);
	old_planex = player->plane.x;
	player->plane.x = player->plane.x * cos(-player->rot_speed) -
	player->plane.y * sin(-player->rot_speed);
	player->plane.y = old_planex * sin(-player->rot_speed) +
	player->plane.y * cos(-player->rot_speed);
	player->anglesky += player->rot_speed * 20;
}

void	ft_move_left(t_player *player)
{
	float	old_dirx;
	float	old_planex;

	old_dirx = player->dir.x;
	old_planex = player->plane.x;
	player->dir.x = player->dir.x * cos(player->rot_speed) -
	player->dir.y * sin(player->rot_speed);
	player->dir.y = old_dirx * sin(player->rot_speed) +
	player->dir.y * cos(player->rot_speed);
	player->plane.x = player->plane.x * cos(player->rot_speed) -
	player->plane.y * sin(player->rot_speed);
	player->plane.y = old_planex * sin(player->rot_speed) +
	player->plane.y * cos(player->rot_speed);
	player->anglesky -= player->rot_speed * 20;
}
