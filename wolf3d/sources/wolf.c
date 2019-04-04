/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:03:32 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:03:32 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_pressed(t_press *press)
{
	press->fwd = 0;
	press->bkwd = 0;
	press->lft = 0;
	press->rgt = 0;
	press->s_lft = 0;
	press->s_rgt = 0;
	press->talk = 0;
	press->new_lvl = 0;
}

void	ft_free_b_map(t_boxel **b_map, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		free(b_map[i]);
		i++;
	}
	free(b_map);
}

void	main_wh(t_window *win, t_win_surface *ws, t_boxel ***b_map, t_player *p)
{
	t_items tmp_items;

	while (win->run)
	{
		if (reset_death(ws, win, p, *b_map) == 0)
			init_pressed(&p->press);
		set_loop(ws, win, p, *b_map);
		if (poll_event(ws, win, p, *b_map) == 1)
		{
			free_b_map(*b_map);
			free(b_map[0][0]->values);
			free(b_map[0][0]->level);
			if (b_map[0][0]->nb_sprites > 0)
				free(b_map[0][0]->sprite);
			Mix_FreeMusic(b_map[0][0]->bgm);
			ft_free_b_map(*b_map, b_map[0][0]->lines);
			free_music(p);
			tmp_items = p->items;
			*b_map = create_boxel_map(p->level);
			*p = init_player(p->level, p->prevlevel);
			p->items = tmp_items;
			init_new_lvl(ws, win, p, *b_map);
		}
		end_loop(ws, win, p, *b_map);
	}
}

int		main(void)
{
	t_window		win;
	t_boxel			**b_map;
	t_win_surface	win_surface;
	t_player		player;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) >= 0 && TTF_Init() >= 0)
	{
		if (init_win(&win) == 0 &&
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) >= 0)
		{
			b_map = create_boxel_map("./maps/house.w3d");
			player = init_player("./maps/house.w3d", HOUSE);
			init_all(&win_surface, &win, &player, b_map);
			main_wh(&win, &win_surface, &b_map, &player);
			Mix_FreeMusic(b_map[0][0].bgm);
			SDL_DestroyWindow(win.win);
		}
		Mix_Quit();
		SDL_Quit();
	}
	return (0);
}
