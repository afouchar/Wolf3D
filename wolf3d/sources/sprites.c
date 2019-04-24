/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:29 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:29 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_sprites_bis1(t_boxel **b_map, t_player *player, int i)
{
	if (b_map[(int)(b_map[0][0].sprite[i].x + b_map[0][0].shoot.dir.x *
b_map[0][0].shoot.move_speed)][(int)(b_map[0][0].sprite[i].y)].door == 0)
	{
		if (check_pos_sprite(b_map, player, (int)(b_map[0][0].sprite[i].x +
b_map[0][0].shoot.dir.x * b_map[0][0].shoot.move_speed),
(int)(b_map[0][0].sprite[i].y)) == 0)
		{
			b_map[0][0].sprite[i].x += b_map[0][0].shoot.dir.x
			* b_map[0][0].shoot.move_speed;
		}
		else
			b_map[0][0].sprite[i].show = 0;
	}
	else
	{
		b_map[0][0].sprite[i].show = 0;
	}
}

void	move_sprites_bis2(t_boxel **b_map, t_player *player, int i)
{
	if (b_map[(int)(b_map[0][0].sprite[i].x)][(int)(b_map[0][0].sprite[i].y +
b_map[0][0].shoot.dir.y * b_map[0][0].shoot.move_speed)].door == 0)
	{
		if (check_pos_sprite(b_map, player, (int)(b_map[0][0].sprite[i].x),
(int)(b_map[0][0].sprite[i].y +
b_map[0][0].shoot.dir.y * b_map[0][0].shoot.move_speed)) == 0)
		{
			b_map[0][0].sprite[i].y += b_map[0][0].shoot.dir.y *
b_map[0][0].shoot.move_speed;
		}
		else
			b_map[0][0].sprite[i].show = 0;
	}
	else
	{
		b_map[0][0].sprite[i].show = 0;
	}
}

void	move_sprites_rand1(t_boxel **b_map, int i, int r)
{
	if (r >= 75)
	{
		if ((int)(b_map[0][0].sprite[i].y + 0.08) < b_map[0][0].lines &&
b_map[(int)(b_map[0][0].sprite[i].x)]
[(int)(b_map[0][0].sprite[i].y + 0.08)].door == 0)
			b_map[0][0].sprite[i].y += 0.08;
	}
	else if (r < 75 && r > 50)
	{
		if ((int)(b_map[0][0].sprite[i].y - 0.08) > 0 &&
b_map[(int)(b_map[0][0].sprite[i].x)]
[(int)(b_map[0][0].sprite[i].y - 0.08)].door == 0)
			b_map[0][0].sprite[i].y -= 0.08;
	}
}

void	move_sprites_rand2(t_boxel **b_map, int i, int r)
{
	if (r <= 50 && r > 25)
	{
		if ((int)(b_map[0][0].sprite[i].x + 0.08) <
b_map[0][0].values[(int)b_map[0][0].sprite[i].y] &&
b_map[(int)(b_map[0][0].sprite[i].x + 0.08)]
[(int)(b_map[0][0].sprite[i].y)].door == 0)
			b_map[0][0].sprite[i].x += 0.08;
	}
	else if (r <= 25)
	{
		if ((int)(b_map[0][0].sprite[i].y - 0.08) > 0
				&& b_map[(int)(b_map[0][0].sprite[i].x - 0.08)]
				[(int)(b_map[0][0].sprite[i].y)].door == 0)
			b_map[0][0].sprite[i].x -= 0.08;
	}
}

void	move_sprites(t_boxel **b_map, t_player *player)
{
	int		i;
	int		r;

	i = 0;
	while (i < b_map[0][0].nb_sprites)
	{
		if (b_map[0][0].sprite[i].texture == 13 &&
		b_map[0][0].sprite[i].show == 1)
		{
			move_sprites_bis1(b_map, player, i);
			move_sprites_bis2(b_map, player, i);
		}
		if (b_map[0][0].sprite[i].show == 1 &&
(b_map[0][0].sprite[i].texture < 9 ||
b_map[0][0].sprite[i].texture == 21) && water_animation(b_map) % 2 == 0)
		{
			r = rand() % 100 + 1;
			move_sprites_rand1(b_map, i, r);
			move_sprites_rand2(b_map, i, r);
		}
		if (b_map[0][0].sprite[i].show == 1 &&
b_map[0][0].sprite[i].texture == 22 && water_animation(b_map) % 3 == 0)
			move_sprites_water(b_map, player, i);
		i++;
	}
}
