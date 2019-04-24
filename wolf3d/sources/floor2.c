/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:47 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:47 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_lgt_fl_col(SDL_Surface **img, t_boxel **b, t_ray *r, t_floor *f)
{
	int				tex_num;

	get_floor_color(b, r, f, 'F');
	if (f->raw == 0xFFFF00)
	{
		tex_num = water_animation(b);
		f->tmp_col = get_mask(b, f, tex_num);
		f->color = get_background(img, r->x, f->y);
		f->color = get_alpha(f->color, f->tmp_col, 9);
	}
}

void	get_floor_color(t_boxel **b_map, t_ray *r, t_floor *f, char side)
{
	SDL_PixelFormat	*fmt;
	t_fpoint		tex;
	int				tex_num;

	tex_num = get_side_fl(side, b_map, r, f);
	f->pixel = (Uint32 *)b_map[0][0].textures[tex_num]->pixels;
	fmt = b_map[0][0].textures[tex_num]->format;
	tex.x = (int)(f->floortex.x / 4) * fmt->BytesPerPixel;
	tex.y = (int)(f->floortex.y / 4) * b_map[0][0].textures[tex_num]->pitch;
	f->raw = *(f->pixel + (int)tex.y + (int)tex.x);
	if (f->raw != 0xFFFF00)
	{
		if (b_map[0][0].islevel != FIELDS)
			f->raw = (f->raw >> 1) & 8355711;
		SDL_GetRGB(f->raw, fmt, &f->tmp_col.r, &f->tmp_col.g, &f->tmp_col.b);
		set_floor_fog(f, r, b_map);
	}
}

void	draw_fl_bis(SDL_Surface **img, t_ray *r, t_player *player, t_boxel **b)
{
	int		p;

	get_location(player, r, &b[0][0].f);
	if (b[r->mapx][r->mapy].floor >= 0)
	{
		if ((int)b[0][0].f.curwall.y < b[0][0].values[(int)b[0][0].f.curwall.x]
		&& (int)b[0][0].f.curwall.x < b[0][0].lines && (int)b[0][0].f.curwall.y
		>= 0 && (int)b[0][0].f.curwall.x >= 0)
			water_floor(b, r, img, b[0][0].f);
	}
	if (b[r->mapx][r->mapy].ceiling > 0)
	{
		if ((int)b[0][0].f.curwall.y < b[0][0].values[(int)b[0][0].f.curwall.x]
		&& (int)b[0][0].f.curwall.x < b[0][0].lines && (int)b[0][0].f.curwall.y
		>= 0 && (int)b[0][0].f.curwall.x >= 0)
		{
			get_floor_color(b, r, &b[0][0].f, 'C');
			if (b[0][0].f.raw != 0xFFFF00)
			{
				p = (*img)->h - (b[0][0].f.y + (r->lineheight -
				b[r->mapx][r->mapy].wall) * (b[r->mapx][r->mapy].wall - 1));
				draw_point(img, r->x, p, b[0][0].f.color);
			}
		}
	}
}

void	draw_floor(SDL_Surface **img, t_ray *r, t_player *player, t_boxel **b)
{
	get_height(img, r);
	get_direction(r, &b[0][0].f);
	b[0][0].f.y = r->drawend;
	while (b[0][0].f.y < (*img)->h - 1)
	{
		r->distancewall = (*img)->h / (2.0 * b[0][0].f.y - (*img)->h);
		draw_fl_bis(img, r, player, b);
		b[0][0].f.y++;
	}
}
