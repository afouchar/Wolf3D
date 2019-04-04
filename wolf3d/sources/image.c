/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:29 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:29 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_image(SDL_Surface **image, t_player *player, t_boxel **b_map)
{
	draw_background(*image, player, b_map);
	cast_ray(image, player, b_map);
	act_name(player, b_map);
	ft_draw_crosshair(*image, b_map, player);
	init_hud(image, player);
}

void	blit_main(t_win_surface *ws, t_window *win, t_player *player)
{
	SDL_BlitSurface(win->image, NULL, ws->plane, NULL);
	SDL_UpdateWindowSurface(win->win);
	SDL_FreeSurface(player->hud.wallet_surface);
	SDL_FreeSurface(player->hud.act_surface);
	SDL_FreeSurface(ws->plane);
	SDL_FreeSurface(win->image);
	TTF_CloseFont(player->hud.font);
}
