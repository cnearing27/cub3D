/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:31 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:32 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	char	*s;

	s = (char *)str;
	while (*s)
	{
		if (*s == n)
			return (s);
		s++;
	}
	if (n == 0)
		return (s);
	return (NULL);
}
