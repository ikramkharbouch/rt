/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:13:39 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/05 19:27:18 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

t_env       *env_setup(t_mlx *mlx)
{
    
}

void        env_init(void)
{
    t_camera    camera;
    t_list      *lights;
    t_list      *objects;
    
    lights  = (t_list *)malloc(sizeof(t_list));
    objects = (t_list *)malloc(sizeof(t_list));

    init_scene_values(&camera, &lights, &objects);
}