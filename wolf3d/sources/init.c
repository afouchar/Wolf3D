/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:25 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:25 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			get_nb_lines(char *sprite_file)
{
	int		fd;
	char	*buf;
	int		i;

	i = 0;
	if ((fd = open(sprite_file, O_RDONLY)) > 0)
	{
		buf = (char *)malloc(sizeof(char) * 2);
		while (read(fd, buf, 1) > 0)
		{
			if (buf[0] == '\n' || buf[0] == '\0')
			{
				buf[0] = '\0';
				i++;
			}
		}
		close(fd);
		free(buf);
		return (i + 1);
	}
	return (-1);
}

t_sprite	*get_sprites(char *file_name, t_boxel **boxel)
{
	char		*sprite_file;
	char		*tmp_str;
	t_sprite	*tab;
	int			fd;
	int			i;

	tmp_str = ft_strsub(file_name, 0, ft_strlen(file_name) - 4);
	sprite_file = ft_strjoin(tmp_str, ".spr");
	free(tmp_str);
	if ((i = get_nb_lines(sprite_file)) > 0)
		tab = (t_sprite *)malloc(sizeof(t_sprite) * (i + 1));
	i = 0;
	if ((fd = open(sprite_file, O_RDONLY)) > 0)
	{
		while (get_line(fd, &tmp_str) == 1)
		{
			tab[i++] = create_sprite_line(tmp_str, boxel);
			free(tmp_str);
		}
		free(tmp_str);
		close(fd);
	}
	free(sprite_file);
	boxel[0][0].nb_sprites = i;
	return (tab);
}

void		init_values_boxel(t_boxel **boxel, char *file_name, t_point pt)
{
	boxel[0][0].lines = pt.y;
	boxel[0][0].values = get_values(boxel);
	boxel[0][0].textures = load_textures();
	boxel[0][0].level = ft_strdup(file_name);
	boxel[0][0].islevel = find_level(boxel);
	boxel[0][0].sprite = get_sprites(file_name, boxel);
	boxel[0][0].tex_sprite = load_sprites();
	boxel[0][0].tex_weapon = load_weapon();
	boxel[0][0].tex_sky = load_sky();
	boxel[0][0].killfog = 1;
	boxel[0][0].anim = 0;
	boxel[0][0].bgm = NULL;
	boxel[0][0].cur_music = 7;
	boxel[0][0].cur_walk = 38;
	boxel[0][0].move_sky = 0;
}

t_boxel		**create_boxel_map(char *file_name)
{
	t_boxel	**boxel;
	t_point	pt;
	int		fd;
	char	*tmp_str;

	pt.x = 0;
	pt.y = 0;
	boxel = (t_boxel **)malloc(sizeof(t_boxel *) * file_size(file_name));
	if ((fd = open(file_name, O_RDONLY)) > 0)
	{
		while (get_line(fd, &tmp_str) == 1)
		{
			boxel[pt.y] = create_boxels_line(tmp_str);
			pt.y++;
		}
		close(fd);
		free(tmp_str);
		init_values_boxel(boxel, file_name, pt);
	}
	return (boxel);
}

SDL_Surface	**load_textures(void)
{
	SDL_Surface **texture;

	texture = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 100);
	texture[0] = SDL_LoadBMP("./textures/fields/empty.bmp");
	texture[1] = SDL_LoadBMP("./textures/village/pavement.bmp");
	texture[2] = SDL_LoadBMP("./textures/village/rooftop.bmp");
	texture[3] = SDL_LoadBMP("./textures/village/shelf.bmp");
	texture[4] = SDL_LoadBMP("./textures/village/wall_brick_door_home.bmp");
	texture[5] = SDL_LoadBMP("./textures/village/wall_brick_door_level.bmp");
	texture[6] = SDL_LoadBMP("./textures/village/wall_brick_door_shop.bmp");
	texture[7] = SDL_LoadBMP("./textures/village/wall_brick_door.bmp");
	texture[8] = SDL_LoadBMP("./textures/village/wall_brick_ivy.bmp");
	texture[9] = SDL_LoadBMP("./textures/village/wall_brick_window.bmp");
	texture[10] = SDL_LoadBMP("./textures/village/wall_brick.bmp");
	load_textures2(texture);
	load_textures3(texture);
	load_textures4(texture);
	load_textures5(texture);
	load_textures6(texture);
	return (texture);
}
