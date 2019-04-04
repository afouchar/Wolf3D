/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:06:18 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:06:18 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_boxel		*create_boxels_line(char *str)
{
	t_point	pt;
	char	**infos;
	t_boxel	*boxels;

	pt.x = 0;
	pt.y = 0;
	infos = ft_strsplit(str, ' ');
	free(str);
	boxels = (t_boxel *)malloc(sizeof(t_boxel) * ft_tablen(infos));
	while (pt.x < ft_tablen(infos))
	{
		if (ft_strlen(infos[pt.x]) < 19)
		{
			ft_putendl(infos[pt.x]);
			ft_putendl(". parse error !");
			exit(0);
		}
		boxels[pt.x] = create_boxel(infos[pt.x]);
		boxels[pt.x].lines = ft_tablen(infos);
		pt.x++;
	}
	free(infos);
	return (boxels);
}

int			get_line(int fd, char **line)
{
	char	*buf;
	char	*tmp;
	int		ret;

	ret = 0;
	*line = ft_strnew(1);
	buf = (char *)malloc(sizeof(char) * 2);
	while ((ret = read(fd, buf, 1)) > 0)
	{
		buf[1] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
		if (buf[0] == '\n' || buf[0] == '\0')
		{
			free(buf);
			return (1);
		}
		free(buf);
		buf = (char *)malloc(sizeof(char) * 2);
	}
	free(buf);
	if (ret == 0 && *line[0] != '\0')
		return (1);
	return (0);
}

void		move_inside(t_sprite *sprite, t_boxel **boxel)
{
	if (sprite->y >= boxel[0][0].lines)
		sprite->y = (boxel[0][0].lines - 1.5);
	if (sprite->x >= boxel[0][0].values[(int)sprite->y])
		sprite->x = (boxel[0][0].values[(int)sprite->y] - 1.5);
}

void		random_pos(t_sprite *sprite, t_boxel **boxel)
{
	float		r;

	r = 0;
	if (boxel[0][0].islevel == FIELDS)
	{
		r = ((float)rand() / (float)(RAND_MAX)) * 5.0;
		sprite->x += (r - (int)r);
		r = ((float)rand() / (float)(RAND_MAX)) * 5.0;
		sprite->y += (r - (int)r);
	}
}

t_sprite	create_sprite_line(char *str, t_boxel **boxel)
{
	char		**tab;
	t_sprite	sprite;

	tab = ft_strsplit(str, ' ');
	sprite.x = strtof(tab[0], NULL);
	sprite.y = strtof(tab[1], NULL);
	sprite.texture = ft_atoi(tab[2]);
	if (sprite.texture == 9)
		random_pos(&sprite, boxel);
	move_inside(&sprite, boxel);
	free(tab[2]);
	free(tab[1]);
	free(tab[0]);
	free(tab);
	sprite.show = 1;
	sprite.loot = 0;
	if (sprite.texture < 9 || sprite.texture == 21)
		sprite.hp = 100;
	if (sprite.texture == 22)
		sprite.hp = BOSS_HP;
	if (sprite.texture == 10 || sprite.texture == 11 || sprite.texture == 14)
		sprite.loot = 1;
	if (sprite.texture == 13)
		sprite.show = 0;
	return (sprite);
}
