/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:24 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:24 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_sfog			init_col_struct(int tex_num, int y, t_player *p, t_color *color)
{
	t_sfog g;

	g.tex_num = tex_num;
	g.y = y;
	g.ds = p->ds;
	g.i = p->ds.i;
	g.col = color;
	return (g);
}

void			ft_swap_int(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_swap_float(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			get_sprite_size(t_disp_sprite *ds, int tex_num)
{
	if (tex_num == 14)
	{
		ds->vmove = 256;
		ds->multw = 1;
		ds->mult = 2;
	}
	else if (tex_num == 15)
	{
		ds->vmove = -192;
		ds->multw = 0.8;
		ds->mult = 0.8;
	}
	else if (tex_num == 20 || tex_num == 22)
	{
		ds->vmove = 256;
		ds->multw = 2;
		ds->mult = 2;
	}
	else
	{
		ds->multw = 1;
		ds->mult = 1;
		ds->vmove = 0;
	}
}
