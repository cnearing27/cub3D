/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:01 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:02 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_new;
	unsigned char	*src_new;

	dest_new = (unsigned char *) dest;
	src_new = (unsigned char *) src;
	while (n > 0)
	{
		*dest_new = *src_new;
		if (*src_new == (unsigned char) c)
		{
			return (++dest);
		}
		dest_new++;
		src_new++;
		dest++;
		n--;
	}
	return (NULL);
}
