/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharrive <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:59:25 by tharrive          #+#    #+#             */
/*   Updated: 2018/03/08 08:38:58 by tharrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (ft_strlen((char *)s1) +
						ft_strlen((char *)s2) + 1));
	ft_bzero(str, sizeof(char) * (ft_strlen((char *)s1) +
						ft_strlen((char *)s2) + 1));
	if (str)
	{
		if (s1)
			str = ft_strcpy(str, s1);
		if (s2)
			str = ft_strcat(str, s2);
	}
	return (str);
}
