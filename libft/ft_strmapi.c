/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nateremi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:41:29 by nateremi          #+#    #+#             */
/*   Updated: 2025/11/11 13:41:31 by nateremi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*new_s;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = f((unsigned int)i, s[i]);
		i++;
	}
	new_s[len] = '\0';
	return (new_s);
}
