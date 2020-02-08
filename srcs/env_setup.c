/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:13:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/08 17:23:53 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

t_env       *env_setup(t_mlx *mlx, t_parser *p)
{
    t_env   *env;

    if (!(env = (t_env *)malloc(sizeof(t_env))))
        return (NULL);
    env->mlx    = mlx;
    env->scene  = scene_setup(p);
    return (env);
}

t_scene     *scene_setup(t_parser *p)
{
    t_scene     *scene;
    t_list      *lights;
    t_list      *objects;
    
    if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
        return (NULL);
    if (!(lights  = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    if (!(objects  = (t_list *)malloc(sizeof(t_list))))
        return (NULL);

    fill_data(p, scene);

    return (scene);
}