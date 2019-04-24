/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:54 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:54 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_point(SDL_Surface **image, int x, int y, t_color c)
{
	Uint32 *pixels;

	if (y < (*image)->h && y > 0 && x > 0 && x < (*image)->w)
	{
		pixels = (Uint32 *)(*image)->pixels;
		pixels[(y * (*image)->w) + x] = RGB;
	}
}

void	draw_pixel(SDL_Surface **image, int x, int y, Uint32 color)
{
	Uint32 *pixels;

	if (y < (*image)->h && y > 0 && x > 0 && x < (*image)->w)
	{
		pixels = (Uint32 *)(*image)->pixels;
		pixels[(y * (*image)->w) + x] = color;
	}
}

void	draw_square(SDL_Surface **image, t_square *sq, t_color c)
{
	t_point		pt;

	pt.x = sq->p1.x;
	pt.y = sq->p1.y;
	while (pt.y < sq->p3.y)
	{
		while (pt.x < sq->p2.x)
		{
			draw_point(image, pt.x, pt.y, c);
			pt.x++;
		}
		pt.x = sq->p1.x;
		pt.y++;
	}
}
