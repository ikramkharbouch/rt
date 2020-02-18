/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:41:24 by ikrkharb          #+#    #+#             */
/*   Updated: 2020/02/18 19:50:16 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void 		debug_cam_setup(t_camera *camera)
{
	printf("VIEW_DIR: x = %f | y = %f| z = %f\n", camera->view_dir.x, camera->view_dir.y, camera->view_dir.z);
	printf("U: x = %f | y = %f| z = %f\n", camera->u.x, camera->u.y, camera->u.z);
	printf("V: x = %f | y = %f| z = %f\n", camera->v.x, camera->v.y, camera->v.z);

	printf("H_HEIGHT: %f\n", camera->h_height);
	printf("H_WIDTH: %f\n", camera->h_width);
}

void 		print_cam_props(t_camera *camera)
{
	float x_eye;
	float y_eye;
	float z_eye;
	float x_look_at;
	float y_look_at;
	float z_look_at;
	float fov;
	float dist;

	x_eye = camera->eye.x;
	y_eye = camera->eye.y;
	z_eye = camera->eye.z;

	x_look_at = camera->look_at.x;
	y_look_at = camera->look_at.y;
	z_look_at = camera->look_at.z;

	fov = camera->fov;
	dist = camera->dist;

	printf("|x_eye = %f|\n|y_eye = %f|\n|z_eye = %f|\n", x_eye, y_eye, z_eye);
	printf("|x_look_at = %f|\n|y_look_at = %f|\n|z_look_at = %f|\n", x_look_at, y_look_at, z_look_at);
	printf("|fov = %f|\n|dist = %f|\n", fov, dist);
}

void print_light_props(t_light *light)
{
	float x;
	float y;
	float z;
	float radius;

	x = light->origin.x;
	y = light->origin.y;
	z = light->origin.z;
	radius = light->intensity;

	printf("|x = %f|\n|y = %f|\n|z = %f|\n|intensity = %f|\n", x, y, z, radius);
}

void debug_camera(t_list *camera)
{
	t_camera *cam;

	cam = camera->content;
	printf("\teye->x == %f, eye->y == %f, eye->z == %f\n", cam->eye.x, cam->eye.y, cam->eye.z);
	printf("\t\tlook_at->x == %f, look_at->y == %f, look_at->z == %f\n", cam->look_at.x, cam->look_at.y, cam->look_at.z);
	printf("\t\t\tfov == %f\n", cam->fov);
}

void debug_light(t_list *lights)
{
	t_light *light;

	light = lights->content;
	while (lights)
	{
		printf("origin->x == %f, origin->y == %f, origin->z == %f\n", light->origin.x, light->origin.y, light->origin.z);
		printf("dir->x == %f, dir->y == %f, dir->z == %f\n", light->dir.x, light->dir.y, light->origin.z);
		printf("%f\n", light->intensity);
		lights = lights->next;
	}
}

void	debug_obj(t_list *objects)
{
	t_object	*obj;
	
	while(objects)
	{
		obj = objects->content;
		printf("object_name == %s\n", obj->name);
		printf("\t\tcenter->x == %f, center->y == %f, origin->z == %f\n", obj->center.x, obj->center.y, obj->center.z);
		printf("\t\tradius == %f\n", obj->radius);
		printf("\t\tks == %f\n", obj->ks);
		printf("\t\tkd == %f\n", obj->kd);
		printf("\t\tn == %f\n", obj->n);
		objects = objects->next;
	}
}

void	debug_rot(t_rot *rot)
{
	printf("%d\n", rot->on);
	printf("%d %d %d\n", rot->alpha_x, rot->alpha_y, rot->alpha_z);
}

void	debug_trans(t_trans *trans)
{
	printf("%d\n", trans->on);
	printf("%f %f %f\n", trans->vec.x, trans->vec.y, trans->vec.z);
}

void print_list_lights(t_list *list)
{
	t_light *light;

	light = NULL;
	while (list)
	{
		light = list->content;
		printf("light->origin : \t%f\t%f\t%f\n", light->origin.x, light->origin.y, light->origin.z);
		printf("light->intensity: \t%f\n", light->intensity);
		list = list->next;
	}
}

void print_list_objects(t_list *list)
{
	t_object *object;

	object = NULL;
	while (list)
	{
		object = list->content;
		printf("object->name: %s\n", object->name);
		printf("\tobject->center: %f %f %f\n", object->center.x, object->center.y, object->center.z);
		printf("\tobject->vec_dir: %f %f %f\n", object->vec_dir.x, object->vec_dir.y, object->vec_dir.z);
		printf("\tobject->alpha: %f\n", object->alpha);
		printf("\tobject->n: %f\n", object->n);
		printf("\tobject->ks: %f\n", object->ks);
		printf("\tobject->kd: %f\n", object->kd);
		printf("\tobject->color: %d\n", object->color);
		list = list->next;
	}
}