/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:13:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/09 00:48:08 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

t_env       *env_setup(t_mlx *mlx, t_parser *p)
{
    if (!(g_env = (t_env *)malloc(sizeof(t_env))))
        return (NULL);
    g_env->mlx    = mlx;
    g_env->scene  = scene_setup(p);
    g_env->next = NULL;
    return (g_env);
}

t_scene     *scene_setup(t_parser *p)
{
    t_scene     *scene;
    
    if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);

    
    scene->next = NULL;
    scene->lights = NULL;
    scene->objects = NULL;
    
    fill_data(p, scene);
    

    return (scene);
}