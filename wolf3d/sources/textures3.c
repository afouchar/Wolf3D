/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:03:47 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:03:47 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_height(SDL_Surface **image, t_ray *r)
{
	if (r->side == 0)
		r->perpwalldist = fabs((r->mapx - r->rayposx +
		(1 - r->stepx) / 2) / r->raydirx);
	else
		r->perpwalldist = fabs((r->mapy - r->rayposy +
		(1 - r->stepy) / 2) / r->raydiry);
	r->lineheight = fabs((*image)->h / r->perpwalldist);
	r->drawstart = ((*image)->h / 2) - (r->lineheight / 2);
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + ((*image)->h / 2);
	if (r->drawend >= (*image)->h)
		r->drawend = ((*image)->h - 1);
	if (r->drawend < 0)
		r->drawend = (*image)->h;
	if (r->side == 1)
		r->wallx = r->rayposx + ((r->mapy - r->rayposy +
		(1 - r->stepy) / 2) / r->raydiry) * r->raydirx;
	else
		r->wallx = r->rayposy + ((r->mapx - r->rayposx +
		(1 - r->stepx) / 2) / r->raydirx) * r->raydiry;
	r->wallx -= floor((r->wallx));
}

void	get_side_color(SDL_Surface **img, t_ray *r, t_player *p, t_boxel **b)
{
	if (r->side == 0 && (int)p->pos.x < r->mapx)
	{
		b[0][0].tier_shadow = 'N';
		get_color(img, b, r, 'N');
	}
	else if (r->side == 0)
	{
		b[0][0].tier_shadow = 'S';
		get_color(img, b, r, 'S');
	}
	else if (r->side != 0 && (int)p->pos.y < r->mapy)
	{
		b[0][0].tier_shadow = 'E';
		get_color(img, b, r, 'E');
	}
	else
	{
		b[0][0].tier_shadow = 'W';
		get_color(img, b, r, 'W');
	}
}

void	get_tiers_color(SDL_Surface **image, t_ray *r, t_boxel **b_map, int p)
{
	if (p < (b_map[r->mapx][r->mapy].wall - 1))
		get_color(image, b_map, r, 'M');
	else if (p == (b_map[r->mapx][r->mapy].wall - 1))
		get_color(image, b_map, r, 'T');
	else
		p = b_map[r->mapx][r->mapy].wall;
}

int		reflect(t_ray *r, t_boxel **b_map, int tier)
{
	int		py;

	py = 0;
	if (b_map[0][0].islevel == FIELDS)
	{
		if (tier == 1)
		{
			py = (r->drawend + (r->drawend - r->drawstart)) -
			(r->y - r->drawstart);
			if (py <= WINH2 * 2 - 1)
				return (py);
		}
		else if (tier == 2)
		{
			py = (r->drawend + (r->drawend - r->drawstart)) - (((r->y + r->p) -
			(r->lineheight * r->p)) - r->drawstart);
			if (py <= WINH2 * 2 - 1)
				return (py);
		}
	}
	return (0);
}

void	to_alpha(t_ray *r)
{
	t_color8		tmp_col;

	tmp_col.r = 220;
	tmp_col.g = 220;
	tmp_col.b = 240;
	if (r->color.r >= tmp_col.r)
		r->color.r -= abs(r->color.r - tmp_col.r) / 2;
	else if (tmp_col.r > r->color.r)
		r->color.r += abs(tmp_col.r - r->color.r) / 2;
	if (r->color.g >= tmp_col.g)
		r->color.g -= abs(r->color.g - tmp_col.g) / 2;
	else if (tmp_col.g > r->color.g)
		r->color.g += abs(tmp_col.g - r->color.g) / 2;
	if (r->color.b >= tmp_col.b)
		r->color.b -= abs(r->color.b - tmp_col.b) / 2;
	else if (tmp_col.b > r->color.b)
		r->color.b += abs(tmp_col.b - r->color.b) / 2;
}
