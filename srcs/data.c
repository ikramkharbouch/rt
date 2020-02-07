/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:35:37 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/07 19:03:29 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

void        fill_camera(t_camera *camera, t_block *block)
{
    t_block_list    *list;
    t_list          *camera;
    int             key;
    int             i;

    i = 0;
    while (i < block->n)
    {
        key = find_camera_key(list[i].key);
        if (key == EYE)
            camera->eye = char_to_vec(list[i].value);
        if (key == LOOK_AT)
            camera->look_at = char_to_vec(list[i].value);
        if (key == FOV)
            camera->fov = atof(list[i].value);
        if (key == DIST)
            camera->dist = atof(list[i].value);
        i++;
    }
}

int         fill_data(t_parser *p, t_env *env)
{
    t_block *block;
    t_scene *scene;
    int     block_index;
    int     i;

    scene = env->scene;
    block_index = 0;
    i = 0;
    while (i < p->n)
    {
        block = (&(p->blocks[i]));
        if (!(block_index = find_block(block)))
            return (0);
        if (block_index == CAMERA)
            fill_camera(&(scene->camera), block);
        if (block_index == LIGHT)
            fill_lights(scene->lights, block);
        if (block_index == SHAPE)
            fill_objects(scene->objects, block);
        i++;
    }
    return (1);
}

int         check_data(t_parser *p)
{
    if (!check(p))
        return (0);
    return (1);
}

t_parser    *get_data(char *filename)
{
    t_parser    *p;

    if (!(p = parse(filename)))
        return (0);
    return (p);
}
