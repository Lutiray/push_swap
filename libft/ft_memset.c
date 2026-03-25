/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateremi <entalia663@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:11:43 by nateremi          #+#    #+#             */
/*   Updated: 2025/11/10 12:31:19 by nateremi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int num, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (len > 0)
	{
		*p = (unsigned char)num;
		p++;
		len--;
	}
	return (str);
}
