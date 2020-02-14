#include "../includes/rtv1.h"

int		colormap(t_color *c)
{
	int color;

	color = c->r * pow(256, 2) + c->g * 256 + c->b;
	return (color);
}

t_color     *decimal_to_rgb(int color)
{
    t_color *c;

    c = (t_color *)malloc(sizeof(t_color));
    c->b = color % 256;
    color = color / 256;
    c->g = color % 256;
    color = color / 256;
    c->r = color % 256;
    return (c); 
}

int         color_mix(int color, float a)
{
    t_color *c;
    int     cl;

    c = decimal_to_rgb(color);
    c->r = c->r * a; 
    c->g = c->g * a; 
    c->b = c->b * a;
    cl = colormap(c);
    free(c);
    return (cl);
}
