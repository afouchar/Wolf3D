/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fog_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:08 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:08 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_fog_sp2(t_boxel **b_map, t_sfog *g, t_ray *r, t_color8 c)
{
	if (b_map[0][0].islevel == SHOP)
	{
		g->col->r = c.r * b_map[0][0].killfog + r->sp_dis[g->i] * 2;
		g->col->g = c.g + r->sp_dis[g->i] * 2;
		g->col->b = c.b + r->sp_dis[g->i] * 2;
		if (g->col->r > 222)
			g->col->r = 222;
		if (g->col->g > 222)
			g->col->g = 222;
		if (g->col->b > 222)
			g->col->b = 222;
	}
	else
		set_fog_sp3(b_map, g, r, c);
}

void	set_fog_sp4(t_boxel **b_map, t_sfog *g, t_ray *r, t_color8 c)
{
	if (b_map[0][0].islevel != SHOP &&
	b_map[0][0].sprite[r->sprite_order[g->i]].texture != 14)
	{
		g->col->r = c.r * 2 / r->sp_dis[g->i];
		g->col->g = c.g * 2 / r->sp_dis[g->i];
		g->col->b = c.b * 2 / r->sp_dis[g->i];
		if (g->col->r > 150)
			g->col->r = 150;
		if (g->col->g > 150)
			g->col->g = 150;
		if (g->col->b > 150)
			g->col->b = 150;
	}
	else
	{
		g->col->r = c.r;
		g->col->g = c.g;
		g->col->b = c.b;
	}
}

void	set_fog_sp3(t_boxel **b_map, t_sfog *g, t_ray *r, t_color8 c)
{
	if (b_map[0][0].islevel == FIELDS)
	{
		g->col->r = c.r * b_map[0][0].killfog + r->sp_dis[g->i] / 2;
		g->col->g = c.g + r->sp_dis[g->i] / 2;
		g->col->b = c.b + r->sp_dis[g->i] / 2;
		if (g->col->r > 235)
			g->col->r = 235;
		if (g->col->g > 245)
			g->col->g = 245;
		if (g->col->b > 235)
			g->col->b = 235;
	}
	else
		set_fog_sp4(b_map, g, r, c);
}

void	set_fog_sp(t_boxel **b_map, t_sfog *g, t_ray *r, t_color8 c)
{
	if (b_map[0][0].islevel == CHURCH || b_map[0][0].islevel == HOUSE)
	{
		g->col->r = c.r * b_map[0][0].killfog + r->sp_dis[g->i] * 5;
		g->col->g = c.g + r->sp_dis[g->i] * 5;
		g->col->b = c.b + r->sp_dis[g->i] * 5;
		if (g->col->r > 222)
			g->col->r = 222;
		if (g->col->g > 222)
			g->col->g = 222;
		if (g->col->b > 222)
			g->col->b = 222;
	}
	else
		set_fog_sp2(b_map, g, r, c);
}
