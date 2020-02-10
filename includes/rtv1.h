/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:53:32 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/10 19:56:54 by ikrkharb         ###   ########.fr       */
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
# include "../parser/parser.h"

# define HEIGHT 	800
# define WIDTH  	800
# define FALSE		-1
# define CAMERA		6
# define LIGHT		7
# define SHAPE		8
# define EYE		9
# define LOOK_AT	10
# define FOV		11
# define DIST		12
# define ORIGIN		13
# define INTENSITY	14
# define NAME		15
# define CENTER		16
# define RADIUS		17
# define KS			18
# define KD			19
# define N			20
# define COLOR		21

# define FALSE  1e+30
# define DEG_TO_RAD(X) (X * (M_PI / 180.0));

typedef struct      s_mlx
{
	void            *mlx_ptr;
	void            *win_ptr;
	void            *img_ptr;
	char            *img_data;
	int             bits_per_pixel;
	int             size_line;
	int             endian;
	int             x;
	int             y;
}                   t_mlx;

typedef struct      s_point
{
	float x;
	float y;
	float z;
}                   t_point;

typedef t_point t_vec;

typedef struct      s_camera
{
	t_point         eye;
	t_point         look_at;
	t_vec           up;
	t_vec           u;
	t_vec           v;
	t_vec           view_dir;
	t_vec           bottom_left;
	t_vec           x_incv;
	t_vec           y_incv;
	float           aspect_ratio;
	float           fov;
	float           h_width;
	float           h_height;
	float           dist;
}                   t_camera;

typedef struct      s_ray
{
    t_point         origin;
    t_vec           dir;
}                   t_ray;

typedef struct      s_object
{
    t_vec           center;
    t_vec           vec_dir;
    char            *name;
    float 	        radius;
	float	        alpha;
	float 	        ks;
	float 	        kd;
	float 	        n;
	float	        t;
    int             color;
	t_equation		eq;
}                   t_object;

typedef	struct 		s_equation
{
	float			a;
	float			b;
	float			c;
	float			discr;
	float			t1;
	float			t2;
	float			min_t;
}					t_equation;


typedef struct      s_light
{
    t_vec           dir;
    t_point         origin;
    float           intensity;
}					t_light;

typedef struct      s_color
{
    unsigned char   r;
    unsigned char   g;
    unsigned char   b;
}                   t_color;

typedef struct      s_scene
{
    t_camera        camera;
    t_list			*lights;
    t_list			*objects;
	struct s_scene	*next;
}                   t_scene;

typedef struct		s_env
{
	t_mlx			*mlx;
	t_scene			*scene;
	struct s_env	*next;
}					t_env;

t_env	*g_env;

/*
** Manage the project and verify all errors;
*/

int     	manage_rtv1(char *filename, t_mlx *mlx);
void        debug_obj(void);
void        debug_light(void);

/*
**	MLX SETUP && MLX HOOKS.
*/

void    	mlx_setup(t_mlx *mlx);
void 		ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int 		mouse_press(int button, int x, int y, void *param);
int 		key_press(int keycode, void *param);
int 		close_win(void *param);

/*
** Initialization of structs values and setup.
*/

t_env       *env_setup(t_mlx *mlx, t_parser *p);
t_scene     *scene_setup(t_parser *p);
void    	init_mlx_values(t_mlx *mlx);
void    	init_scene_values(t_camera *camera, t_light *light, t_object *object);


/*
** Free allocated memory.
*/

void        free_env(t_env *env);

/*
** Data manipulation.
*/

t_parser    *get_data(char *filename);
t_scene     *fill_data(t_parser *p, t_scene *scene);
int         check_data(t_parser *p);
int			check(t_parser *p);
int			check_cam_keys(t_block_list *list);
int			check_light_keys(t_block_list *list);
int			check_shape_keys(t_block_list *list);

/*
** Utils.
*/

int     	find_block(t_block *block);
int     	find_camera_key(char *key);
int     	find_light_key(char *key);
int     	find_object_key(char *key);
t_vec		char_to_vec(char *str);

/*
** Ray generating.
*/

t_ray       ray_gen(int i, int j);

/*
** Maths operations on vectors.
*/

float 		vec_dot(t_vec v1, t_vec v2);
t_vec 		vec_sub(t_vec v1, t_vec v2);
t_vec 		vec_sum(t_vec v1, t_vec v2);
t_vec 		vec_scale(t_vec v1, t_vec v2);
t_vec 		vec_kscale(float k, t_vec v2);
t_vec 		vec_cross(t_vec v1, t_vec v2);
t_vec 		vec_normalize(t_vec v);

/*
** Intersections between ray and objects.
*/

float       intersect_ray_sphere(t_ray *ray, t_object *object);
float       intersect_ray_plane(void);
float       intersect_ray_cylinder(void);
float       intersect_ray_cone(void);

#endif