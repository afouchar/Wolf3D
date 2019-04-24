/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:07:12 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:07:12 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		color2(char *name, t_color *c)
{
	if (ft_strcmp(name, "green") == 0)
	{
		c->r = 0;
		c->g = 255;
		c->b = 0;
		c->a = 0;
	}
	else if (ft_strcmp(name, "blue") == 0)
	{
		c->r = 0;
		c->g = 0;
		c->b = 255;
		c->a = 0;
	}
	else if (ft_strcmp(name, "grey") == 0)
	{
		c->r = 55;
		c->g = 55;
		c->b = 55;
		c->a = 0;
	}
}

t_color		color(char *name)
{
	t_color		c;

	c.r = 0;
	c.g = 0;
	c.b = 0;
	c.a = 0;
	if (ft_strcmp(name, "white") == 0)
	{
		c.r = 255;
		c.g = 255;
		c.b = 255;
		c.a = 0;
	}
	else if (ft_strcmp(name, "red") == 0)
	{
		c.r = 255;
		c.g = 0;
		c.b = 0;
		c.a = 0;
	}
	color2(name, &c);
	return (c);
}

t_color		rgba_color(int r, int g, int b, int a)
{
	t_color		c;

	if (r > 255 || r < 0)
		r = 0;
	if (g > 255 || g < 0)
		g = 0;
	if (b > 255 || b < 0)
		b = 0;
	if (a > 255 || a < 0)
		a = 0;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}
