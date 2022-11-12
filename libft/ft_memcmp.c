/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:07 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:08 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *d, size_t n)
{
	unsigned char	*s_new;
	unsigned char	*d_new;

	s_new = (unsigned char *)s;
	d_new = (unsigned char *)d;
	while (n && (*s_new == *d_new))
	{
		s_new++;
		d_new++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s_new - *d_new);
}
