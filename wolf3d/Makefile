# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/12 16:24:15 by afouchar          #+#    #+#              #
#    Updated: 2015/06/12 17:08:31 by afouchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = @gcc

NAME = wolf3d

SOURCE = ./sources/wolf.c\
		 ./sources/ambiant_music.c\
		 ./sources/bounds.c\
		 ./sources/colors.c\
		 ./sources/cast.c\
		 ./sources/craft_menu.c\
		 ./sources/craft_stuff.c\
		 ./sources/floor.c\
		 ./sources/floor2.c\
		 ./sources/floor_water.c\
		 ./sources/free_b_p.c\
		 ./sources/fx.c\
		 ./sources/hud_stuff.c\
		 ./sources/image.c\
		 ./sources/init.c\
		 ./sources/init2.c\
		 ./sources/init3.c\
		 ./sources/init_menus.c\
		 ./sources/init_main.c\
		 ./sources/init_player_pos.c\
		 ./sources/init_player_pos2.c\
		 ./sources/level.c\
		 ./sources/loot.c\
		 ./sources/move.c\
		 ./sources/move2.c\
		 ./sources/move3.c\
		 ./sources/move_key.c\
		 ./sources/objects.c\
		 ./sources/objects_house.c\
		 ./sources/set_menus.c\
		 ./sources/shapes.c\
		 ./sources/shapes2.c\
		 ./sources/shoot.c\
		 ./sources/shop_menu.c\
		 ./sources/skybox.c\
		 ./sources/sprites.c\
		 ./sources/sprites_tools.c\
		 ./sources/sprites_tools2.c\
		 ./sources/sprites_tools3.c\
		 ./sources/draw_sprites.c\
		 ./sources/start_menu.c\
		 ./sources/textures.c\
		 ./sources/textures2.c\
		 ./sources/textures3.c\
		 ./sources/textures4.c\
		 ./sources/load_textures.c\
		 ./sources/init_player.c\
		 ./sources/create_polygon.c\
		 ./sources/load_sprite_sky.c\
		 ./sources/init_object.c\
		 ./sources/event.c\
		 ./sources/set_fog_sprite.c\

OBJECT = ./wolf.o\
		 ./ambiant_music.o\
		 ./bounds.o\
		 ./colors.o\
		 ./cast.o\
		 ./craft_menu.o\
		 ./craft_stuff.o\
		 ./floor.o\
		 ./floor2.o\
		 ./floor_water.o\
		 ./free_b_p.o\
		 ./fx.o\
		 ./hud_stuff.o\
		 ./image.o\
		 ./init.o\
		 ./init2.o\
		 ./init3.o\
		 ./init_menus.o\
		 ./init_main.o\
		 ./init_player_pos.o\
		 ./init_player_pos2.o\
		 ./level.o\
		 ./loot.o\
		 ./move.o\
		 ./move2.o\
		 ./move3.o\
		 ./move_key.o\
		 ./objects.o\
		 ./objects_house.o\
		 ./set_menus.o\
		 ./shapes.o\
		 ./shapes2.o\
		 ./shoot.o\
		 ./shop_menu.o\
		 ./skybox.o\
		 ./sprites.o\
		 ./sprites_tools.o\
		 ./sprites_tools2.o\
		 ./sprites_tools3.o\
		 ./draw_sprites.o\
		 ./start_menu.o\
		 ./textures.o\
		 ./textures2.o\
		 ./textures3.o\
		 ./textures4.o\
		 ./load_textures.o\
		 ./init_player.o\
		 ./create_polygon.o\
		 ./load_sprite_sky.o\
		 ./init_object.o\
		 ./event.o\
		 ./set_fog_sprite.o\

SDL_CFG = `./lib_SDL/bin/sdl2-config --cflags --libs`

FTYPE_CFG = `./lib_SDL/bin/freetype-config --cflags --libs`

LIB_MIXER = -lSDL2_mixer

LIB_TTF = -lSDL2_ttf

LIBFT = -L./libft -lft

FLAG = = -Wall -Wextra -Werror

O3 = -O3

SOURCE_OBJECT = $(SOURCE:.c=.o)

HDR = ./sources/wolf.h

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SOURCE_OBJECT)
	@make compil

compil: 
	@echo "_______________________________________________"
	@echo "            \x1B[38mProject wolf3d compiling\033[0m            "
	@echo "                     \033[1;37m10%\c\033[0m"
	@make -C ./libft
	@echo "\b\b\b\x1B[37m20%\c\033[0m"
	@echo "\b\b\b\x1B[37m30%\c\033[0m"
	$(CC) $(FLAG) -I ./lib_SDL/include/SDL2/ -I libft $(O3) -c $(SOURCE)
	@echo "\b\b\b\x1B[33m40%\c\033[0m"
	@echo "\b\b\b\x1B[33m50%\c\033[0m"
	$(CC) $(SDL_CFG) $(LIBFT) $(LIB_MIXER) $(LIB_TTF) $(FTYPE_CFG) $(SOURCE_OBJECT) $(O3) -o $(NAME)
	@echo "\b\b\b\x1B[33m60%\c\033[0m"
	@echo "\b\b\b\x1B[33m70%\c\033[0m"
	@make clean
	@echo "\b\b\b\x1B[31m80%\c\033[0m"
	@echo "\b\b\b\x1B[31m90%\c\033[0m"
	@echo "\b\b\b\x1B[31m100%\033[0m"
	@echo "                 \x1B[34mGame is ready\033[0m                 "
	@echo "_______________________________________________"

%.o: %.c $(HDR)
	$(CC) $(FLAG) -I ./lib_SDL/include/SDL2/ -I libft $(O3) $< -c -o $@

clean:
	@rm -Rf $(SOURCE_OBJECT)
	@rm -Rf $(OBJECT)

fclean: clean
	@echo "\033[1;31mDeleting : \033[0m$(SOURCE_OBJECT) libft.a"
	@rm -Rf ./libft/libft.a
	@rm -Rf $(NAME)
	@rm -Rf ./lib_SDL
	@echo "\033[1;31msources and executable deleted.\033[0m"

re: fclean all

install:
	mkdir lib_SDL
	cd SDL2 && ./configure --prefix=`cd ../lib_SDL && pwd` && cd ../SDL2 && make && make install
	cd freetype2 && ./configure --prefix=`cd ../lib_SDL && pwd` --with-sdl-prefix=`cd ../lib_SDL && pwd` && cd ../freetype2 && make && make install
	cd SDL2_ttf && ./configure --prefix=`cd ../lib_SDL && pwd`  --with-freetype-prefix=`cd ../lib_SDL && pwd` --with-sdl-prefix=`cd ../lib_SDL && pwd` && cd ../SDL2_ttf && make && make install
	cd SDL2_mixer && ./configure --prefix=`cd ../lib_SDL && pwd` --with-sdl-prefix=`cd ../lib_SDL && pwd` && cd ../SDL2_mixer && make && make install
	@make

finstall:
	@rm -Rf lib_SDL
	@make fclean
	@echo "\033[1;31mSDL, sources and executable deleted.\033[0m"

help:
	@echo "make:           \033[1;31mCompilation\033[0m"
	@echo "make install:   \033[1;31mInstall SDL2 Library\033[0m"
	@echo "make finstall:  \033[1;31mDelete library\033[0m"
	@echo "make clean:     \033[1;31mDelete all .o\033[0m"
	@echo "make fclean:    \033[1;31mDelete all .o - libft.a - wolf3d.exe\033[0m"
	@echo "make re:        \033[1;31mFclean and make\033[0m"
