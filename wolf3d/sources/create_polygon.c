/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_polygon.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:07:01 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:07:01 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_point		create_point(int x, int y)
{
	t_point		pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

t_fline		create_fline(float p1x, float p1y, float p2x, float p2y)
{
	t_fline	fline;

	fline.p1.x = p1x;
	fline.p1.y = p1y;
	fline.p2.x = p2x;
	fline.p2.y = p2y;
	return (fline);
}

t_line		create_line(int p1x, int p1y, int p2x, int p2y)
{
	t_line	line;

	line.p1.x = p1x;
	line.p1.y = p1y;
	line.p2.x = p2x;
	line.p2.y = p2y;
	return (line);
}

t_square	create_square(int posx, int posy, int width, int height)
{
	t_square	sq;

	sq.p1.x = posx;
	sq.p1.y = posy;
	sq.p2.x = posx + width;
	sq.p2.y = posy;
	sq.p3.x = posx;
	sq.p3.y = posy + height;
	sq.p4.x = posx + width;
	sq.p4.y = posy + height;
	sq.width = width;
	sq.height = height;
	return (sq);
}

SDL_Rect	create_rect(int x, int y, int w, int h)
{
	SDL_Rect	rect;

	rect.x = x;
	rect.y = y;
	rect.h = h;
	rect.w = w;
	return (rect);
}
