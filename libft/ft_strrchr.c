/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateremi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:33:18 by nateremi          #+#    #+#             */
/*   Updated: 2025/11/10 12:33:22 by nateremi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	str_len;

	str_len = ft_strlen(str);
	while (str_len >= 0)
	{
		if (str[str_len] == (char)c)
			return ((char *)(str + str_len));
		str_len--;
	}
	return (NULL);
}
