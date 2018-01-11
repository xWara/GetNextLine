/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharrive <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:52:41 by tharrive          #+#    #+#             */
/*   Updated: 2018/01/10 14:53:29 by tharrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

int					check_errors(const int fd, char **line, char save)
{
	if (fd == 0 || line == NULL)
		return (-1);
	if (!save)
	{
		if (!(save = (char)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char		save;

	if (!check_errors(fd, line, save))
	{
		printf("pas bon \n");
		return (-1);
	}

	return (0);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		*line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	printf("all is ok");
	close(fd);
	return (0);
}
