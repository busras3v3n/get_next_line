/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:03:17 by busseven          #+#    #+#             */
/*   Updated: 2024/11/25 14:43:55 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;
	size_t	i;

	i = 0;
	r = malloc(count * size);
	if (!r)
		return (NULL);
	if (size * count != 0)
	{
		while (i < size * count)
		{
			*(unsigned char *)(r + i) = 0;
			i++;
		}
	}
	return (r);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*joined;
	size_t		j;
	size_t		i;

	joined = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))) + 1);
	if (!joined)
		return (NULL);
	j = 0;
	i = 0;
	while (j < ft_strlen(s1))
	{
		joined[j] = s1[j];
		j++;
	}
	while (i < ft_strlen(s2))
	{
		joined[j] = s2[i];
		i++;
		j++;
	}
	joined[j] = '\0';
	return (joined);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = start;
	j = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (len == 0 || i >= ft_strlen(s))
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	str = malloc((len * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (i < start + len && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		i;

	cpy = malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
