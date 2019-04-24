/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:04:09 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:04:09 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_menu	init_start_menu(void)
{
	t_menu	m;

	m.font = TTF_OpenFont("kelmscot.ttf", 18);
	m.font_select = TTF_OpenFont("kelmscot.ttf", 20);
	return (m);
}

void	selected_start(t_menu *m, t_point *size, int nb, int select)
{
	if ((nb == 0 && select == 1) || (nb == 1 && select == 0))
	{
		size->x = WINW2 - ((ft_strlen(m->name) * 10) / 2);
		m->text_object = create_rect(size->x, size->y, 120, 90);
		m->text_color = set_font_color(165, 48, 30, 255);
		m->text_surface = TTF_RenderText_Blended(m->font_select,
		m->name, m->text_color);
	}
	else
	{
		size->x = WINW2 - ((ft_strlen(m->name) * 9) / 2);
		m->text_object = create_rect(size->x, size->y, 120, 90);
		m->text_color = set_font_color(82, 82, 82, 255);
		m->text_surface = TTF_RenderText_Blended(m->font,
		m->name, m->text_color);
	}
}

void	draw_start_menu(SDL_Surface *image, int select)
{
	t_point		size;
	t_menu		m;
	int			nb;

	m = init_start_menu();
	nb = 0;
	while (nb < 2)
	{
		if (nb == 0)
			size.y = WINH2 - 20;
		else if (nb == 1)
			size.y = WINH2 + 20;
		m.name = select_start_name(nb);
		selected_start(&m, &size, nb, select);
		SDL_BlitSurface(m.text_surface, NULL, image, &m.text_object);
		SDL_FreeSurface(m.text_surface);
		free(m.name);
		nb++;
	}
	TTF_CloseFont(m.font_select);
	TTF_CloseFont(m.font);
}

void	blit_start_menu(t_window *win, t_win_surface *ws, t_boxel **b, int sel)
{
	SDL_BlitSurface(b[0][0].textures[99], NULL, win->image, NULL);
	draw_start_menu(win->image, sel);
	SDL_BlitSurface(win->image, NULL, ws->plane, NULL);
	SDL_UpdateWindowSurface(win->win);
	SDL_FreeSurface(ws->plane);
	SDL_FreeSurface(win->image);
}

int		start_menu(t_window *win, t_win_surface *win_surface, t_boxel **b_map)
{
	SDL_Event	event;
	int			menu;
	int			select;

	menu = 1;
	select = 1;
	while (menu)
	{
		win_surface->plane = SDL_GetWindowSurface(win->win);
		win->image = SDL_CreateRGBSurface(0,
		win->width, win->height, 32, 0, 0, 0, 0);
		if (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				return (0);
			else if (event.key.keysym.sym == SDLK_UP)
				select = 1;
			else if (event.key.keysym.sym == SDLK_DOWN)
				select = 0;
			else if (event.key.keysym.sym == SDLK_RETURN)
				menu = 0;
		}
		blit_start_menu(win, win_surface, b_map, select);
	}
	return (select);
}
