/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_water.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:43 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:43 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			water_tile(t_boxel **b_map, t_floor *f)
{
	if (b_map[(int)f->curwall.x][(int)f->curwall.y].floor == 0)
		return (0);
	else if (b_map[(int)f->curwall.x][(int)f->curwall.y].floor >= 65
		&& b_map[(int)f->curwall.x][(int)f->curwall.y].floor <= 76)
		return (b_map[(int)f->curwall.x][(int)f->curwall.y].floor);
	else
		return (-1);
}

void		water_floor(t_boxel **b, t_ray *r, SDL_Surface **img, t_floor f)
{
	if (water_tile(b, &f) != -1)
	{
		get_lgt_fl_col(img, b, r, &f);
		draw_point(img, r->x, f.y, f.color);
	}
	else
	{
		get_floor_color(b, r, &f, 'F');
		if (f.raw != 0xFFFF00)
			draw_point(img, r->x, f.y, f.color);
	}
}

int			water_animation(t_boxel **b_map)
{
	if (b_map[0][0].anim >= 0 && b_map[0][0].anim <= 0.09)
		return (86);
	else if (b_map[0][0].anim > 0.09 && b_map[0][0].anim <= 0.18)
		return (87);
	else if (b_map[0][0].anim > 0.18 && b_map[0][0].anim <= 0.27)
		return (88);
	else if (b_map[0][0].anim > 0.27 && b_map[0][0].anim <= 0.36)
		return (89);
	else if (b_map[0][0].anim > 0.36 && b_map[0][0].anim <= 0.45)
		return (90);
	else if (b_map[0][0].anim > 0.45 && b_map[0][0].anim <= 0.54)
		return (91);
	else if (b_map[0][0].anim > 0.54 && b_map[0][0].anim <= 0.63)
		return (92);
	else if (b_map[0][0].anim > 0.63 && b_map[0][0].anim <= 0.72)
		return (93);
	else if (b_map[0][0].anim > 0.72 && b_map[0][0].anim <= 0.81)
		return (94);
	else if (b_map[0][0].anim > 0.81 && b_map[0][0].anim <= 0.9)
		return (95);
	else if (b_map[0][0].anim > 0.9 && b_map[0][0].anim <= 1.01)
		return (96);
	else
		return (0);
}

t_color8	get_mask(t_boxel **b_map, t_floor *f, int tex_num)
{
	SDL_PixelFormat	*fmt;
	t_color8		c;
	t_fpoint		tex;

	f->pixel = (Uint32 *)b_map[0][0].textures[tex_num]->pixels;
	fmt = b_map[0][0].textures[tex_num]->format;
	tex.x = (int)(f->floortex.x / 4) * fmt->BytesPerPixel;
	tex.y = (int)(f->floortex.y / 4) * b_map[0][0].textures[tex_num]->pitch;
	f->raw = *(f->pixel + (int)tex.y + (int)tex.x);
	SDL_GetRGB(f->raw, fmt, &c.r, &c.g, &c.b);
	return (c);
}

t_color		get_alpha(t_color bg, t_color8 mask, int opacity)
{
	t_color		color;

	if (bg.r >= mask.r)
		color.r = bg.r - (abs(bg.r - mask.r) / opacity);
	else if (mask.r > bg.r)
		color.r = bg.r + (abs(mask.r - bg.r) / opacity);
	if (bg.g >= mask.g)
		color.g = bg.g - (abs(bg.g - mask.g) / opacity);
	else if (mask.g > bg.g)
		color.g = bg.g + (abs(mask.g - bg.g) / opacity);
	if (bg.b >= mask.b)
		color.b = bg.b - (abs(bg.b - mask.b) / opacity);
	else if (mask.b > bg.b)
		color.b = bg.b + (abs(mask.b - bg.b) / opacity);
	return (color);
}
