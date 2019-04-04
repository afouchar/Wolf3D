/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:05:46 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:05:46 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	load_textures6(SDL_Surface **texture)
{
	texture[80] = SDL_LoadBMP("./textures/fields/waterfall_1_mask_1.bmp");
	texture[81] = SDL_LoadBMP("./textures/fields/waterfall_1_mask_2.bmp");
	texture[82] = SDL_LoadBMP("./textures/fields/waterfall_1_mask_3.bmp");
	texture[83] = SDL_LoadBMP("./textures/fields/waterfall_2_mask_1.bmp");
	texture[84] = SDL_LoadBMP("./textures/fields/waterfall_2_mask_2.bmp");
	texture[85] = SDL_LoadBMP("./textures/fields/waterfall_2_mask_3.bmp");
	texture[86] = SDL_LoadBMP("./textures/fields/water_mask_1.bmp");
	texture[87] = SDL_LoadBMP("./textures/fields/water_mask_2.bmp");
	texture[88] = SDL_LoadBMP("./textures/fields/water_mask_3.bmp");
	texture[89] = SDL_LoadBMP("./textures/fields/water_mask_4.bmp");
	texture[90] = SDL_LoadBMP("./textures/fields/water_mask_5.bmp");
	texture[91] = SDL_LoadBMP("./textures/fields/water_mask_6.bmp");
	texture[92] = SDL_LoadBMP("./textures/fields/water_mask_7.bmp");
	texture[93] = SDL_LoadBMP("./textures/fields/water_mask_8.bmp");
	texture[94] = SDL_LoadBMP("./textures/fields/water_mask_9.bmp");
	texture[95] = SDL_LoadBMP("./textures/fields/water_mask_10.bmp");
	texture[96] = SDL_LoadBMP("./textures/fields/water_mask_11.bmp");
	texture[97] = SDL_LoadBMP("./textures/village/wall_brick_sconce_mask.bmp");
	texture[98] = SDL_LoadBMP("./textures/fields/grass_rocks.bmp");
	texture[99] = SDL_LoadBMP("./textures/menu/start_screen.bmp");
}

void	load_textures5(SDL_Surface **texture)
{
	texture[61] = SDL_LoadBMP("./textures/fields/mountain_top.bmp");
	texture[62] = SDL_LoadBMP("./textures/fields/mountain.bmp");
	texture[63] = SDL_LoadBMP("./textures/fields/waterfall_1.bmp");
	texture[64] = SDL_LoadBMP("./textures/fields/waterfall_2.bmp");
	texture[65] = SDL_LoadBMP("./textures/fields/grass_to_water_ht.bmp");
	texture[66] = SDL_LoadBMP("./textures/fields/grass_to_water_vr.bmp");
	texture[67] = SDL_LoadBMP("./textures/fields/grass_to_water_hb.bmp");
	texture[68] = SDL_LoadBMP("./textures/fields/grass_to_water_vl.bmp");
	texture[69] = SDL_LoadBMP("./textures/fields/grass_to_water_angle_tr.bmp");
	texture[70] = SDL_LoadBMP("./textures/fields/grass_to_water_in_tr.bmp");
	texture[71] = SDL_LoadBMP("./textures/fields/grass_to_water_angle_tl.bmp");
	texture[72] = SDL_LoadBMP("./textures/fields/grass_to_water_in_tl.bmp");
	texture[73] = SDL_LoadBMP("./textures/fields/grass_to_water_angle_br.bmp");
	texture[74] = SDL_LoadBMP("./textures/fields/grass_to_water_in_br.bmp");
	texture[75] = SDL_LoadBMP("./textures/fields/grass_to_water_angle_bl.bmp");
	texture[76] = SDL_LoadBMP("./textures/fields/grass_to_water_in_bl.bmp");
	texture[77] = SDL_LoadBMP("./textures/fields/wheat.bmp");
	texture[78] = SDL_LoadBMP("./textures/village/wall_brick_fire_mask_2.bmp");
	texture[79] = SDL_LoadBMP("./textures/village/wall_brick_fire_mask_3.bmp");
}

