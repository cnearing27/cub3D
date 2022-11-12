/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:59 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:38:00 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	char	*d;
	size_t	i;

	d = NULL;
	if (s && set)
	{
		while (*s && ft_strchr(set, *s))
			s++;
		i = ft_strlen(s);
		while (i && ft_strchr(set, s[i]))
			i--;
		d = ft_substr(s, 0, i + 1);
	}
	return (d);
}
