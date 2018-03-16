/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharrive <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:37:21 by tharrive          #+#    #+#             */
/*   Updated: 2018/03/16 15:51:59 by tharrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef char		*t_string;

static int			reader(t_string *save, const int fd)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	t_string		tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = save[fd];
		save[fd] = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(save[fd], '\n') != NULL)
			return (ret);
	}
	return (ret);
}

static int			filling(const int fd, t_string *line, t_string save[fd])
{
	int				i;

	i = 0;
	while (save[fd][i] != '\n' && save[fd][i] != '\0')
		i++;
	*line = ft_strsub(save[fd], 0, i);
	ft_strcpy(save[fd], &save[fd][i + 1]);
	return (1);
}

int					get_next_line(const int fd, t_string *line)
{
	static t_tab	tab[256];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!tab[fd].save && (!(tab[fd].save = (char *)ft_strnew(1))))
		return (-1);
	if (reader(&(*save), fd) < 0)
		return (-1);
	if (save[fd]->save[0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (filling(fd, line, &(*save)) < 0)
		return (-1);
	return (1);
}
