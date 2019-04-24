/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:21 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:21 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	light_mouse_key(SDL_Event *ev, t_player *player, t_boxel **b_map)
{
	if (ev->key.keysym.sym == SDLK_r && ev->type != SDL_MOUSEMOTION)
	{
		b_map[0][0].killfog = 15;
		Mix_PlayChannel(-1, player->light, 0);
	}
	if (ev->type == SDL_MOUSEMOTION)
	{
		if (ev->motion.xrel < 0)
			player->press.lft = 1;
		else if (ev->motion.xrel > 0)
			player->press.rgt = 1;
		ev->motion.xrel = 0;
	}
}

void	fwd_bkwd_key(SDL_Event *ev, t_player *player, t_window *win)
{
	if (ev->type != SDL_MOUSEMOTION)
	{
		if (ev->type == SDL_QUIT || ev->key.keysym.sym == SDLK_ESCAPE)
			win->run = 0;
		if (ev->key.type == SDL_KEYDOWN && (ev->key.keysym.sym == SDLK_w
		|| ev->key.keysym.sym == SDLK_z))
			player->press.fwd = 1;
		if (ev->key.type == SDL_KEYUP && (ev->key.keysym.sym == SDLK_w
		|| ev->key.keysym.sym == SDLK_z))
			player->press.fwd = 0;
		if (ev->key.type == SDL_KEYDOWN && ev->key.keysym.sym == SDLK_s)
			player->press.bkwd = 1;
		if (ev->key.type == SDL_KEYUP && ev->key.keysym.sym == SDLK_s)
			player->press.bkwd = 0;
	}
}

void	straf_key(SDL_Event *ev, t_player *player)
{
	if (ev->type != SDL_MOUSEMOTION)
	{
		if (ev->key.type == SDL_KEYDOWN && ev->key.keysym.sym == SDLK_d)
			player->press.s_rgt = 1;
		if (ev->key.type == SDL_KEYUP && ev->key.keysym.sym == SDLK_d)
			player->press.s_rgt = 0;
		if (ev->key.type == SDL_KEYDOWN && (ev->key.keysym.sym == SDLK_a
		|| ev->key.keysym.sym == SDLK_q))
			player->press.s_lft = 1;
		if (ev->key.type == SDL_KEYUP && (ev->key.keysym.sym == SDLK_a
		|| ev->key.keysym.sym == SDLK_q))
			player->press.s_lft = 0;
	}
}

void	dash_key(SDL_Event *ev, t_player *player)
{
	if (ev->type != SDL_MOUSEMOTION)
	{
		if (ev->key.type == SDL_KEYDOWN && ev->key.keysym.sym == SDLK_SPACE
		&& player->dash > 0)
		{
			player->dash--;
			player->move_speed *= 4;
		}
		if (ev->key.type == SDL_KEYUP && ev->key.keysym.sym == SDLK_SPACE)
		{
			player->dash = 6;
			player->move_speed /= 4;
		}
	}
}

void	shoot_key(SDL_Event *ev, t_player *player, t_boxel **b_map)
{
	if (ev->type != SDL_MOUSEMOTION)
	{
		if (ev->button.button == SDL_BUTTON_LEFT
		&& ev->button.state == SDL_PRESSED)
		{
			if (player->items.ammo > 0 && b_map[0][0].islevel != SHOP
			&& b_map[0][0].islevel != HOUSE && b_map[0][0].islevel != CHURCH)
			{
				init_shoot(b_map, player);
				Mix_PlayChannel(-1, player->arrow, 0);
			}
		}
	}
}
