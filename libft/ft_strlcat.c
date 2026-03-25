/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateremi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:32:00 by nateremi          #+#    #+#             */
/*   Updated: 2025/11/10 12:32:02 by nateremi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_len)
{
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (dst_len <= d_len)
		return (s_len + dst_len);
	i = d_len;
	j = 0;
	while (i < (dst_len - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}
