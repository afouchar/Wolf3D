/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:50 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:50 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_line(SDL_Surface **image, t_line *line, t_color c)
{
	t_point		pt;

	if (line->p1.x < (*image)->w && line->p1.y < (*image)->h)
	{
		pt.x = line->p1.x;
		pt.y = line->p1.y;
		while ((pt.x <= line->p2.x) && (line->p2.x - line->p1.x) != 0)
		{
			draw_point(image, pt.x, line->p1.y + ((line->p2.y - line->p1.y)
			* (pt.x - line->p1.x)) / (line->p2.x - line->p1.x), c);
			pt.x++;
		}
		while (pt.y <= line->p2.y && (line->p2.y - line->p1.y) != 0)
		{
			draw_point(image, line->p1.x + ((line->p2.x - line->p1.x)
			* (pt.y - line->p1.y)) / (line->p2.y - line->p1.y), pt.y, c);
			pt.y++;
		}
	}
	draw_line2(image, line, c);
}

void	draw_line2(SDL_Surface **image, t_line *line, t_color c)
{
	t_point		pt;

	pt.x = line->p2.x;
	pt.y = line->p2.y;
	while (pt.y <= line->p1.y && (line->p1.y - line->p2.y) != 0)
	{
		draw_point(image, line->p2.x + ((line->p1.x - line->p2.x) * (pt.y -
		line->p2.y)) / (line->p1.y - line->p2.y), pt.y, c);
		pt.y++;
	}
	while ((pt.x <= line->p1.x) && (line->p1.x - line->p2.x) != 0)
	{
		draw_point(image, pt.x, line->p2.y + ((line->p1.y - line->p2.y) *
		(pt.x - line->p2.x)) / (line->p1.x - line->p2.x), c);
		pt.x++;
	}
}

void	draw_fline(SDL_Surface **image, t_fline *line, t_color c)
{
	t_fpoint	pt;

	if (line->p1.x < (*image)->w && line->p1.y < (*image)->h)
	{
		pt.x = line->p1.x;
		pt.y = line->p1.y;
		while ((pt.x <= line->p2.x) && (line->p2.x - line->p1.x) != 0)
		{
			draw_point(image, pt.x, line->p1.y + ((line->p2.y - line->p1.y)
			* (pt.x - line->p1.x)) / (line->p2.x - line->p1.x), c);
			pt.x++;
		}
		while (pt.y <= line->p2.y && (line->p2.y - line->p1.y) != 0)
		{
			draw_point(image, line->p1.x + ((line->p2.x - line->p1.x)
			* (pt.y - line->p1.y)) / (line->p2.y - line->p1.y), pt.y, c);
			pt.y++;
		}
	}
	draw_fline2(image, line, c);
}

void	draw_fline2(SDL_Surface **image, t_fline *line, t_color c)
{
	t_fpoint	pt;

	pt.x = line->p2.x;
	pt.y = line->p2.y;
	while (pt.y <= line->p1.y && (line->p1.y - line->p2.y) != 0)
	{
		draw_point(image, line->p2.x + ((line->p1.x - line->p2.x) *
		(pt.y - line->p2.y)) / (line->p1.y - line->p2.y), pt.y, c);
		pt.y++;
	}
	while ((pt.x <= line->p1.x) && (line->p1.x - line->p2.x) != 0)
	{
		draw_point(image, pt.x, line->p2.y + ((line->p1.y - line->p2.y) *
		(pt.x - line->p2.x)) / (line->p1.x - line->p2.x), c);
		pt.x++;
	}
}