void	load_textures4(SDL_Surface **texture)
{
	texture[47] = SDL_LoadBMP("./textures/village/wall_brick_deer.bmp");
	texture[48] = SDL_LoadBMP("./textures/village/wallpaper_deer.bmp");
	texture[49] = SDL_LoadBMP("./textures/village/wall_brick_sconce.bmp");
	texture[50] = SDL_LoadBMP("./textures/village/wallpaper_sconce.bmp");
	texture[51] = SDL_LoadBMP("./textures/village/wall_toolshelf.bmp");
	texture[52] = SDL_LoadBMP("./textures/village/floor_carpet_bottom.bmp");
	texture[53] = SDL_LoadBMP("./textures/village/floor_carpet_top.bmp");
	texture[54] = SDL_LoadBMP("./textures/village/new_floor_carpet_bottom.bmp");
	texture[55] = SDL_LoadBMP("./textures/village/new_floor_carpet_top.bmp");
	texture[56] = SDL_LoadBMP("./textures/village/wall_brick_window_mask.bmp");
	texture[57] = SDL_LoadBMP("./textures/village/wall_brick_light.bmp");
	texture[58] = SDL_LoadBMP("./textures/village/lamppost_mask.bmp");
	texture[59] = SDL_LoadBMP("./textures/village/shop_counter_mask.bmp");
	texture[60] = SDL_LoadBMP("./textures/village/wall_brick_fire_mask_1.bmp");
}

void	load_textures3(SDL_Surface **texture)
{
	texture[26] = SDL_LoadBMP("./textures/fields/grass.bmp");
	texture[27] = SDL_LoadBMP("./textures/fields/ruins_top.bmp");
	texture[28] = SDL_LoadBMP("./textures/fields/ruins_wall.bmp");
	texture[29] = SDL_LoadBMP("./textures/fields/trees_top.bmp");
	texture[30] = SDL_LoadBMP("./textures/fields/trees.bmp");
	texture[31] = SDL_LoadBMP("./textures/fields/cabin_wall.bmp");
	texture[32] = SDL_LoadBMP("./textures/fields/cabin_door.bmp");
	texture[33] = SDL_LoadBMP("./textures/fields/cabin_window.bmp");
	texture[34] = SDL_LoadBMP("./textures/village/wall_brick_window_light.bmp");
	texture[35] = SDL_LoadBMP("./textures/village/wall_brick_fire.bmp");
	texture[36] = SDL_LoadBMP("./textures/village/wall_brick_window_t.bmp");
	texture[37] = SDL_LoadBMP("./textures/village/wallpaper.bmp");
	texture[38] = SDL_LoadBMP("./textures/village/wallpaper_painting.bmp");
	texture[39] = SDL_LoadBMP("./textures/village/wall_brick_painting.bmp");
	texture[40] = SDL_LoadBMP("./textures/menu/book.bmp");
	texture[41] = SDL_LoadBMP("./textures/village/wallpaper_door_home.bmp");
	texture[42] = SDL_LoadBMP("./textures/village/wallpaper_window.bmp");
	texture[43] = SDL_LoadBMP("./textures/village/wallpaper_fireplace.bmp");
	texture[44] = SDL_LoadBMP("./textures/village/new_floor.bmp");
	texture[45] = SDL_LoadBMP("./textures/village/new_rooftop.bmp");
	texture[46] = SDL_LoadBMP("./textures/village/shop_counter.bmp");
}

void	load_textures2(SDL_Surface **texture)
{
	texture[11] = SDL_LoadBMP("./textures/church/church_wall_ornament.bmp");
	texture[12] = SDL_LoadBMP("./textures/church/church_door_inside.bmp");
	texture[13] = SDL_LoadBMP("./textures/church/church_door_top.bmp");
	texture[14] = SDL_LoadBMP("./textures/church/church_door.bmp");
	texture[15] = SDL_LoadBMP("./textures/church/church_floor.bmp");
	texture[16] = SDL_LoadBMP("./textures/church/church_roof.bmp");
	texture[17] = SDL_LoadBMP("./textures/church/church_top_ornament.bmp");
	texture[18] = SDL_LoadBMP("./textures/church/church_top.bmp");
	texture[19] = SDL_LoadBMP("./textures/church/church_wall_deco_inside.bmp");
	texture[20] = SDL_LoadBMP("./textures/church/church_wall_inside.bmp");
	texture[21] = SDL_LoadBMP("./textures/church/church_wall_empty.bmp");
	texture[22] = SDL_LoadBMP("./textures/church/church_window_inside.bmp");
	texture[23] = SDL_LoadBMP("./textures/church/church_wall.bmp");
	texture[24] = SDL_LoadBMP("./textures/church/church_rose_right.bmp");
	texture[25] = SDL_LoadBMP("./textures/church/church_rose_left.bmp");
}
