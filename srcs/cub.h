/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgallien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 10:59:17 by hgallien          #+#    #+#             */
/*   Updated: 2021/03/08 11:11:25 by hgallien         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include <math.h>
# include "mlx.h"
# define N 1
# define NE 2
# define E 3
# define SE 4
# define S 5
# define SW 6
# define W 7
# define NW 8
# define R 200
# define KW 13
# define KA 0
# define KS 1
# define KD 2

typedef struct	s_var_verif
{
	int i;
	int j;
	int v;
	int p;
	int x;
	int y;
}				t_var_verif;

typedef struct	s_var_objd
{
	int		height;
	int		i;
	int		diff;
	float	x;
	float	side;
}				t_var_objd;

typedef struct	s_var_ex
{
	int timer;
	int verif;
	int ui;
	int uj;

}				t_var_ex;

typedef	struct	s_list
{
	char			*l;
	struct s_list	*next;
}				t_list;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			w;
	int			h;
}				t_data;

typedef struct	s_vecteur
{
	float x;
	float y;
}				t_vecteur;

typedef struct	s_point
{
	float x;
	float y;
}				t_point;
typedef struct	s_line
{
	float a;
	float b;
	float c;
}				t_line;

typedef struct	s_color
{
	int				red;
	int				blue;
	int				green;
	unsigned int	t;
	int				touchedr;
	int				touchedb;
	int				touchedg;
}				t_color;

typedef struct	s_player
{
	float		fov;
	t_vecteur	v;
	t_point		s;
	t_line		l;
	int			d;
}				t_player;

typedef struct	s_path
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
}				t_path;

typedef struct	s_object
{
	char	ref;
	t_point	p;
	float	d;
	int		side;
}				t_object;

typedef struct	s_all_tab
{
	t_line		*rayons;
	t_point		*touches;
	t_object	**touches_obj;
	float		*angles;
}				t_all_tab;

typedef struct	s_allp
{
	t_all_tab	tab;
	t_player	*hugo;
	int			save;
	int			i_obj;
	int			*hold;
	int			side;
	int			nb_path;
	int			nb_door;
	int			gun_state;
	void		*mini;
	void		*minik;
	char		**map;
	t_data		img_hp;
	int			nb_hp;
	int			*s_wall;
	t_data		img;
	int			col;
	t_data		hp;
	t_data		wall[4];
	t_data		s_door;
	t_data		gun[5];
	t_data		obj[10];
	t_point		door[10];
	int			door_state[10];
	int			res;
	int			resw;
	t_color		f;
	t_color		c;
	t_path		path;
	int			xmap;
	int			ymap;
	t_vecteur	v;
	t_point		s;
}				t_allp;

typedef struct	s_fobj_var
{
	t_line		l;
	t_vecteur	vision;
	int			nb_obj;
	t_point		rx;
	t_point		ry;
	t_allp		*all;
}				t_fobj_var;

typedef struct	s_cold_var
{
	int		height;
	int		i;
	int		diff;
	int		temp;
	float	x;
}				t_cold_var;

void			close_door_display(t_point wall,
				int col, float angle, t_allp *all);
void			door_col_display(t_point wall,
				int col, float angle, t_allp *all);
int				is_door(t_point wall, t_allp *all);
t_list			*before_get_map(int fd, t_list *temp);
int				is_door_bis(t_point wall, t_allp *all);
int				proc_mine(t_point newp, char **map);
void			fix(t_point *newp);
int				k_press(int keycode, t_allp *param);
void			exit_map(char **map, int i, t_allp *all);
void			test_mapname(char *s);
void			free_after_angles(int *tab);
int				check_info(t_allp *all);
void			free_path(t_allp *all);
void			free_after_touches_obj(t_all_tab *tab, int *s_wall);
void			free_while(int i, t_all_tab *tab, int *s_wall);
void			free_after_touches(int *s_wall, t_all_tab *tab);
void			free_img_b(t_allp *all);
void			free_after_rayons(int *s_wall, t_all_tab *tab);
int				lunch_display(t_allp *all);
void			add_res(int *res, char c);
void			exit_find_obj(t_allp *all);
float			colli_x(t_point p, char **map);
void			starting_point(char c, int i, int j, t_allp *all);
void			exit_check_info(t_allp *all, int fd);
int				is_bad_char(char c);
int				verif_door(int i, int j, t_allp *all, int p);
int				test_close(int x, int y, t_var_verif var, char **map);
void			test_spawn(t_var_verif *var, char **map, t_allp *all);
void			exit_get_info(t_allp *all);
t_list			*new_element(void);
t_list			*cp_list(t_list *list, char *line);
char			**list_to_map(t_list *l, int x, int y, t_allp *all);
char			**get_map(int fd, t_allp *all);
void			setup_var_verif(t_var_verif *var);
float			colli_y(t_point p, char **map);
t_point			collision(t_line l, t_point s, char **map);
void			free_land(t_allp *all);
void			setup_img(t_allp *all);
int				after_get_map(int fd);
t_point			w_key(t_player hugo, char **map, t_allp *all);
void			*ft_mlx_img(t_allp *all, char *path, int *width, int *height);
void			exit_load(t_allp *all);
t_point			s_key(t_player hugo, char **map, t_allp *all);
void			col_display(t_point wall, int col, float angle, t_allp *all);
int				find_side(t_point p, t_line l);
int				explosion(t_allp *all, int timer);
t_vecteur		la_key(t_player hugo);
int				rm_space(char *line, int i);
t_vecteur		ra_key(t_player hugo);
int				end(t_allp *all);
t_point			zero_b(t_line player, t_line obj);
t_point			zero_a(t_line player, t_line obj);
t_point			d_key(t_player hugo, char **map, t_allp *all);
void			shoot(t_allp *param);
t_point			a_key(t_player hugo, char **map, t_allp *all);
int				condition_spawn(char **map, int i, int j);
void			open_door(t_allp *all);
void			load_all(t_allp *all);
void			load_bonus(t_allp *all);
void			load_wall(t_allp *all);
int				in_conditions(t_allp *all, int x, int y, t_var_verif *var);
void			load_obj(t_allp *all);
int				get_next_line(int fd, char **line);
void			contour(char **map, int x, int y, t_allp *all);
int				ft_isdigit(int c);
void			contour_hp(int x, int y, t_allp *all);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				max(int a, int b);
void			exit_parse(t_allp *all);
char			*ft_strdup(const char *src);
void			bmp_setup(t_allp *all);
void			hp_bar(t_allp *param, int hp);
void			handle_gun(t_allp *all);
int				parsing(t_allp *all, char *file);
int				verif_map(int x, int y, char **map, t_allp *all);
void			wrong_file(int fd);
int				get_info(t_allp *all, int fd);
size_t			ft_strlenb(const char *s);
int				get_path_no(char*line, t_allp *all);
int				get_path_so(char*line, t_allp *all);
int				get_path_we(char*line, t_allp *all);
int				get_path_ea(char*line, t_allp *all);
int				get_path_s(char*line, t_allp *all);
int				color_f(char*line, t_allp *all);
int				color_c(char*line, t_allp *all);
void			wall_display(t_all_tab tab, t_allp *all, int width);
int				obj_roundy(t_object *res,
				t_fobj_var *var, t_point *p, char **map);
int				my_mlx_pixel_get(t_data *data, int x, int y);
void			free_path_exit(t_allp *all);
void			free_list(t_list *l);
void			obj_display_upper(t_all_tab tab, t_allp *all, int width);
void			malloc_land(t_all_tab *tab, int width, t_allp *all);
void			obj_display(t_object obj, int col, t_allp *all);
int				get_first_line(char *line, t_allp *all);
int				obj_roundx(t_object *res,
				t_fobj_var *var, t_point *p, char **map);
int				oob(t_point *p, t_object *res, t_fobj_var var);
t_fobj_var		set_fobj_var(t_line l, t_vecteur v, t_allp *all);
t_point			find_next_round(t_line l, t_point p);
int				ry_top(t_point *p, t_fobj_var *var, t_object *res, char **map);
int				rx_left(t_point *p, t_fobj_var *var, t_object *res, char **map);
int				ry_bottom(t_point *p, t_fobj_var *var,
				t_object *res, char **map);
int				rx_right(t_point *p, t_fobj_var *var,
				t_object *res, char **map);
t_point			proj_equation(t_line player, t_line obj);
void			final_display(t_allp *all);
void			calc_rayons_touches(t_player hugo, char **mapi, t_allp *all);
size_t			ft_strlcpyb(char *dst, const char *src, size_t dstsize);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			col_display(t_point wall, int coli, float angle, t_allp *all);
t_point			find_wall(t_line l, t_point p, char **map);
t_object		*find_obj(t_line l, t_point p, t_vecteur vision, t_allp *all);
t_point			x_or_y(t_point o, t_point rx, t_point ry);
t_point			next_round_x(t_line l, t_point p);
t_point			next_round_y(t_line l, t_point p);
char			**get_map(int fd, t_allp *all);
float			distance(t_point a, t_point b);
t_vecteur		vec_f_angle(t_vecteur oldv, float angle);
void			equation(t_point op, t_vecteur v, t_line *l);
#endif
