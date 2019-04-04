/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:03:58 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:03:58 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_water_mask_num(int tex_num)
{
	int		mask;

	mask = 58;
	if (tex_num == 63)
	{
		if (SDL_GetTicks() % 3 == 0)
			mask = 80;
		else if (SDL_GetTicks() % 2 == 0)
			mask = 81;
		else
			mask = 82;
	}
	else if (tex_num == 64)
	{
		if (SDL_GetTicks() % 3 == 0)
			mask = 83;
		else if (SDL_GetTicks() % 2 == 0)
			mask = 84;
		else
			mask = 85;
	}
	return (mask);
}

int			get_mask_num(t_boxel **b_map, int tex_num)
{
	int		mask;

	mask = 58;
	if (tex_num == 34)
		mask = 56;
	else if (tex_num == 46)
		mask = 59;
	else if (tex_num == 49 || tex_num == 50)
		mask = 97;
	else if (tex_num == 35 || tex_num == 43)
	{
		if ((int)b_map[0][0].p_time % 3 == 0)
			mask = 60;
		else if ((int)b_map[0][0].p_time % 2 == 0)
			mask = 78;
		else
			mask = 79;
	}
	else
		mask = get_water_mask_num(tex_num);
	return (mask);
}

t_color8	get_tex_mask(SDL_Surface **img, t_boxel **b_map, t_ray *r, int tnum)
{
	SDL_PixelFormat		*fmt;
	Uint32				*pixelslayout;
	t_color8			c;
	int					mask;

	mask = get_mask_num(b_map, tnum);
	r->tex.y = get_texy(img, b_map, r, mask);
	pixelslayout = (Uint32 *)b_map[0][0].textures[mask]->pixels;
	fmt = b_map[0][0].textures[mask]->format;
	r->curcollayout = *(pixelslayout + (int)r->tex.y +
	(int)((r->tex.x / 4) * fmt->BytesPerPixel));
	SDL_GetRGB(r->curcollayout, fmt, &c.r, &c.g, &c.b);
	return (c);
}

int			lampside(t_boxel **b_map, t_ray *r, int i)
{
	if ((int)(b_map[0][0].sprite[i].x) == r->mapx - 1 &&
	(int)(b_map[0][0].sprite[i].y) == r->mapy &&
	b_map[0][0].tier_shadow == 'N')
		return (1);
	else if ((int)(b_map[0][0].sprite[i].x) == r->mapx + 1 &&
	(int)(b_map[0][0].sprite[i].y) == r->mapy &&
	b_map[0][0].tier_shadow == 'S')
		return (1);
	else if ((int)(b_map[0][0].sprite[i].x) == r->mapx &&
	(int)(b_map[0][0].sprite[i].y - 1) == r->mapy &&
	b_map[0][0].tier_shadow == 'W')
		return (1);
	else if ((int)(b_map[0][0].sprite[i].x) == r->mapx &&
	(int)(b_map[0][0].sprite[i].y + 1) == r->mapy &&
	b_map[0][0].tier_shadow == 'E')
		return (1);
	else
		return (0);
}

int			ft_check_lamppost(t_boxel **b_map, t_ray *r, char side)
{
	int i;

	i = 0;
	if (side == 'T' || side == 'M')
	{
		while (i < b_map[0][0].nb_sprites)
		{
			if (b_map[0][0].sprite[i].texture == 14
			&& b_map[0][0].sprite[i].show == 1)
			{
				if (lampside(b_map, r, i) == 1)
					return (1);
			}
			i++;
		}
	}
	return (0);
}
