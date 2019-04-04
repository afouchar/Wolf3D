/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:07 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:07 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

size_t			file_size(const char *file)
{
	struct stat st;

	if (stat(file, &st) != 0)
		return (0);
	return (st.st_size / 100);
}

SDL_Surface		**init_thumbnails(void)
{
	SDL_Surface **thumb;

	thumb = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 12);
	thumb[0] = SDL_LoadBMP("./textures/menu/menu_shadow.bmp");
	thumb[1] = SDL_LoadBMP("./textures/menu/menu_painting.bmp");
	thumb[2] = SDL_LoadBMP("./textures/menu/menu_fireplace.bmp");
	thumb[3] = SDL_LoadBMP("./textures/menu/menu_wallpaper.bmp");
	thumb[4] = SDL_LoadBMP("./textures/menu/menu_floor.bmp");
	thumb[5] = SDL_LoadBMP("./textures/menu/menu_deer.bmp");
	thumb[6] = SDL_LoadBMP("./textures/menu/menu_decoration.bmp");
	thumb[7] = SDL_LoadBMP("./textures/menu/menu_toolshelf.bmp");
	thumb[8] = SDL_LoadBMP("./textures/menu/menu_shadow_craft.bmp");
	thumb[9] = SDL_LoadBMP("./textures/menu/menu_bow.bmp");
	thumb[10] = SDL_LoadBMP("./textures/menu/menu_crossbow.bmp");
	thumb[11] = SDL_LoadBMP("./textures/menu/menu_bow.bmp");
	return (thumb);
}

t_objects		*init_objects(void)
{
	t_objects	*obj;

	obj = (t_objects *)malloc(sizeof(t_objects) * NB_OBJ);
	obj[0].id = PAINT;
	obj[0].price = 50;
	obj[1].id = FIRE;
	obj[1].price = 130;
	obj[2].id = PAPER;
	obj[2].price = 510;
	obj[3].id = FLOOR;
	obj[3].price = 450;
	obj[4].id = DEER;
	obj[4].price = 85;
	obj[5].id = DECO;
	obj[5].price = 375;
	obj[6].id = TOOLSHELF;
	obj[6].price = 975;
	return (obj);
}

t_objects		*init_craft_objects(void)
{
	t_objects	*craft_obj;

	craft_obj = (t_objects *)malloc(sizeof(t_objects) * NB_CRAFT);
	craft_obj[0].id = SMALLBOW;
	craft_obj[0].price = 0;
	craft_obj[1].id = BOW;
	craft_obj[1].price = 75;
	craft_obj[2].id = CROSSBOW;
	craft_obj[2].price = 150;
	craft_obj[3].id = ARROW;
	craft_obj[3].price = 2;
	return (craft_obj);
}

t_items			init_items(void)
{
	int			i;
	t_items		items;

	i = 0;
	items.money = MONEY;
	items.toolbox = TBOX;
	items.weapon = STARTWEAPON;
	items.ammo = AMMO;
	items.strength = (14 + (STARTWEAPON * 2)) * (STARTWEAPON + 1);
	items.thumbnails = init_thumbnails();
	items.owned = (int *)malloc(sizeof(int) * NB_OBJ);
	items.boss = 1;
	while (i < NB_OBJ)
	{
		items.owned[i] = 0;
		i++;
	}
	items.hp = 400;
	items.max_hp = 400;
	items.nb_owned = 0;
	items.objects = init_objects();
	items.craft_objects = init_craft_objects();
	return (items);
}
