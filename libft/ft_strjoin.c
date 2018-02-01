/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharrive <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:59:25 by tharrive          #+#    #+#             */
/*   Updated: 2018/02/01 15:55:52 by tharrive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (ft_strlen((char *)s1) +
						ft_strlen((char *)s2) + 1));
	if (str)
	{
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
	}
	return (str);
}
