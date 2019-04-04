/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:58 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:58 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_sprites2(SDL_Surface **img, t_boxel **b_map, t_player *p, t_ray *r)
{
	float castspritescreen;

	p->ds.sprite.x = b_map[0][0].sprite[r->sprite_order[p->ds.i]].x - p->pos.x;
	p->ds.sprite.y = b_map[0][0].sprite[r->sprite_order[p->ds.i]].y - p->pos.y;
	p->ds.invdet = 1.0 / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	p->ds.transform.x = p->ds.invdet * (p->dir.y * p->ds.sprite.x -
		p->dir.x * p->ds.sprite.y);
	p->ds.transform.y = p->ds.invdet * (-p->plane.y * p->ds.sprite.x +
		p->plane.x * p->ds.sprite.y);
	p->ds.vmovescreen = (int)(p->ds.vmove / p->ds.transform.y);
	castspritescreen = WINW2 * (1 + p->ds.transform.x / p->ds.transform.y);
	p->ds.spritescreenx = (int)castspritescreen;
	p->ds.spriteheight = fabs((int)(*img)->h / p->ds.transform.y) * p->ds.mult;
	p->ds.half_spriteh = p->ds.spriteheight / 2;
	p->ds.draw_start.y = -p->ds.half_spriteh + WINH2 + p->ds.vmovescreen;
	if (p->ds.draw_start.y < 0)
		p->ds.draw_start.y = 0;
	p->ds.draw_end.y = p->ds.half_spriteh + WINH2 + p->ds.vmovescreen;
	if (p->ds.draw_end.y >= (*img)->h)
		p->ds.draw_end.y = (*img)->h - 1;
}

void	draw_sprites3(SDL_Surface **image, t_player *player)
{
	player->ds.spritewidth = abs((int)((*image)->h / (player->ds.transform.y)))
	* player->ds.multw;
	player->ds.half_spritew = player->ds.spritewidth / 2;
	player->ds.draw_start.x = -player->ds.half_spritew +
	player->ds.spritescreenx;
	if (player->ds.draw_start.x < 0)
		player->ds.draw_start.x = 0;
	player->ds.draw_end.x = player->ds.half_spritew + player->ds.spritescreenx;
	if (player->ds.draw_end.x >= (*image)->w)
		player->ds.draw_end.x = (*image)->w - 1;
}

void	draw_sprites4(SDL_Surface **img, t_boxel **b_map, t_player *p, t_ray *r)
{
	int					y;
	Uint32				col;
	t_color				color;

	y = p->ds.draw_start.y;
	while (p->ds.stripe < p->ds.draw_end.x)
	{
		if (p->ds.transform.y > 0 && p->ds.stripe > 0 && p->ds.stripe <
		(*img)->w && p->ds.transform.y < r->zbuffer[p->ds.stripe])
		{
			p->ds.texx = (int)(256 * (p->ds.stripe - (-p->ds.spritewidth
			/ 2 + p->ds.spritescreenx)) * TEXW / p->ds.spritewidth) / 256;
			while (y < p->ds.draw_end.y)
			{
				col = get_col_sp(img, b_map, r,
init_col_struct(b_map[0][0].sprite[r->sprite_order[p->ds.i]].texture,
y, p, &color));
				if (col != 0x000000)
					draw_point(img, p->ds.stripe, ((*img)->h - y), color);
				y++;
			}
			y = p->ds.draw_start.y;
		}
		p->ds.stripe++;
	}
}

void	draw_sprites5(t_boxel **b_map, t_player *p, t_ray *r)
{
	int i;

	i = 0;
	while (i < b_map[0][0].nb_sprites)
	{
		if (b_map[0][0].sprite[i].show == 1)
		{
			if (p->items.boss == 0 && b_map[0][0].sprite[i].texture == 22)
				b_map[0][0].sprite[i].show = 0;
			r->sprite_order[i] = i;
			r->sp_dis[i] = ((p->pos.x - b_map[0][0].sprite[i].x) * (p->pos.x -
			b_map[0][0].sprite[i].x) + (p->pos.y - b_map[0][0].sprite[i].y) *
			(p->pos.y - b_map[0][0].sprite[i].y));
		}
		i++;
	}
}

void	draw_sprites(SDL_Surface **img, t_player *p, t_ray *r, t_boxel **b_map)
{
	int					i;
	int					count;

	count = 0;
	if (b_map[0][0].islevel != CHURCH)
		move_sprites(b_map, p);
	draw_sprites5(b_map, p, r);
	sort_sprites(r->sprite_order, r->sp_dis, b_map);
	i = 0;
	while (i < b_map[0][0].nb_sprites)
	{
		if (b_map[0][0].sprite[i].show == 1 && r->sp_dis[i] < DOF)
		{
			get_sprite_size(&p->ds,
			b_map[0][0].sprite[r->sprite_order[i]].texture);
			p->ds.i = i;
			draw_sprites2(img, b_map, p, r);
			draw_sprites3(img, p);
			p->ds.stripe = p->ds.draw_start.x;
			r->lineheight = p->ds.spriteheight;
			draw_sprites4(img, b_map, p, r);
			p->ds.stripe = p->ds.draw_start.x;
		}
		i++;
	}
}
