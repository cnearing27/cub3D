/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:37:28 by cnearing          #+#    #+#             */
/*   Updated: 2022/11/01 18:37:29 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **str, size_t size)
{
	while (size > 0)
	{
		free(str[size]);
		size--;
	}
	free(str);
}

static void	ft_creatstr(char **str, const char *s, char c, size_t count)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str[count] = NULL;
	while (i < count)
	{
		while (s[j] && s[j] == c)
			j++;
		len = 0;
		while (s[j + len] && s[j + len] != c)
			len++;
		str[i] = ft_substr(s, j, len);
		if (!str[i])
		{
			ft_free(str, count);
			break ;
		}
		j = j + len;
		i++;
	}
}

static size_t	ft_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			i = 0;
		else if (i == 0)
		{
			i = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	size_t	count;
	char	**str;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	ft_creatstr(str, s, c, count);
	return (str);
}
