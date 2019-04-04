/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:05 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:05 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_texture_bis(SDL_Surface **image, t_ray *r, t_boxel **b_map, int t)
{
	int		py;
	int		pry;

	py = 0;
	pry = r->y;
	if (r->curcol != 0xFFFF00)
	{
		if (t == 2)
			pry = (r->y + r->p) - (r->lineheight * r->p);
		draw_point(image, r->x, pry, r->color);
		if ((py = reflect(r, b_map, t)) > 0)
		{
			to_alpha(r);
			draw_point(image, r->x, py, r->color);
		}
	}
}

void	draw_texture(SDL_Surface **img, t_ray *r, t_player *p, t_boxel **b_map)
{
	int		py;

	get_height(img, r);
	py = 0;
	r->tex.x = get_texx(r);
	r->y = r->drawstart;
	while (r->y < r->drawend)
	{
		r->p = 1;
		get_side_color(img, r, p, b_map);
		draw_texture_bis(img, r, b_map, 1);
		if (b_map[r->mapx][r->mapy].wall > 1)
		{
			while (r->p < b_map[r->mapx][r->mapy].wall &&
			((r->y + r->p) - (r->lineheight * r->p)) > 0)
			{
				get_tiers_color(img, r, b_map, r->p);
				draw_texture_bis(img, r, b_map, 2);
				r->p++;
			}
		}
		r->y++;
	}
	r->zbuffer[r->x] = r->perpwalldist;
}
