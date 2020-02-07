/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:53:32 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 17:46:20 by ikrkharb         ###   ########.fr       */
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

# define HEIGHT 800
# define WIDTH  800
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
}                   t_object;

typedef struct      s_light
{
    t_vec           dir;
    t_point         origin;
    float           intensity;
    struct s_light  *next;
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
    t_light         *lights;
    t_object		*objects;
}                   t_scene;

typedef struct		s_env
{
	t_mlx			*mlx;
	t_scene			*scene;
}					t_env;

/*
**	MLX SETUP && MLX HOOKS.
*/

void    mlx_setup(t_mlx *mlx);
void 	ft_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int 	mouse_press(int button, int x, int y, void *param);
int 	key_press(int keycode, void *param);
int 	close_win(void *param);

/*
** Initialization of structs values and setup.
*/

t_env       *env_setup(t_mlx *mlx);
t_scene     *scene_setup(void);
void    	init_mlx_values(t_mlx *mlx);
void    	init_scene_values(t_camera *camera, t_list *lights, t_list *objects);

t_env g_env;

/*
** Free allocated memory.
*/

void        free_env(t_env *env);

/*
** Data manipulation.
*/

int     get_data(char *filename, t_env *env);
void    fill_structs(t_parser *p, t_env *env);

#endif