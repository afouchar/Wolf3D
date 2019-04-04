/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:03:40 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:03:40 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	get_tex_col(SDL_Surface **img, t_boxel **b_map, t_ray *r, int tnum)
{
	SDL_PixelFormat		*fmt;
	Uint32				*pixels;

	r->tex.y = get_texy(img, b_map, r, tnum);
	pixels = (Uint32 *)b_map[0][0].textures[tnum]->pixels;
	fmt = b_map[0][0].textures[tnum]->format;
	r->curcol = *(pixels + r->tex.y + (r->tex.x / 4) * fmt->BytesPerPixel);
	if (tnum != 29 && tnum != 30)
		r->curcol = get_shadow(b_map[0][0].tier_shadow, r->curcol, tnum);
	SDL_GetRGB(r->curcol, fmt, &r->tmp_col.r, &r->tmp_col.g, &r->tmp_col.b);
}

void	get_color_light(SDL_Surface **img, t_boxel **b, t_ray *r, int tnum)
{
	t_color8			tmp_layout;

	tmp_layout = get_tex_mask(img, b, r, tnum);
	get_tex_col(img, b, r, tnum);
	set_fog(r, b);
	r->color.r = 255 - (abs(tmp_layout.r - r->color.r));
	r->color.g = 255 - (abs(tmp_layout.g - r->color.g));
	r->color.b = 255 - (abs(tmp_layout.b - r->color.b));
}

void	get_color_bis(SDL_Surface **img, t_boxel **b, t_ray *r, int tnum)
{
	SDL_PixelFormat		*fmt;
	Uint32				*pixels;

	if (tnum == 63 || tnum == 64)
		get_color_light(img, b, r, tnum);
	else
	{
		r->tex.y = get_texy(img, b, r, tnum);
		pixels = (Uint32 *)b[0][0].textures[tnum]->pixels;
		fmt = b[0][0].textures[tnum]->format;
		r->curcol = *(pixels + r->tex.y + (r->tex.x / 4) * fmt->BytesPerPixel);
		if (tnum != 29 && tnum != 30 && tnum != 77)
			r->curcol = get_shadow(b[0][0].tier_shadow, r->curcol, tnum);
		SDL_GetRGB(r->curcol, fmt, &r->tmp_col.r, &r->tmp_col.g, &r->tmp_col.b);
		set_fog(r, b);
	}
}

void	get_color(SDL_Surface **image, t_boxel **b_map, t_ray *r, char side)
{
	int					tex_num;

	tex_num = get_side(side, b_map, r);
	if (b_map[0][0].islevel != FIELDS)
	{
		if (ft_check_lamppost(b_map, r, side) == 1)
			get_color_light(image, b_map, r, tex_num);
		else if (tex_num == 34 || tex_num == 35 || tex_num == 43 ||
		tex_num == 46 || tex_num == 49 || tex_num == 50)
			get_color_light(image, b_map, r, tex_num);
		else
			get_color_bis(image, b_map, r, tex_num);
	}
	else
		get_color_bis(image, b_map, r, tex_num);
}

int		get_texx(t_ray *r)
{
	int		texx;

	texx = (int)(r->wallx * (float)(TEXW));
	if (r->side == 0 && r->raydirx > 0)
		texx = TEXW - texx - 1;
	if (r->side == 1 && r->raydiry < 0)
		texx = TEXW - texx - 1;
	return (texx);
}
