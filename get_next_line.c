/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharrive <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 13:37:21 by tharrive          #+#    #+#             */
/*   Updated: 2018/02/22 14:21:45 by tharrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

typedef char		*t_string;

static int			reader(t_string *save, const int fd)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	t_string		tmp;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = *save;
		*save = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(*save, '\n') != NULL)
			return (ret);
	}
	return (ret);
}

static int			filling(t_string *line, t_string *save)
{
	t_string		tmp;
	int				i;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	*line = ft_strsub(*save, 0, i);
	if (!(tmp = (t_string)malloc(sizeof(tmp) * (ft_strlen(*save) + 1))))
		return (-1);
	tmp = ft_strcpy(tmp, &(*save)[i + 1]);
	ft_strclr(*save);
	*save = ft_strcpy(*save, tmp);
	free(tmp);
	return (1);
}

int					get_next_line(const int fd, t_string *line)
{
	static t_string	save;

	if (fd < 0 || line == NULL || fd > 256 || BUFF_SIZE <= 0)
		return (-1);
	if (!save && (!(save = (char *)malloc(sizeof(save) * 2))))
		return (-1);
	if (reader(&save, fd) < 0)
		return (-1);
	if (save[0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (filling(line, &save) < 0)
		return (-1);
	return (1);
}
