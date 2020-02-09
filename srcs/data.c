/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:35:37 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/08 21:12:48 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/rtv1.h"

t_camera    *fill_camera(t_camera *camera, t_block *block)
{
    t_block_list    *list;
    int             key;
    int             i;

    list = block->list;
    key = 0;
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
    return (camera);
}

t_list    *fill_lights(t_block *block)
{
    t_block_list    *list;
    t_light         light;
    int             key;
    int             i;

    list = block->list;
    key = 0;
    i = 0;
    while (i < block->n)
    {
        key = find_light_key(list[i].key);
        if (key == ORIGIN)
            light.origin = char_to_vec(list[i].value);
        if (key == INTENSITY)
            light.intensity = atof(list[i].value);
        i++;
    }
    // ft_lstadd(&lights, ft_lstnew(&light, sizeof(t_light)));
    // return (lights);
    return (ft_lstnew(&light, sizeof(t_light)));
}

t_list      *fill_objects(t_block *block)
{
    t_block_list    *list;
    t_object        object;
    int             key;
    int             i;

    list = block->list;
    key = 0;
    i = 0;
    while (i < block->n)
    {
        key = find_object_key(list[i].key);
        if (key == NAME)
            object.name = list[i].value;
        if (key == CENTER)
            object.center = char_to_vec(list[i].value);
        if (key == RADIUS)
            object.radius = atof(list[i].value);
        if (key == KS)
            object.ks = atof(list[i].value);
        if (key == KD)
            object.kd = atof(list[i].value);
        if (key == N)
            object.n = atof(list[i].value);
        if (key == COLOR)
            object.color = atoi(list[i].value);
        i++;
    }
    // ft_lstadd(&objects, ft_lstnew(&object, sizeof(t_object)));
    // return (objects);
    return (ft_lstnew(&object, sizeof(t_object)));
}

int         fetch_blocks(t_block *block, t_scene *scene)
{
    int     block_index;

    block_index = 0;
    if (!(block_index = find_block(block)))
            return (0);
    if (block_index == CAMERA)
        scene->camera = *(fill_camera(&(scene->camera), block));
    if (block_index == LIGHT)
        ft_lstadd(&(scene->lights), fill_lights(block));
    if (block_index == SHAPE)
        ft_lstadd(&(scene->objects), fill_objects(block));
    return (1);
}

t_scene     *fill_data(t_parser *p, t_scene *scene)
{
    t_block *block;
    int     block_index;
    int     i;

    block_index = 0;
    i = 0;
    while (i < p->n)
    {
        block = &(p->blocks[i]);
        fetch_blocks(block, scene);
        i++;
    }
    return (scene);
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
    // pretty_parser(p);
    return (p);
}
