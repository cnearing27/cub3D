/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:10 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:11 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_new;
	unsigned char	*src_new;

	dest_new = (unsigned char *)dest;
	src_new = (unsigned char *)src;
	if (!dest_new && !src_new)
		return (NULL);
	if (dest > src)
		while (n--)
			*(dest_new + n) = *(src_new + n);
	else
		while (n--)
			*dest_new++ = *src_new++;
	return (dest);
}
