/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:13:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 17:43:45 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

t_env       *env_setup(t_mlx *mlx)
{
    t_env       *env;

    env         = (t_env *)malloc(sizeof(t_env));
    env->mlx    = mlx;
    env->scene  = scene_setup();
    
    return (env);
}

t_scene     *scene_setup(void)
{
    t_scene     *scene;
    t_camera    camera;
    t_list      *lights;
    t_list      *objects;
    
    scene   = (t_scene *)malloc(sizeof(t_scene));
    lights  = (t_list *)malloc(sizeof(t_list));
    objects = (t_list *)malloc(sizeof(t_list));

    init_scene_values(&camera, &lights, &objects);
    scene->camera   = camera;
    scene->lights   = lights;
    scene->objects  = objects;

    return (scene);
}