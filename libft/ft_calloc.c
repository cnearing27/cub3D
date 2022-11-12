/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:32:58 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:32:59 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*dst;

	dst = (char *)malloc(n * size);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, (n * size));
	return (dst);
}
