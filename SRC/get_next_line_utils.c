/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/03 09:39:08 by mhadad           ###   ########.fr       */
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
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	char	*s1;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	if (!(buff = malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	ft_bzero(buff, len + 1);
	if (start >= EOL_len(s, 1))
		return (buff);
	while (start--)
		s1++;
	while (len--)
		buff[len] = s1[len];
	return (buff);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char *str;

	if (!(str = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(str, (size * nmemb));
	return (str);
}