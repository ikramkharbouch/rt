/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:20:04 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/12/04 23:17:35 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_found(char **line, char *buff, char *pos)
{
	char	*new;
	char	*sub_str;

	if (!(sub_str = ft_strsub(buff, 0, pos - buff)))
		return (-1);
	if (!(new = ft_strjoin(*line, sub_str)))
	{
		ft_strdel(&sub_str);
		return (-1);
	}
	ft_strdel(line);
	ft_strdel(&sub_str);
	*line = new;
	ft_strcpy(buff, pos + 1);
	return (1);
}

int		ft_not_found(char **line, char *buff)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*line, buff)))
		return (-1);
	ft_strdel(line);
	*line = tmp;
	ft_bzero(buff, BUFF_SIZE + 1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	int			size;
	char		*pos;

	if (fd < 0 || read(fd, NULL, 0) == -1 || !(*line = ft_strnew(0)))
		return (-1);
	if (*buff)
	{
		if ((pos = ft_strchr(buff, '\n')))
			return (ft_is_found(line, buff, pos));
		else if (ft_not_found(line, buff) == -1)
			return (-1);
	}
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		if ((pos = ft_strchr(buff, '\n')))
			return (ft_is_found(line, buff, pos));
		else if (!ft_not_found(line, buff))
			return (-1);
	}
	if (**line)
		return (1);
	ft_strdel(line);
	return (size);
}
