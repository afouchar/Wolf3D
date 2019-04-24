/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   craft_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:07:09 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:07:09 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	selected_craft(SDL_Surface *img, t_player *p, t_menu *m, int select)
{
	if (select != -1)
	{
		if (is_craft_owned(p, select) == 1)
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

void	blit_craft_menu(SDL_Surface *img, t_player *p, t_menu *m, int nb)
{
	m->price_surface = TTF_RenderText_Blended(m->font, m->price, m->text_color);
	SDL_BlitSurface(m->price_surface, NULL, img, &m->price_object);
	SDL_FreeSurface(m->price_surface);
	SDL_SetColorKey(p->items.thumbnails[nb + 8], SDL_TRUE,
	SDL_MapRGB(p->items.thumbnails[nb + 8]->format, 255, 255, 0));
	SDL_BlitSurface(p->items.thumbnails[nb + 8], &m->object, img, &m->img);
	free(m->price);
}

void	draw_craft_menu(SDL_Surface *image, t_player *player, int select)
{
	int			nb;
	t_menu		m;

	m = init_craft_menu();
	nb = 1;
	set_toolbox(player, &m, select);
	SDL_BlitSurface(m.wallet_surface, NULL, image, &m.wallet_object);
	SDL_FreeSurface(m.wallet_surface);
	SDL_BlitSurface(m.arrow_surface, NULL, image, &m.arrow_object);
	SDL_FreeSurface(m.arrow_surface);
	while (nb < NB_CRAFT + 1)
	{
		m.name = select_craft_name(nb);
		m.price = select_craft_price(player, nb);
		set_menu_hud(&image, &m, HOUSE);
		if (nb == select)
			selected_craft(image, player, &m, select);
		else
			selected_craft(image, player, &m, -1);
		blit_craft_menu(image, player, &m, nb);
		align_selection(&m, nb);
		nb++;
	}
	TTF_CloseFont(m.font_select);
	TTF_CloseFont(m.font);
}

int		craft_event(t_player *p, int select)
{
	SDL_Event	event;

	if (SDL_PollEvent(&event) != 0)
	{
		if (event.key.keysym.sym == SDLK_e && event.key.state == SDL_PRESSED)
		{
			Mix_PlayChannel(-1, p->book_close, 0);
			Mix_VolumeMusic(MIX_MAX_VOLUME);
			select = -1;
		}
		else if (event.type == SDL_QUIT)
			exit(0);
		else if ((event.key.keysym.sym == SDLK_w
		|| event.key.keysym.sym == SDLK_w) && event.key.state == SDL_PRESSED)
			select = (select <= 1) ? NB_CRAFT : (select - 1);
		else if (event.key.keysym.sym == SDLK_s
		&& event.key.state == SDL_PRESSED)
			select = (select >= NB_CRAFT) ? 1 : (select + 1);
		else if (event.key.keysym.sym == SDLK_RETURN
		&& event.key.state == SDL_PRESSED)
			craft_objects(p, select);
	}
	return (select);
}

void	craft_menu(t_window *win, t_win_surface *ws, t_player *p, t_boxel **b)
{
	SDL_Rect	rect;
	int			select;

	select = 1;
	rect = create_rect(0, 0, win->image->w, win->image->h);
	if ((int)p->pos.x == 6 && (int)p->pos.y == 5 && is_owned(p, TOOLSHELF) == 1)
	{
		if (is_owned(p, FLOOR))
			Mix_VolumeMusic(MIX_MAX_VOLUME / 30);
		else
			Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
		Mix_PlayChannel(-1, p->book_open, 0);
		while (select != -1)
		{
			select = craft_event(p, select);
			SDL_BlitSurface(b[0][0].textures[40], &rect, win->image, &rect);
			draw_craft_menu(win->image, p, select);
			SDL_BlitSurface(win->image, NULL, ws->plane, NULL);
			SDL_FreeSurface(ws->plane);
			SDL_UpdateWindowSurface(win->win);
		}
	}
	if (is_owned(p, FLOOR))
		Mix_VolumeMusic(MIX_MAX_VOLUME / 20);
}
