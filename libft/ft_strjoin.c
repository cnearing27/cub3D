/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:36 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:37 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s, const char *d)
{
	int		i;
	char	*dst;

	i = 0;
	if (!s || !d)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(d) + 1));
	if (!dst)
		return (NULL);
	while (*s)
		dst[i++] = *s++;
	while (*d)
		dst[i++] = *d++;
	dst[i] = '\0';
	return (dst);
}
