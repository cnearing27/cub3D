/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:50 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:51 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_new;
	unsigned char	*s2_new;

	s1_new = (unsigned char *)s1;
	s2_new = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_new[i] == s2_new[i] && i < n && (s1_new[i] || s2_new[i]))
	{
		if (s1_new[i] != s2_new[i])
			return (s1_new[i] - s2_new[i]);
		i++;
	}
	if (i != n)
		return (s1_new[i] - s2_new[i]);
	return (0);
}
