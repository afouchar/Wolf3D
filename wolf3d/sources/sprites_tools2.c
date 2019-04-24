/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:21 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:21 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

Uint32	get_col_sp(SDL_Surface **image, t_boxel **b, t_ray *r, t_sfog g)
{
	SDL_PixelFormat	*bpp;
	Uint32			*pixels;
	int				d;
	t_color8		c;

	if ((int)b[0][0].p_time % 2 == 0 && g.tex_num == 17)
		g.tex_num = 18;
	else if (g.tex_num == 18)
		g.tex_num = 17;
	d = ((g.y - g.ds.vmovescreen) * 512 -
	(*image)->h * 256 + r->lineheight * 256);
	g.texy = ((d * TEXH) / r->lineheight) / 512;
	pixels = (Uint32 *)b[0][0].tex_sprite[g.tex_num]->pixels;
	bpp = b[0][0].tex_sprite[g.tex_num]->format;
	g.ds.texx = ((b[0][0].tex_sprite[g.tex_num]->w - g.ds.texx) / 4) % TEXW;
	g.texy = ((b[0][0].tex_sprite[g.tex_num]->h - g.texy - 1) / 4) % TEXH;
	g.color = *(pixels + g.texy * b[0][0].tex_sprite[g.tex_num]->pitch +
	g.ds.texx * bpp->BytesPerPixel);
	SDL_GetRGB(g.color, bpp, &c.r, &c.g, &c.b);
	set_fog_sp(b, &g, r, c);
	return (g.color);
}

int		sort_sprites2(int *order, float *dist, t_boxel **b_map, int gap)
{
	int i;
	int j;
	int swapped;

	i = 0;
	swapped = 0;
	while (i < b_map[0][0].nb_sprites - gap)
	{
		j = i + gap;
		if (b_map[0][0].sprite[i].show == 1 &&
		b_map[0][0].sprite[j].show == 1 && dist[i] < DOF)
		{
			if (dist[i] < dist[j])
			{
				ft_swap_int(&order[i], &order[j]);
				ft_swap_float(&dist[i], &dist[j]);
				swapped = 1;
			}
		}
		i++;
	}
	if (swapped == 1)
		return (1);
	return (0);
}

void	sort_sprites(int *order, float *dist, t_boxel **b_map)
{
	int gap;
	int swapped;

	gap = b_map[0][0].nb_sprites;
	swapped = 0;
	while (gap > 1 || swapped == 0)
	{
		gap *= 10;
		gap /= 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		swapped = sort_sprites2(order, dist, b_map, gap);
		if (gap == 1 && swapped == 0)
			swapped = 1;
	}
}
