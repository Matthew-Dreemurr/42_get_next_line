/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/12 09:18:55 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *s1;

	s1 = s;
	if (n)
		while (n--)
			s1[n] = 0;
}

//TODO need to proterc NULL string
size_t	EOL_len(const char *s, int len)
{
	size_t	i;

	i = 0;
	if(!len)
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	else
	{
		while (s[i])
			i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	if (!dst)
		return (0);
	i = 0;
	count = ft_strlen(src);
	if (!dstsize)
		return (count);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char *str;

	if (!(str = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(str, (size * nmemb));
	return (str);
}