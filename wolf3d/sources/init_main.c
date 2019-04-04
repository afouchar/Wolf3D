/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:14 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:14 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_new_lvl(t_win_surface *ws, t_window *win, t_player *p, t_boxel **b)
{
	if (b[0][0].islevel == HOUSE)
		get_objects(p, b);
	init_win_surface(ws, win, p);
	init_pressed(&p->press);
	Mix_PlayChannel(-1, p->door_open, 0);
}

void	init_all(t_win_surface *ws, t_window *win, t_player *p, t_boxel **b_map)
{
	srand(time(NULL));
	init_pressed(&p->press);
	p->items.money = 0;
	p->items = init_items();
	init_win_surface(ws, win, p);
	win->run = start_menu(win, ws, b_map);
	SDL_SetRelativeMouseMode(SDL_TRUE);
}

void	set_loop(t_win_surface *ws, t_window *win, t_player *p, t_boxel **b_map)
{
	if (water_animation(b_map) % 2 == 0)
		b_map[0][0].move_sky += 0.5;
	play_music(p, b_map);
	p->old_time = p->p_time;
	p->p_time = SDL_GetTicks();
	b_map[0][0].p_time = p->p_time;
	p->frame_time = (p->p_time - p->old_time) / 1000.0;
	b_map[0][0].anim += p->frame_time;
	if (b_map[0][0].anim > 1.01)
		b_map[0][0].anim = 0;
	if (p->frame_time > 0.2)
		p->frame_time = 0.2;
	p->move_speed = p->frame_time * MV_SPEED;
	p->rot_speed = p->frame_time * ROT_SPEED;
	ws->plane = SDL_GetWindowSurface(win->win);
	win->image = SDL_CreateRGBSurface(0,
	win->width, win->height, 32, 0, 0, 0, 0);
}

void	end_loop(t_win_surface *ws, t_window *win, t_player *p, t_boxel **b_map)
{
	set_move(p, b_map);
	draw_image(&win->image, p, b_map);
	set_talk(&win->image, p);
	blit_main(ws, win, p);
}

int		reset_death(t_win_surface *ws, t_window *win, t_player *p, t_boxel **b)
{
	if (p->items.hp <= 0)
	{
		win->run = start_menu(win, ws, b);
		p->items.hp = p->items.max_hp;
		p->dir.x = 0;
		p->dir.y = -1;
		p->plane.x = -0.66;
		p->plane.y = 0;
		p->pos.x = 27.5;
		p->pos.y = 56.5;
		return (0);
	}
	return (1);
}
