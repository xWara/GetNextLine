/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharrive <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:52:41 by tharrive          #+#    #+#             */
/*   Updated: 2018/02/01 15:56:21 by tharrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int					check_errors(char **line, char **save)
{
	if (line == NULL)
		return (-1);
	if (!*save)
	{
		if (!(*save = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
		*save[0] = '\0';
	}
	return (1);
}

char				*reader(char *save, int fd)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		save = ft_strjoin(save, buff);
	}
	return (save);
}

int					get_next_line(const int fd, char **line)
{
	static char		*save;
	int				i;

	if (!check_errors(line, &save))
		return (-1);
	if (*save)
		ft_strcpy(*line, save);
	save = reader(save, fd);
	i = 0;
	if (save[i])
	{
		while (save[i] != '\n' && save)
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			(*line) = ft_strsub(save, 0, i);
			save = &save[i + 1];
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}

int					main(int argc, char **argv)
{
	int				fd;
	char			*line;

	if (argc != 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		ft_putendl(line);
	close(fd);
	return (0);
}
