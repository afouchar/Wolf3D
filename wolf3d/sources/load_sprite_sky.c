/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_sky.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:49 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:49 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			load_sprites2(SDL_Surface **sprite)
{
	sprite[12] = SDL_LoadBMP("./sprites/objects/small_table.bmp");
	sprite[13] = SDL_LoadBMP("./sprites/objects/arrow.bmp");
	sprite[14] = SDL_LoadBMP("./sprites/objects/lamppost.bmp");
	sprite[15] = SDL_LoadBMP("./sprites/objects/bush.bmp");
	sprite[16] = SDL_LoadBMP("./sprites/objects/fountain.bmp");
	sprite[17] = SDL_LoadBMP("./sprites/objects/foam_1.bmp");
	sprite[18] = SDL_LoadBMP("./sprites/objects/foam_2.bmp");
	sprite[19] = SDL_LoadBMP("./sprites/objects/rocks.bmp");
	sprite[20] = SDL_LoadBMP("./sprites/objects/tree.bmp");
	sprite[21] = SDL_LoadBMP("./sprites/objects/deer.bmp");
	sprite[22] = SDL_LoadBMP("./sprites/people/boss.bmp");
	sprite[23] = SDL_LoadBMP("./sprites/objects/sconce.bmp");
}

SDL_Surface		**load_sprites(void)
{
	SDL_Surface **sprite;

	sprite = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 24);
	sprite[0] = SDL_LoadBMP("./sprites/people/man_1.bmp");
	sprite[1] = SDL_LoadBMP("./sprites/people/man_2.bmp");
	sprite[2] = SDL_LoadBMP("./sprites/people/man_3.bmp");
	sprite[3] = SDL_LoadBMP("./sprites/people/man_4.bmp");
	sprite[4] = SDL_LoadBMP("./sprites/people/monk_1.bmp");
	sprite[5] = SDL_LoadBMP("./sprites/people/woman_1.bmp");
	sprite[6] = SDL_LoadBMP("./sprites/people/woman_2.bmp");
	sprite[7] = SDL_LoadBMP("./sprites/people/woman_3.bmp");
	sprite[8] = SDL_LoadBMP("./sprites/people/woman_4.bmp");
	sprite[9] = SDL_LoadBMP("./sprites/objects/tall_grass.bmp");
	sprite[10] = SDL_LoadBMP("./sprites/objects/purse.bmp");
	sprite[11] = SDL_LoadBMP("./sprites/objects/toolbox.bmp");
	load_sprites2(sprite);
	return (sprite);
}

SDL_Surface		**load_sky(void)
{
	SDL_Surface **texture;

	texture = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 6);
	texture[0] = SDL_LoadBMP("./textures/sky/sky_house.bmp");
	texture[1] = SDL_LoadBMP("./textures/sky/sky_shop.bmp");
	texture[2] = SDL_LoadBMP("./textures/sky/sky_village.bmp");
	texture[3] = SDL_LoadBMP("./textures/sky/sky_place.bmp");
	texture[4] = SDL_LoadBMP("./textures/sky/sky_church.bmp");
	texture[5] = SDL_LoadBMP("./textures/sky/sky_fields.bmp");
	return (texture);
}

SDL_Surface		**load_weapon(void)
{
	SDL_Surface **weapon;

	weapon = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 4);
	weapon[0] = SDL_LoadBMP("./weapons/small_bow.bmp");
	weapon[1] = SDL_LoadBMP("./weapons/bow.bmp");
	weapon[2] = SDL_LoadBMP("./weapons/crossbow.bmp");
	return (weapon);
}
