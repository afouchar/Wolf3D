/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afouchar <afouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 01:02:51 by afouchar          #+#    #+#             */
/*   Updated: 2015/06/13 01:02:51 by afouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "SDL.h"
# include "../lib_SDL/include/SDL2/SDL_ttf.h"
# include "../lib_SDL/include/SDL2/SDL_mixer.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <math.h>
# include <sys/time.h>

# define RGB (256 * 256 * (int)(c.r) + 256 * (int)(c.g) + (int)(c.b))
# define TEXW 512
# define TEXH 512
# define WINW2 400
# define WINH2 300
# define BOSS_HP 1200
# define MONEY 40000000
# define TBOX 1000
# define STARTWEAPON 0
# define AMMO 2000
# define NB_OBJ 7
# define NB_CRAFT 3
# define DOF 255
# define MV_SPEED 2.7
# define ROT_SPEED 2.2

typedef enum		e_level
{
	HOUSE,
	SHOP,
	VILLAGE,
	PLACE,
	CHURCH,
	FIELDS
}					t_level;

typedef enum		e_object
{
	PAINT = 11,
	FIRE = 12,
	PAPER = 13,
	FLOOR = 14,
	DEER = 15,
	DECO = 16,
	TOOLSHELF = 17
}					t_object;

typedef enum		e_loot
{
	PURSE = 10,
	TOOLBOX = 11
}					t_loot;

typedef enum		e_weapon
{
	SMALLBOW,
	BOW,
	CROSSBOW,
	ARROW
}					t_weapon;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_fpoint
{
	float			x;
	float			y;
}					t_fpoint;

typedef struct		s_line
{
	t_point			p1;
	t_point			p2;
}					t_line;

typedef struct		s_fline
{
	t_fpoint		p1;
	t_fpoint		p2;
}					t_fline;

typedef struct		s_square
{
	t_point			p1;
	t_point			p2;
	t_point			p3;
	t_point			p4;
	int				width;
	int				height;
}					t_square;

typedef struct		s_fsquare
{
	t_fpoint		p1;
	t_fpoint		p2;
	t_fpoint		p3;
	t_fpoint		p4;
	float			width;
	float			height;
}					t_fsquare;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_color;

typedef struct		s_color8
{
	Uint8			r;
	Uint8			g;
	Uint8			b;
	Uint8			a;
}					t_color8;

typedef struct		s_shoot
{
	int				act;
	t_fpoint		pos;
	t_fpoint		dir;
	float			move_speed;

}					t_shoot;

typedef struct		s_objects
{
	int				id;
	int				price;
}					t_objects;

typedef struct		s_items
{
	int				money;
	int				toolbox;
	int				weapon;
	int				ammo;
	int				strength;
	int				*owned;
	int				nb_owned;
	t_objects		*objects;
	t_objects		*craft_objects;
	SDL_Surface		**thumbnails;
	int				boss;
	int				hp;
	int				max_hp;
}					t_items;

typedef struct		s_menu
{
	TTF_Font		*font;
	TTF_Font		*font_select;
	SDL_Rect		img;
	SDL_Rect		object;
	SDL_Rect		select;
	SDL_Rect		hover;
	SDL_Rect		price_object;
	SDL_Surface		*price_surface;
	char			*name;
	SDL_Rect		text_object;
	SDL_Surface		*text_surface;
	SDL_Color		text_color;
	char			*price;
	SDL_Rect		wallet_object;
	SDL_Surface		*wallet_surface;
	SDL_Color		wallet_color;
	char			*wallet;
	SDL_Rect		arrow_object;
	SDL_Surface		*arrow_surface;
	SDL_Color		arrow_color;
	char			*arrow;
	SDL_Rect		esc_object;
	SDL_Surface		*esc_surface;
	SDL_Color		esc_color;
	char			*esc;
}					t_menu;

typedef struct		s_hud
{
	TTF_Font		*font;
	SDL_Rect		wallet_object;
	SDL_Surface		*wallet_surface;
	SDL_Color		wallet_color;
	char			*wallet;

	SDL_Rect		tbox_object;
	SDL_Surface		*tbox_surface;
	SDL_Color		tbox_color;
	char			*tbox;

	SDL_Rect		ammo_object;
	SDL_Surface		*ammo_surface;
	SDL_Color		ammo_color;
	char			*ammo;

	SDL_Rect		act_object;
	SDL_Surface		*act_surface;
	SDL_Color		act_color;
	char			*act;

	SDL_Rect		hp_object;
	SDL_Surface		*hp_surface;
	SDL_Color		hp_color;
	char			*hp;
}					t_hud;

typedef struct		s_press
{
	int				fwd;
	int				bkwd;
	int				lft;
	int				rgt;
	int				s_lft;
	int				s_rgt;
	int				talk;
	int				new_lvl;
}					t_press;

typedef struct		s_disp_sprite
{
	t_fpoint		sprite;
	t_fpoint		transform;
	t_point			draw_start;
	t_point			draw_end;
	float			invdet;
	int				spritescreenx;
	int				spriteheight;
	int				half_spriteh;
	int				half_spritew;
	int				spritewidth;
	int				stripe;
	int				texx;
	float			vmove;
	int				vmovescreen;
	float			mult;
	float			multw;
	int				i;
}					t_disp_sprite;

typedef struct		s_sprite
{
	float			x;
	float			y;
	int				texture;
	int				hp;
	int				show;
	int				loot;
}					t_sprite;

typedef struct		s_bg
{
	int				num;
	int				wgt_img;
	SDL_Rect		srt;
	SDL_Rect		drt;
}					t_bg;

typedef struct		s_floor
{
	float			distwall;
	float			weight;
	t_fpoint		curwall;
	t_fpoint		floortex;
	t_fpoint		floorwall;
	t_color			color;
	t_color8		tmp_col;
	Uint32			*pixel;
	Uint32			raw;
	int				tex_num;
	int				y;
}					t_floor;

typedef struct		s_boxel
{
	char			*level;
	int				lines;
	int				*values;
	int				wall;
	int				texn;
	int				texe;
	int				texs;
	int				texw;
	int				texmid;
	int				textop;
	int				floor;
	int				ceiling;
	int				door;
	char			tier_shadow;
	int				killfog;
	int				islevel;
	t_shoot			shoot;
	SDL_Surface		**textures;
	SDL_Surface		**tex_sprite;
	SDL_Surface		**tex_weapon;
	t_sprite		*sprite;
	int				nb_sprites;
	SDL_Surface		**tex_sky;
	float			move_sky;
	float			p_time;
	float			anim;
	int				cur_music;
	int				cur_walk;
	Mix_Music		*bgm;
	t_floor			f;
}					t_boxel;

typedef struct		s_window
{
	SDL_Window		*win;
	SDL_Surface		*image;
	Uint32			state;
	char			*title;
	int				width;
	int				height;
	int				posx;
	int				posy;
	int				run;
}					t_window;

typedef struct		s_win_surface
{
	SDL_Surface		*plane;
	int				centerx;
	int				centery;
	int				distance;
	int				row_angle;
}					t_win_surface;

typedef struct		s_sfog
{
	int				tex_num;
	int				y;
	t_disp_sprite	ds;
	int				i;
	t_color			*col;
	int				texy;
	Uint32			color;

}					t_sfog;

typedef struct		s_player
{
	char			*level;
	float			fov;
	float			rotate;
	t_fpoint		pos;
	t_fpoint		dir;
	t_fpoint		plane;
	int				height;
	int				angle;
	float			p_time;
	float			old_time;
	float			frame_time;
	float			rot_speed;
	float			move_speed;
	int				side;
	int				mapx;
	int				mapy;
	float			rayposx;
	float			rayposy;
	float			raydirx;
	float			raydiry;
	float			anglesky;
	int				testweapon;
	int				testshoot;
	int				anim;
	int				prevlevel;
	t_items			items;
	t_press			press;
	t_hud			hud;
	int				monk_say;
	int				dist_vol_sprite;
	int				dash;
	Mix_Chunk		*arrow;
	Mix_Chunk		*boss_hit;
	Mix_Chunk		*boss_die;
	Mix_Chunk		*deer_hit;
	Mix_Chunk		*deer_die;
	Mix_Chunk		*book_open;
	Mix_Chunk		*book_close;
	Mix_Chunk		*door_open;
	Mix_Chunk		*coin_shop;
	Mix_Chunk		*coin_shop_empty;
	Mix_Chunk		*coin_shop_already;
	Mix_Chunk		*people_die;
	Mix_Chunk		*light;
	Mix_Chunk		*boss_song;
	Mix_Chunk		*craft_weapon;
	Mix_Chunk		*craft_arrow;
	Mix_Chunk		*monk_haaa;
	Mix_Chunk		*monk_yes;
	Mix_Chunk		*monk_try;
	Mix_Chunk		*monk_morning;
	Mix_Chunk		*hit_1;
	Mix_Chunk		*hit_2;
	Mix_Chunk		*hit_3;
	Mix_Chunk		*walk_church;
	Mix_Chunk		*walk_grass;
	Mix_Chunk		*walk_house;
	Mix_Chunk		*walk_village;
	Mix_Chunk		*walk_water;
	Mix_Chunk		*loot_money;
	Mix_Chunk		*loot_toolbox;
	t_disp_sprite	ds;
}					t_player;

typedef struct		s_ray
{
	int				x;
	int				y;
	int				rec;
	float			camx;
	float			rayposx;
	float			rayposy;
	float			raydirx;
	float			raydiry;
	int				mapx;
	int				mapy;
	float			sidedistx;
	float			sidedisty;
	float			deltadistx;
	float			deltadisty;
	float			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	float			lineheight;
	float			drawstart;
	float			drawend;
	float			wallx;
	float			distancewall;
	float			*zbuffer;
	int				*sprite_order;
	float			*sp_dis;
	t_point			tex;
	t_color			color;
	t_color8		tmp_col;
	Uint32			curcol;
	Uint32			curcollayout;
	t_color8		tmp_l;
	t_fline			line;
	int				p;
}					t_ray;

void				walk_sound(t_player *player, t_boxel **b_map);
void				draw_wall(SDL_Surface **image, t_ray *r, t_player *player,
t_boxel **b_map);
void				draw_floor(SDL_Surface **image, t_ray *r, t_player *player,
t_boxel **b_map);
void				draw_background(SDL_Surface *image, t_player *player,
t_boxel **b_map);
t_point				create_point(int x, int y);
t_square			create_square(int posx, int posy, int width, int height);
t_fline				create_fline(float p1x, float p1y, float p2x, float p2y);
t_line				create_line(int p1x, int p1y, int p2x, int p2y);
SDL_Rect			create_rect(int x, int y, int w, int h);
t_boxel				create_boxel(char *str);
t_boxel				**create_boxel_map(char *file_name);
SDL_Surface			**load_textures(void);
void				load_textures2(SDL_Surface **texture);
void				load_textures3(SDL_Surface **texture);
void				load_textures4(SDL_Surface **texture);
void				load_textures5(SDL_Surface **texture);
void				load_textures6(SDL_Surface **texture);
t_items				init_items(void);
t_sprite			create_sprite_line(char *str, t_boxel **boxel);
void				load_sprites2(SDL_Surface **sprite);
SDL_Surface			**load_sprites(void);
void				init_values_boxel(t_boxel **boxel, char *file_name,
t_point pt);
SDL_Surface			**load_sky(void);
SDL_Surface			**load_weapon(void);
int					init_win(t_window *win);
void				init_win_surface(t_win_surface *win_surface, t_window *win,
t_player *player);
t_player			init_player(char *file_name, int prevlevel);
size_t				file_size(const char *file);
void				init_player_song(t_player *player);
void				init_player_song2(t_player *player);
void				init_player_pos(t_player *player, int prevlevel,
char *file_name);
void				init_player_pos1(t_player *player, int prevlevel,
char *file_name);
void				init_player_pos2(t_player *player, int prevlevel,
char *file_name);
void				init_player_pos3(t_player *player, int prevlevel,
char *file_name);
void				init_player_pos4(t_player *player, int prevlevel,
char *file_name);
void				init_player_pos5(t_player *player, char *file_name);
void				init_player_values(t_player *player);
SDL_Surface			**init_thumbnails(void);
t_objects			*init_objects(void);
t_objects			*init_craft_objects(void);
t_items				init_items(void);
void				values_boxel(t_boxel *boxel, char **num);
int					ft_tablen(char **tab);
int					*get_values(t_boxel **boxel);
t_boxel				*create_boxels_line(char *str);
int					get_line(int fd, char **line);
void				move_inside(t_sprite *sprite, t_boxel **boxel);
void				random_pos(t_sprite *sprite, t_boxel **boxel);
t_sprite			create_sprite_line(char *str, t_boxel **boxel);
void				draw_pixel(SDL_Surface **image, int x, int y, Uint32 color);
void				draw_point(SDL_Surface **image, int x, int y, t_color c);
void				draw_line(SDL_Surface **image, t_line *line, t_color c);
void				draw_line2(SDL_Surface **image, t_line *line, t_color c);
void				draw_square(SDL_Surface **image, t_square *sq, t_color c);
void				draw_fline(SDL_Surface **image, t_fline *line, t_color c);
void				draw_fline2(SDL_Surface **image, t_fline *line, t_color c);
t_color				color(char *name);
t_color				rgba_color(int r, int g, int b, int a);
int					find_level(t_boxel **b_map);
void				get_color(SDL_Surface **image, t_boxel **b_map,
t_ray *r, char side);
void				get_height(SDL_Surface **image, t_ray *r);
void				get_side_color(SDL_Surface **image, t_ray *r,
t_player *player, t_boxel **b_map);
void				get_tiers_color(SDL_Surface **image, t_ray *r,
t_boxel **b_map, int p);
void				draw_texture(SDL_Surface **image, t_ray *r,
t_player *player, t_boxel **b_map);
void				ft_swap_int(int *a, int *b);
void				ft_swap_float(float *a, float *b);
void				sort_sprites(int *order, float *dist, t_boxel **b_map);
void				draw_sprites(SDL_Surface **image, t_player *player,
t_ray *r, t_boxel **b_map);
void				move_sprites(t_boxel **b_map, t_player *player);
void				init_bg(SDL_Rect *srcrect, SDL_Rect *dstrect, int *size_img,
t_boxel **b_map);
void				draw_background_bis(SDL_Surface *image, t_boxel **b_map,
t_player *player, SDL_Rect srcrect, SDL_Rect dstrect,
int weight_img, int num_level);
void				draw_background(SDL_Surface *image, t_player *player,
t_boxel **b_map);
void				ft_draw_crosshair(SDL_Surface *image, t_boxel **b_map,
t_player *player);
void				init_shoot(t_boxel **b_map, t_player *player);
void				ft_shoot(SDL_Surface **image, t_boxel **b_map,
t_player *player);
void				ft_move_forward(t_player *player, t_boxel **b_map);
void				ft_move_backward(t_player *player, t_boxel **b_map);
void				ft_straf_right(t_player *player, t_boxel **b_map);
void				ft_straf_left(t_player *player, t_boxel **b_map);
void				ft_move_right(t_player *player);
void				ft_move_left(t_player *player);
void				get_floor_color(t_boxel **b_map, t_ray *r, t_floor *f,
char side);
void				draw_floor(SDL_Surface **image, t_ray *r, t_player *player,
t_boxel **b_map);
void				get_direction(t_ray *r, t_floor *f);
void				get_location(t_player *player, t_ray *r, t_floor *f);
int					water_animation(t_boxel **b_map);
int					get_side_fl(char side, t_boxel **b_map, t_ray *r,
t_floor *f);
t_color				get_background(SDL_Surface **image, int x, int y);
t_color8			get_mask(t_boxel **b_map, t_floor *f, int tex_num);
t_color				get_alpha(t_color bg, t_color8 mask, int opacity);
void				water_floor(t_boxel **b, t_ray *r, SDL_Surface **img,
t_floor f);
int					water_tile(t_boxel **b_map, t_floor *f);
void				get_lgt_fl_col(SDL_Surface **img, t_boxel **b, t_ray *r,
t_floor *f);
Uint32				get_shadow(char side, Uint32 shadow, int tex_num);
void				set_fog(t_ray *r, t_boxel **b_map);
void				set_fog2(t_ray *r, t_boxel **b_map);
void				set_floor_fog(t_floor *f, t_ray *r, t_boxel **b_map);
void				set_floor_fog2(t_floor *f, t_ray *r, t_boxel **b_map);
int					get_side(char side, t_boxel **b_map, t_ray *r);
int					get_texy(SDL_Surface **image, t_boxel **b_map, t_ray *r,
int tex_num);
double				radian(double deg);
int					out_of_bounds(t_boxel **b_map, t_ray r);
int					ft_hit(SDL_Surface **image, t_ray r, t_player *player,
t_boxel **b_map);
void				cast_ray(SDL_Surface **image, t_player *player,
t_boxel **b_map);
char				*load_level(t_player *player, t_boxel **b_map);
int					get_water_mask_num(int tex_num);
int					get_mask_num(t_boxel **b_map, int tex_num);
t_color8			get_tex_mask(SDL_Surface **img, t_boxel **b_map, t_ray *r,
int tnum);
void				get_tex_col(SDL_Surface **img, t_boxel **b_map, t_ray *r,
int tnum);
void				get_color_light(SDL_Surface **img, t_boxel **b, t_ray *r,
int tnum);
int					lampside(t_boxel **b_map, t_ray *r, int i);
int					ft_check_lamppost(t_boxel **b_map, t_ray *r, char side);
void				get_color_bis(SDL_Surface **img, t_boxel **b, t_ray *r,
int tnum);
int					reflect(t_ray *r, t_boxel **b_map, int tier);
void				to_alpha(t_ray *r);
void				draw_texture_bis(SDL_Surface **image, t_ray *r,
t_boxel **b_map, int t);
int					get_texx(t_ray *r);
int					out_of_level(t_player *player, t_boxel **b_map);
void				get_loot(t_player *player, int loot);
int					talk_pos(t_player *player, t_boxel **b_map);
int					loot_pos(t_player *player, t_boxel **b_map);
void				loot_objects(t_player *player, t_boxel **b_map);
int					is_owned(t_player *player, int select);
void				buy_objects(t_player *player, int select);
void				get_objects(t_player *player, t_boxel **b_map);
SDL_Color			set_font_color(int r, int g, int b, int a);
t_menu				init_menu(void);
char				*select_price(t_player *player, int nb);
char				*select_name(int nb);
void				set_menu_hud(SDL_Surface **image, t_menu *m, int place);
void				set_wallet(t_player *player, t_menu *m, int nb);
void				align_selection(t_menu *m, int nb);
void				draw_items_menu(SDL_Surface *image, t_player *player,
int select);
void				shop_menu(t_window *win, t_win_surface *win_surface,
t_player *player, t_boxel **b_map);
t_menu				init_craft_menu(void);
int					is_craft_owned(t_player *player, int select);
void				craft_objects(t_player *player, int select);
void				set_toolbox(t_player *player, t_menu *m, int nb);
char				*select_craft_name(int nb);
char				*select_craft_price(t_player *player, int nb);
void				draw_craft_menu(SDL_Surface *image, t_player *player,
int select);
void				craft_menu(t_window *win, t_win_surface *win_surface,
t_player *player, t_boxel **b_map);
void				act_name(t_player *player, t_boxel **b_map);
void				init_hud(SDL_Surface **image, t_player *player);
void				talk(SDL_Surface **image, t_player *player);
t_menu				init_start_menu(void);
char				*select_start_name(int nb);
void				draw_start_menu(SDL_Surface *image, int select);
int					start_menu(t_window *win, t_win_surface *win_surface,
t_boxel **b_map);
void				play_music(t_player *player, t_boxel **b_map);
void				walk_sound(t_player *player, t_boxel **b_map);
void				init_pressed(t_press *press);
void				copy_rtop(t_ray *r, t_player *player);
void				set_ray(SDL_Surface **image, t_player *player, t_ray *r,
int s);
char				*load_h_s_f(t_boxel **b_map, t_point *pt, t_point *pos);
char				*load_village(t_boxel **b_map, t_point *pt, t_point *pos);
char				*load_church(t_boxel **b_map, t_point *pt, t_point *pos);
void				get_deco_bis(t_boxel **b_map, t_point pt);
void				get_deco(t_player *player, t_boxel **b_map);
void				get_wall_stuff(t_boxel **b_map, t_point pt);
void				get_wallpaper(t_player *player, t_boxel **b_map);
void				get_floor_ceiling(t_player *player, t_boxel **b_map);
void				selected_items(SDL_Surface *img, t_player *p, t_menu *m,
int select);
void				blit_shop_menu(SDL_Surface *img, t_player *p, t_menu *m,
int nb);
int					shop_event(t_player *player, int select);
void				selected_craft(SDL_Surface *img, t_player *p, t_menu *m,
int select);
void				blit_craft_menu(SDL_Surface *img, t_player *p, t_menu *m,
int nb);
int					craft_event(t_player *p, int select);
void				init_hud2(SDL_Surface **image, t_player *player);
void				init_hud1(SDL_Surface **image, t_player *player);
void				selected_start(t_menu *m, t_point *size, int nb,
int select);
void				blit_start_menu(t_window *win, t_win_surface *ws,
t_boxel **b, int sel);
void				play_music2(t_player *player, t_boxel **b_map);
void				walk_standard(t_player *player, t_boxel **b_map);
void				walk_fields(t_player *player, t_boxel **b_map);
void				set_loop(t_win_surface *ws, t_window *win, t_player *p,
t_boxel **b_map);
int					reset_death(t_win_surface *ws, t_window *win, t_player *p,
t_boxel **b_map);
int					poll_event(t_win_surface *ws, t_window *win, t_player *p,
t_boxel **b_map);
void				talk_event(t_player *player);
void				light_mouse_key(SDL_Event *ev, t_player *player,
t_boxel **b_map);
void				fwd_bkwd_key(SDL_Event *ev, t_player *player,
t_window *win);
void				straf_key(SDL_Event *ev, t_player *player);
void				dash_key(SDL_Event *ev, t_player *player);
void				shoot_key(SDL_Event *ev, t_player *player,
t_boxel **b_map);
void				set_move(t_player *player, t_boxel **b_map);
void				set_talk(SDL_Surface **image, t_player *player);
void				draw_image(SDL_Surface **image, t_player *player,
t_boxel **b_map);
void				blit_main(t_win_surface *ws, t_window *win,
t_player *player);
void				init_all(t_win_surface *ws, t_window *win,
t_player *p, t_boxel **b_map);
void				init_new_lvl(t_win_surface *ws, t_window *win,
t_player *p, t_boxel **b_map);
void				end_loop(t_win_surface *ws, t_window *win, t_player *p,
t_boxel **b_map);
void				get_sprite_size(t_disp_sprite *ds, int tex_num);
void				set_fog_sp(t_boxel **b_map, t_sfog *g, t_ray *r,
t_color8 c);
Uint32				get_col_sp(SDL_Surface **image, t_boxel **b_map,
t_ray *r, t_sfog g);
t_sfog				init_col_struct(int tex_num, int y, t_player *p,
t_color *color);
void				set_fog_sp(t_boxel **b_map, t_sfog *g, t_ray *r,
t_color8 c);
void				set_fog_sp2(t_boxel **b_map, t_sfog *g, t_ray *r,
t_color8 c);
void				set_fog_sp3(t_boxel **b_map, t_sfog *g, t_ray *r,
t_color8 c);
void				set_fog_sp4(t_boxel **b_map, t_sfog *g, t_ray *r,
t_color8 c);
int					check_pos_sprite(t_boxel **b_map, t_player *player,
int x, int y);
void				move_sprites_water(t_boxel **b_map, t_player *player,
int i);
void				free_b_map(t_boxel **b_map);
void				free_music(t_player *p);
void				key_shop(t_boxel **b, t_player *p, t_win_surface *ws,
t_window *win);

#endif
