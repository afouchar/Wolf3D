/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:00:53 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:00:53 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		get_side(char side, t_boxel **b_map, t_ray *r)
{
	int		tex_num;

	if (side == 'F')
		tex_num = b_map[r->mapx][r->mapy].floor;
	else if (side == 'C')
		tex_num = b_map[r->mapx][r->mapy].ceiling;
	else if (side == 'N')
		tex_num = b_map[r->mapx][r->mapy].texn;
	else if (side == 'S')
		tex_num = b_map[r->mapx][r->mapy].texs;
	else if (side == 'E')
		tex_num = b_map[r->mapx][r->mapy].texe;
	else if (side == 'W')
		tex_num = b_map[r->mapx][r->mapy].texw;
	else if (side == 'T')
		tex_num = b_map[r->mapx][r->mapy].textop;
	else
		tex_num = b_map[r->mapx][r->mapy].texmid;
	return (tex_num);
}

int		get_texy(SDL_Surface **image, t_boxel **b_map, t_ray *r, int tex_num)
{
	int		d;

	if (tex_num == 56 || tex_num == 58)
	{
		d = ((r->y + r->p) * 256 - (*image)->h * 128 +
		(r->lineheight + 10) * 128);
		d = (((d * TEXH) / (r->lineheight + 10)) / 256);
		d = (d / 4) * b_map[0][0].textures[tex_num]->pitch;
	}
	else
	{
		d = ((r->y + 1) * 256 - (*image)->h * 128 + r->lineheight * 128);
		d = (((d * TEXH) / r->lineheight) / 256);
		d = (d / 4) * b_map[0][0].textures[tex_num]->pitch;
	}
	return (d);
}

double	radian(double deg)
{
	return (deg * M_PI / 180);
}

int		out_of_bounds(t_boxel **b_map, t_ray r)
{
	int		nextx;
	int		nexty;
	int		values;
	int		lines;

	nextx = r.mapx + 1;
	nexty = r.mapy + 1;
	values = b_map[0][0].values[r.mapx];
	lines = b_map[0][0].lines;
	if (nexty < values && r.mapy > 0 && nextx < lines && r.mapx > 0)
		return (0);
	return (1);
}

int		out_of_level(t_player *player, t_boxel **b_map)
{
	t_point		pt;
	t_point		pa;

	pt.x = (int)(player->pos.x + player->dir.x * player->move_speed);
	pt.y = (int)(player->pos.y + player->dir.y * player->move_speed);
	pa.x = (int)(player->pos.x + player->dir.x * player->move_speed);
	pa.y = (int)(player->pos.y + player->dir.y * player->move_speed);
	if (pt.x < b_map[0][0].lines && pa.x > 0
	&& pt.y < b_map[0][0].values[pa.x] && pa.y > 0)
		return (0);
	return (1);
}
