/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:36 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:36 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

Uint32	get_shadow(char side, Uint32 shadow, int tex_num)
{
	if (shadow != 0xFFFF00)
	{
		if (tex_num != 28 && tex_num != 27)
			shadow = (shadow >> 1) & 8355711;
		if (side != 'S')
		{
			shadow = (shadow >> 1) & 8355711;
			if (side == 'E' || side == 'N')
				shadow = (shadow >> 1) & 8355711;
		}
	}
	return (shadow);
}

void	set_fog2(t_ray *r, t_boxel **b_map)
{
	if (b_map[0][0].islevel == HOUSE || b_map[0][0].islevel == SHOP)
	{
		r->color.r = r->tmp_col.r * b_map[0][0].killfog + r->perpwalldist * 20;
		r->color.g = r->tmp_col.g + r->perpwalldist * 20;
		r->color.b = r->tmp_col.b + r->perpwalldist * 20;
		if (r->color.r > 255)
			r->color.r = 255;
		if (r->color.g > 255)
			r->color.g = 255;
		if (r->color.b > 255)
			r->color.b = 255;
	}
	else if (b_map[0][0].islevel == FIELDS)
	{
		r->color.r = r->tmp_col.r * b_map[0][0].killfog + r->perpwalldist * 8;
		r->color.g = r->tmp_col.g + r->perpwalldist * 8;
		r->color.b = r->tmp_col.b + r->perpwalldist * 8;
		if (r->color.r > 245)
			r->color.r = 245;
		if (r->color.g > 245)
			r->color.g = 245;
		if (r->color.b > 235)
			r->color.b = 235;
	}
}

void	set_fog(t_ray *r, t_boxel **b_map)
{
	if (b_map[0][0].islevel == PLACE || b_map[0][0].islevel == VILLAGE)
	{
		r->color.r = r->tmp_col.r * 1.5 * b_map[0][0].killfog / r->perpwalldist;
		r->color.g = r->tmp_col.g * 1.5 / r->perpwalldist * 1;
		r->color.b = r->tmp_col.b * 1.5 / r->perpwalldist * 1;
		if (r->color.r > 100)
			r->color.r = 100;
		if (r->color.g > 100)
			r->color.g = 100;
		if (r->color.b > 100)
			r->color.b = 100;
	}
	else if (b_map[0][0].islevel == CHURCH)
	{
		r->color.r = r->tmp_col.r * b_map[0][0].killfog + r->perpwalldist * 20;
		r->color.g = r->tmp_col.g + r->perpwalldist * 20;
		r->color.b = r->tmp_col.b + r->perpwalldist * 20;
		if (r->color.r > 255)
			r->color.r = 255;
		if (r->color.g > 255)
			r->color.g = 255;
		if (r->color.b > 255)
			r->color.b = 255;
	}
	set_fog2(r, b_map);
}

void	set_floor_fog2(t_floor *f, t_ray *r, t_boxel **b_map)
{
	if (b_map[0][0].islevel == HOUSE || b_map[0][0].islevel == SHOP)
	{
		f->color.r = f->tmp_col.r * b_map[0][0].killfog + r->distancewall * 20;
		f->color.g = f->tmp_col.g + r->distancewall * 20;
		f->color.b = f->tmp_col.b + r->distancewall * 20;
		if (f->color.r > 255)
			f->color.r = 255;
		if (f->color.g > 255)
			f->color.g = 255;
		if (f->color.b > 255)
			f->color.b = 255;
	}
	else if (b_map[0][0].islevel == FIELDS)
	{
		f->color.r = f->tmp_col.r * b_map[0][0].killfog + r->distancewall * 8;
		f->color.g = f->tmp_col.g + r->distancewall * 8;
		f->color.b = f->tmp_col.b + r->distancewall * 8;
		if (f->color.r > 235)
			f->color.r = 235;
		if (f->color.g > 245)
			f->color.g = 245;
		if (f->color.b > 235)
			f->color.b = 235;
	}
}

void	set_floor_fog(t_floor *f, t_ray *r, t_boxel **b_map)
{
	if (b_map[0][0].islevel == PLACE || b_map[0][0].islevel == VILLAGE)
	{
		f->color.r = f->tmp_col.r * b_map[0][0].killfog / r->distancewall * 1;
		f->color.g = f->tmp_col.g / r->distancewall * 1;
		f->color.b = f->tmp_col.b / r->distancewall * 1;
		if (f->color.r > 150)
			f->color.r = 150;
		if (f->color.g > 150)
			f->color.g = 150;
		if (f->color.b > 150)
			f->color.b = 150;
	}
	else if (b_map[0][0].islevel == CHURCH)
	{
		f->color.r = f->tmp_col.r * b_map[0][0].killfog + r->distancewall * 20;
		f->color.g = f->tmp_col.g + r->distancewall * 20;
		f->color.b = f->tmp_col.b + r->distancewall * 20;
		if (f->color.r > 255)
			f->color.r = 255;
		if (f->color.g > 255)
			f->color.g = 255;
		if (f->color.b > 255)
			f->color.b = 255;
	}
	set_floor_fog2(f, r, b_map);
}
