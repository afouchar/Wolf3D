/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:07:15 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:07:15 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	copy_rtop(t_ray *r, t_player *player)
{
	player->mapx = r->mapx;
	player->mapy = r->mapy;
	player->raydirx = r->raydirx;
	player->raydiry = r->raydiry;
	player->rayposx = r->rayposx;
	player->rayposy = r->rayposy;
	player->side = r->side;
}

int		ft_hit(SDL_Surface **image, t_ray r, t_player *player, t_boxel **b)
{
	while (out_of_bounds(b, r) == 0)
	{
		if (r.sidedistx < r.sidedisty)
		{
			r.sidedistx += r.deltadistx;
			r.mapx += r.stepx;
			r.side = 0;
		}
		else
		{
			r.sidedisty += r.deltadisty;
			r.mapy += r.stepy;
			r.side = 1;
		}
		if (b[r.mapx][r.mapy].wall > 0 && r.rec < b[r.mapx][r.mapy].wall)
		{
			r.rec = b[r.mapx][r.mapy].wall;
			ft_hit(image, r, player, b);
			draw_texture(image, &r, player, b);
			draw_floor(image, &r, player, b);
			return (0);
		}
	}
	copy_rtop(&r, player);
	return (0);
}

void	set_ray(SDL_Surface **image, t_player *player, t_ray *r, int s)
{
	if (s != -1)
	{
		r->rec = 0;
		r->x = 0;
		r->zbuffer = (float *)malloc(sizeof(float) * (*image)->w);
		r->sprite_order = (int *)malloc(sizeof(int) * s + 1);
		r->sp_dis = (float *)malloc(sizeof(float) * s + 1);
	}
	else
	{
		r->camx = 2 * r->x / (float)((*image)->w) - 1;
		r->rayposx = player->pos.x;
		r->rayposy = player->pos.y;
		r->raydirx = player->dir.x + player->plane.x * r->camx;
		r->raydiry = player->dir.y + player->plane.y * r->camx;
		r->mapx = (int)(r->rayposx);
		r->mapy = (int)(r->rayposy);
		r->deltadistx = sqrt(1 + (r->raydiry * r->raydiry) /
		(r->raydirx * r->raydirx));
		r->deltadisty = sqrt(1 + (r->raydirx * r->raydirx) /
		(r->raydiry * r->raydiry));
	}
}

void	set_step(t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->rayposx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->rayposx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->rayposy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - r->rayposy) * r->deltadisty;
	}
	r->hit = 0;
}

void	cast_ray(SDL_Surface **image, t_player *player, t_boxel **b_map)
{
	t_ray	r;

	set_ray(image, player, &r, b_map[0][0].nb_sprites);
	while (r.x < (*image)->w)
	{
		set_ray(image, player, &r, -1);
		set_step(&r);
		ft_hit(image, r, player, b_map);
		r.x++;
	}
	draw_sprites(image, player, &r, b_map);
	if (b_map[0][0].killfog > 1)
		b_map[0][0].killfog--;
	if (player->testshoot > 1 && player->testweapon < 2)
	{
		player->testshoot--;
	}
	if (b_map[0][0].islevel == HOUSE && b_map[0][0].killfog > 2)
	{
		b_map[0][0].killfog -= 1;
	}
	free(r.zbuffer);
	free(r.sp_dis);
	free(r.sprite_order);
}
