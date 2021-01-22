/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/22 17:11:11 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   eol_len();
**
**   If len == 0, the fonction will return the number of characters that
**   precede the '\n'.	If len == 1, the fonction will return the number
**   of characters that precede the '\0'
**
**   Return :
**      The number of characters
*/

size_t	eol_len(const char *s, int bool)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (!bool)
		while (s[i] && s[i] != '\n')
			i++;
	else
		while (s[i])
			i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = eol_len(s1, 1);
	len_s2 = eol_len(s2, 1);
	if (!(buff = malloc(sizeof(buff) * (len_s1 + len_s2 + 1))))
		return (NULL);
	buff[len_s1 + len_s2] = '\0';
	while (--len_s1)
		buff[len_s1] = s1[len_s1];
	while (--len_s2)
		buff[len_s2] = s2[len_s2];
	return (buff);
}
