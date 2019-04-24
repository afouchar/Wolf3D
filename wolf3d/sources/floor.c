/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:51 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:51 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_side_fl(char side, t_boxel **b_map, t_ray *r, t_floor *f)
{
	int		tex_num;

	if (side == 'F')
		tex_num = b_map[(int)f->curwall.x][(int)f->curwall.y].floor;
	else if (side == 'C')
		tex_num = b_map[(int)f->curwall.x][(int)f->curwall.y].ceiling;
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

void		get_direction(t_ray *r, t_floor *f)
{
	if (r->side == 0 && r->raydirx > 0)
	{
		f->floorwall.x = r->mapx;
		f->floorwall.y = r->mapy + r->wallx;
	}
	else if (r->side == 0 && r->raydirx < 0)
	{
		f->floorwall.x = r->mapx + 1.0;
		f->floorwall.y = r->mapy + r->wallx;
	}
	else if (r->side == 1 && r->raydiry > 0)
	{
		f->floorwall.x = r->mapx + r->wallx;
		f->floorwall.y = r->mapy;
	}
	else
	{
		f->floorwall.x = r->mapx + r->wallx;
		f->floorwall.y = r->mapy + 1.0;
	}
	f->distwall = r->perpwalldist;
}

void		get_location(t_player *player, t_ray *r, t_floor *f)
{
	f->weight = r->distancewall / f->distwall;
	f->curwall.x = f->weight * f->floorwall.x +
	(1.0 - f->weight) * player->pos.x;
	f->curwall.y = f->weight * f->floorwall.y +
	(1.0 - f->weight) * player->pos.y;
	f->floortex.x = (int)(f->curwall.x * TEXW) % TEXW;
	f->floortex.y = (int)(f->curwall.y * TEXH) % TEXH;
}

Uint32		getpixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16 *)p);
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (bpp == 4)
		return (*(Uint32 *)p);
	else
		return (0);
}

t_color		get_background(SDL_Surface **image, int x, int y)
{
	SDL_PixelFormat	*fmt;
	t_color8		c;
	t_color			color;

	fmt = (*image)->format;
	SDL_GetRGB(getpixel(*image, x, y), fmt, &c.r, &c.g, &c.b);
	color.r = c.r;
	color.g = c.g;
	color.b = c.b;
	return (color);
}
