/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharrive <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:52:34 by tharrive          #+#    #+#             */
/*   Updated: 2018/02/22 13:46:52 by tharrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif
