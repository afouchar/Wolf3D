/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:36 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:36 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_bg(SDL_Rect *srt, SDL_Rect *drt, int *size_img, t_boxel **b_map)
{
	srt->y = 300;
	srt->h = 300;
	srt->w = 800;
	drt->x = 1;
	drt->y = 0;
	drt->h = 500;
	drt->w = 500;
	if (b_map[0][0].islevel == HOUSE || b_map[0][0].islevel == SHOP)
	{
		srt->y = 0;
		srt->h = 1000;
		drt->h = 1000;
	}
	else if (b_map[0][0].islevel == FIELDS)
	{
		srt->y = 110;
		srt->h = 600;
	}
	*size_img = b_map[0][0].tex_sky[b_map[0][0].islevel]->w - 815;
}

int		find_level(t_boxel **b_map)
{
	int		level;

	level = HOUSE;
	if (ft_strcmp(b_map[0][0].level, "./maps/church_place.w3d") == 0)
		level = PLACE;
	if (ft_strcmp(b_map[0][0].level, "./maps/village.w3d") == 0)
		level = VILLAGE;
	if (ft_strcmp(b_map[0][0].level, "./maps/test.w3d") == 0)
		level = HOUSE;
	if (ft_strcmp(b_map[0][0].level, "./maps/church.w3d") == 0)
		level = CHURCH;
	if (ft_strcmp(b_map[0][0].level, "./maps/house.w3d") == 0)
		level = HOUSE;
	if (ft_strcmp(b_map[0][0].level, "./maps/shop.w3d") == 0)
		level = SHOP;
	if (ft_strcmp(b_map[0][0].level, "./maps/fields.w3d") == 0)
		level = FIELDS;
	return (level);
}

void	draw_bg_bis(SDL_Surface *img, t_boxel **b_map, t_player *p, t_bg *bg)
{
	if (bg->srt.x < 0 && bg->srt.x > -img->w)
	{
		bg->drt.w = img->w - bg->srt.x * -1;
		SDL_BlitSurface(b_map[0][0].tex_sky[bg->num], &bg->srt, img, &bg->drt);
		bg->drt.w = img->w - bg->drt.w;
		bg->srt.w = bg->drt.w + 1;
		bg->drt.x = 1;
		bg->srt.x = (bg->wgt_img + img->w) - bg->srt.w;
		SDL_BlitSurface(b_map[0][0].tex_sky[bg->num], &bg->srt, img, &bg->drt);
	}
	else if (bg->srt.x <= -img->w)
	{
		bg->srt.x = bg->wgt_img;
		SDL_BlitSurface(b_map[0][0].tex_sky[bg->num], &bg->srt, img, &bg->drt);
		p->anglesky = bg->wgt_img / 30;
	}
	else
		SDL_BlitSurface(b_map[0][0].tex_sky[bg->num], &bg->srt, img, &bg->drt);
}

void	draw_background(SDL_Surface *img, t_player *p, t_boxel **b_map)
{
	t_bg		bg;

	if (b_map[0][0].islevel != FIELDS && b_map[0][0].islevel != HOUSE)
		bg.srt.x = p->anglesky * 30 + b_map[0][0].move_sky;
	else
		bg.srt.x = p->anglesky * 30;
	bg.num = b_map[0][0].islevel;
	init_bg(&bg.srt, &bg.drt, &bg.wgt_img, b_map);
	if (bg.srt.x > bg.wgt_img && bg.srt.x < (bg.wgt_img + img->w))
	{
		bg.drt.w = img->w - (bg.srt.x - bg.wgt_img);
		SDL_BlitSurface(b_map[0][0].tex_sky[bg.num], &bg.srt, img, &bg.drt);
		bg.drt.x = img->w - (bg.srt.x - bg.wgt_img);
		bg.srt.x = 1;
		SDL_BlitSurface(b_map[0][0].tex_sky[bg.num], &bg.srt, img, &bg.drt);
	}
	else if (bg.srt.x > (bg.wgt_img + img->w))
	{
		bg.srt.x = 1;
		SDL_BlitSurface(b_map[0][0].tex_sky[bg.num], &bg.srt, img, &bg.drt);
		p->anglesky = 0;
	}
	else
		draw_bg_bis(img, b_map, p, &bg);
}
