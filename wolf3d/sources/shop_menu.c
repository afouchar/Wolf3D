/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shop_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:40 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:40 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	selected_items(SDL_Surface *img, t_player *p, t_menu *m, int select)
{
	if (select != -1)
	{
		if (is_owned(p, select + 10) == 1)
			m->text_color = set_font_color(69, 78, 55, 255);
		else
			m->text_color = set_font_color(32, 32, 32, 255);
		m->text_surface = TTF_RenderText_Blended(m->font_select,
		m->name, m->text_color);
		SDL_SetColorKey(p->items.thumbnails[0], SDL_TRUE,
		SDL_MapRGB(p->items.thumbnails[0]->format, 255, 255, 0));
		SDL_BlitSurface(p->items.thumbnails[0], &m->select, img, &m->hover);
		SDL_BlitSurface(m->text_surface, NULL, img, &m->text_object);
		SDL_FreeSurface(m->text_surface);
	}
	else
	{
		m->text_color = set_font_color(82, 82, 82, 255);
		m->text_surface = TTF_RenderText_Blended(m->font,
		m->name, m->text_color);
		SDL_BlitSurface(m->text_surface, NULL, img, &m->text_object);
		SDL_FreeSurface(m->text_surface);
	}
}

void	blit_shop_menu(SDL_Surface *img, t_player *p, t_menu *m, int nb)
{
	m->price_surface = TTF_RenderText_Blended(m->font, m->price, m->text_color);
	SDL_BlitSurface(m->price_surface, NULL, img, &m->price_object);
	SDL_FreeSurface(m->price_surface);
	SDL_SetColorKey(p->items.thumbnails[nb], SDL_TRUE,
	SDL_MapRGB(p->items.thumbnails[nb]->format, 255, 255, 0));
	SDL_BlitSurface(p->items.thumbnails[nb], &m->object, img, &m->img);
	free(m->price);
}

void	draw_items_menu(SDL_Surface *image, t_player *player, int select)
{
	int			nb;
	t_menu		m;

	m = init_menu();
	set_wallet(player, &m, select);
	SDL_BlitSurface(m.wallet_surface, NULL, image, &m.wallet_object);
	SDL_FreeSurface(m.wallet_surface);
	nb = 1;
	while (nb < NB_OBJ + 1)
	{
		m.name = select_name(nb);
		m.price = select_price(player, nb);
		set_menu_hud(&image, &m, SHOP);
		if (nb == select)
			selected_items(image, player, &m, select);
		else
			selected_items(image, player, &m, -1);
		blit_shop_menu(image, player, &m, nb);
		align_selection(&m, nb);
		nb++;
	}
	TTF_CloseFont(m.font_select);
	TTF_CloseFont(m.font);
}

int		shop_event(t_player *player, int select)
{
	SDL_Event	event;

	if (SDL_PollEvent(&event) != 0)
	{
		if (event.key.keysym.sym == SDLK_e && event.key.state == SDL_PRESSED)
		{
			select = -1;
			Mix_PlayChannel(-1, player->book_close, 0);
			Mix_VolumeMusic(MIX_MAX_VOLUME);
		}
		else if (event.type == SDL_QUIT)
			exit(0);
		else if ((event.key.keysym.sym == SDLK_w
		|| event.key.keysym.sym == SDLK_z) && event.key.state == SDL_PRESSED)
			select = (select <= 1) ? NB_OBJ : (select - 1);
		else if (event.key.keysym.sym == SDLK_s
		&& event.key.state == SDL_PRESSED)
			select = (select >= NB_OBJ) ? 1 : (select + 1);
		else if (event.key.keysym.sym == SDLK_RETURN
		&& event.key.state == SDL_PRESSED)
			buy_objects(player, select);
	}
	return (select);
}

void	shop_menu(t_window *win, t_win_surface *ws, t_player *p, t_boxel **b)
{
	SDL_Rect	rect;
	int			select;

	select = 1;
	rect = create_rect(0, 0, 800, 600);
	if ((int)p->pos.x == 5 && (int)p->pos.y == 2)
	{
		Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
		Mix_PlayChannel(-1, p->book_open, 0);
		while (select != -1)
		{
			select = shop_event(p, select);
			SDL_BlitSurface(b[0][0].textures[40], &rect, win->image, &rect);
			draw_items_menu(win->image, p, select);
			SDL_BlitSurface(win->image, NULL, ws->plane, NULL);
			SDL_FreeSurface(ws->plane);
			SDL_UpdateWindowSurface(win->win);
		}
	}
}
