/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:56 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:57 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	char	*s;

	s = (char *)str;
	while (*s)
		s++;
	if (n == 0)
		return (s);
	while (s != str)
	{
		if (*s == n)
			return (s);
		s--;
	}
	if (*s == n)
		return (s);
	return (NULL);
}
