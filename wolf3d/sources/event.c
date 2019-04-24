/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:08:09 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:08:09 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	talk_event(t_player *player)
{
	int		r;

	if (player->press.talk == 0)
	{
		r = rand() % 3 + 1;
		if (r == 1 && player->items.boss == 1)
			Mix_PlayChannel(-1, player->monk_haaa, 0);
		else if (r == 2 && player->items.boss == 1)
			Mix_PlayChannel(-1, player->monk_yes, 0);
		else if (r == 3 && player->items.boss == 1)
			Mix_PlayChannel(-1, player->monk_try, 0);
		else if (player->items.boss == 0)
			Mix_PlayChannel(-1, player->monk_morning, 0);
		player->press.talk = 1;
	}
	else
	{
		player->monk_say = 0;
		player->press.talk = 0;
	}
}

void	key_shop(t_boxel **b, t_player *p, t_win_surface *ws, t_window *win)
{
	if (b[0][0].islevel == SHOP && load_level(p, b) == NULL)
		shop_menu(win, ws, p, b);
	else if (b[0][0].islevel == HOUSE && load_level(p, b) == NULL)
		craft_menu(win, ws, p, b);
}

int		poll_event(t_win_surface *ws, t_window *win, t_player *p, t_boxel **b)
{
	SDL_Event		ev;

	while (SDL_PollEvent(&ev) != 0)
	{
		light_mouse_key(&ev, p, b);
		fwd_bkwd_key(&ev, p, win);
		straf_key(&ev, p);
		dash_key(&ev, p);
		shoot_key(&ev, p, b);
		if (ev.key.keysym.sym == SDLK_e && ev.key.state == SDL_RELEASED)
		{
			if ((p->level = load_level(p, b)) != NULL)
				return (1);
			else if (talk_pos(p, b) != -1)
				talk_event(p);
			else if (loot_pos(p, b) != -1)
				loot_objects(p, b);
		}
		else if (ev.key.keysym.sym == SDLK_e && ev.key.state == SDL_PRESSED)
			key_shop(b, p, ws, win);
	}
	return (0);
}
