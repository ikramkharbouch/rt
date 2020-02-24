/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:17:06 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/24 10:29:26 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../parser-yaml/parser.h"

# define HEIGHT			800
# define WIDTH			800
# define NEAR			1e-6
# define FAR			1000000
# define MIN_D			1e-5

# define CAMERA			6
# define LIGHT			7
# define SHAPE			8
# define EYE			9
# define LOOK_AT		10
# define FOV			11
# define DIST			12
# define ORIGIN			13
# define INTENSITY		14
# define NAME			15
# define CENTER			16
# define RADIUS			17
# define LIGHT_COEFFS	18
# define COLOR			21
# define SPHERE			22
# define PLANE			23
# define CYLINDER		24
# define CONE			25
# define ROT			26
# define TRANS			27
# define ALPHA			28
# define VEC_DIR		29

# define DEG_TO_RAD(X) (X * (M_PI / 180.0));

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

typedef struct s_vector	t_point;

typedef struct		s_camera
{
	t_point			eye;
	t_point			look_at;
	t_vector		up;
	t_vector		u;
	t_vector		v;
	t_vector		view_dir;
	t_vector		bottom_left;
	t_vector		x_incv;
	t_vector		y_incv;
	float			aspect_ratio;
	float			fov;
	float			h_width;
	float			h_height;
	float			dist;
}					t_camera;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				s_l;
	int				en;
	int				x;
	int				y;
}					t_mlx;

typedef	struct		s_rot
{
	int				on;
	int				alpha_x;
	int				alpha_y;
	int				alpha_z;
}					t_rot;

typedef	struct		s_trans
{
	int				on;
	t_vector		vec;
}					t_trans;

typedef struct		s_light_coeffs
{
	float			ks;
	float			kd;
	float			n;
}					t_light_coeffs;

typedef struct		s_object
{
	char			*name;
	int				color;
	t_vector		center;
	t_vector		vec_dir;
	float			radius;
	float			alpha;
	t_light_coeffs	coeffs;
	double			t;
	double			tsh;
	t_rot			rot;
	t_trans			trans;
	float			k;
}					t_object;

typedef struct		s_light
{
	t_point			origin;
	t_vector		dir;
	float			intensity;
	struct s_light	*next;
}					t_light;

typedef struct		s_ray
{
	t_point			origin;
	t_vector		dir;
}					t_ray;

typedef	struct		s_scene
{
	t_camera		camera;
	t_light			light;
	t_object		obj_type;
}					t_scene;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	b;
	unsigned char	g;
}					t_color;

typedef struct		s_env
{
	t_mlx			mlx;
	t_scene			scene;
}					t_env;

t_env g_env;

/*
** MLX SETUP
*/

void				ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int					mouse_press(int button, int x, int y, void *param);
int					key_press(int keycode, void *param);
int					close_win(void *param);
void				ft_draw(t_mlx *mlx);
void				set_mlx_hooks(t_mlx *mlx);
void				ft_mlx_setup(t_mlx *mlx);

/*
** Vectors operations
*/

float				vec_dot(t_vector v1, t_vector v2);
float				vec_dot_x_z(t_vector v1, t_vector v2);
t_vector			vec_sub(t_vector v1, t_vector v2);
t_vector			vec_sum(t_vector v1, t_vector v2);
t_vector			vec_scale(t_vector v1, t_vector v2);
t_vector			vec_kscale(float k, t_vector v2);
t_vector			vec_cross(t_vector v1, t_vector v2);
t_vector			vec_normalize(t_vector v);

/*
** For debugging purposes (To delete later)
*/

void				print_obj_props(t_block *block);
void				print_light_props(t_light *light);
void				read_object_values(int fd, t_block *block);
void				read_light_values(int fd, t_light *light);
void				print_cam_props(t_camera *camera);
void				print_cam_props(t_camera *camera);
void				print_light_props(t_light *light);
void				print_list_objects(t_list *list);
void				print_list_objects(t_list *list);
void				print_list_lights(t_list *list);
void				debug_camera(t_list *camera);
void				debug_rot(t_rot *rot);
void				debug_trans(t_trans *trans);

/*
** Init env blocks
*/

void				init_cam(t_camera *camera);
void				init_light(t_light *light);
void				init_obj(t_object *obj);
void				init_rot(t_rot *rot);
void				init_trans(t_trans *trans);

/*
** Data manipulation
*/

int					get_data(char *filename, t_mlx *mlx);
t_list				*fill_object_data(t_block *block);
t_camera			fill_camera_data(t_block *block);
t_list				*fill_light_data(t_block *block);
int					fill(t_parser *p, t_mlx *mlx);

/*
** Camera and ray generating
*/

t_camera			ft_create_cam(t_vector eye, t_vector look_at, float fov);
t_ray				generate_ray(t_camera *camera, int i, int j);
void				ft_draw_objects(t_mlx *mlx, t_camera camera,
									t_list *objects);
void				create_actual_objs(t_mlx *mlx, t_camera camera,
									t_list *lights, t_list *objects);

/*
** Object's intersections
*/

t_object			*find_inter(t_camera camera, t_list *objects, int i, int j);
double				sphere(t_ray *ray, t_object *obj);
double				plane(t_ray *ray, t_object *obj);
double				cone(t_ray *ray, t_object *obj);
double				cylinder(t_ray *ray, t_object *obj);

/*
** Shading and phong model coloring
*/

int					color_mix(int color, float d, float s);
int					phong_model(t_object *obj, t_ray *ray,
								t_list *lights, float k);
t_vector			get_normal(t_object *obj, t_ray *ray);
int					get_percent(int color, float p);

/*
** Utils
*/

int					find_block(t_block *block);
int					find_camera_key(char *key);
int					find_light_key(char *key);
int					find_object_key(char *key);
int					find_object_name(char *name);
t_vector			char_to_vec(char *str);
t_rot				char_to_rot(char *str);
t_trans				char_to_trans(char *str);
t_light_coeffs		char_to_coeffs(char *str);

/*
** The checker functions
*/

int					check_cam_keys(t_block_list *list);
int					check_light_keys(t_block_list *list);
int					sphere_keys(t_block_list *sphere, int size);
int					cylinder_keys(t_block_list *cylinder, int size);
int					plane_keys(t_block_list *plane, int size);
int					cone_keys(t_block_list *cone, int size);
int					check_shape_keys(t_block_list *list, int size);
int					check(t_parser *p);
int					check_empty_parser(t_parser	*p);
int					len(t_block_list *list);
int					check_vec_input(char *vec);
int					check_transform_input(char *vec);
int					check_univalue(char *vec);
int					sphere_input(t_block_list *sphere, int size);
int					cylinder_input(t_block_list *cylinder, int size);
int					plane_input(t_block_list *plane, int size);
int					cone_input(t_block_list *cone, int size);

/*
** Transformation of objects
*/

void				rotate(t_list **objects);
void				translate(t_list *objects);
t_vector			rotate_x_axis(t_vector vec_dir, float angle);
t_vector			rotate_y_axis(t_vector vec_dir, float angle);
t_vector			rotate_z_axis(t_vector vec_dir, float angle);

#endif
