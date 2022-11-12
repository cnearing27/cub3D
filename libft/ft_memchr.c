/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:04 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:05 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_new;

	str_new = (unsigned char *)str;
	while (n--)
	{
		if (*str_new == (unsigned char)c)
			return (str_new);
		str_new++;
	}
	return (NULL);
}
