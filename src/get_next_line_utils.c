/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/25 13:32:30 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#ifdef DEBUG
# include <stdio.h>
#endif

/*
**   eol_len();
**
**   If bool == 0, the fonction will return (1) if find character '\n'.
**   If bool == 1, the fonction will return the number of characters that
**     precede the '\n'.
**   If bool == 2, the fonction will return the number
**   of characters that precede the '\0'
**
**   Return size_t:
**      The number of characters
*/

size_t	eol_len(const char *s, int bool)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (bool == 0)
	{
		while (s[i])
		{
			if (s[i] == '\n')
			{
#ifdef DEBUG
printf(B_YEL " ╠  =eol_len= \'\\n\' find return " B_WHT "|1|\n╠" RESET);
#endif
				return (1);
			}
			i++;
		}
		return (0);
	}
	if (bool == 1)
	{
		while (s[i])
		{
			if (s[i] == '\n')
			{
#ifdef DEBUG
printf(B_YEL " ╠  =eol_len= \'\\n\' find return " B_WHT "|%lu|\n╠" RESET, i);
#endif
				return (i);
			}
			i++;
		}
		return (0);
	}
	if (bool == 2)
		while (s[i])
			i++;
#ifdef DEBUG
printf(B_YEL " ╠  =eol_len= len return = " B_WHT "|%lu|\n╠" RESET, i);
#endif
	return (i);
}

/*
**   ft_strjoin();
**   
**   
*/

//TODO utilisation de la fonction avec un tmp vide
char	*ft_strjoin(char *s1, const char *s2)
{
	char	*buff;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s2)
		return (NULL);
	i = 0;
	len_s1 = 0;
	if (s1)
		len_s1 = eol_len(s1, 2);
	len_s2 = eol_len(s2, 2);
	i = len_s1 + len_s2;
#ifdef DEBUG
printf(B_YEL "\n╠  ╔  =strjoin= len_s1 = " B_WHT "|%lu|\n" RESET, len_s1);
printf(B_YEL "╠  ╠  =strjoin= len_s2 = " B_WHT "|%lu|\n" RESET, len_s2);
#endif
	if (!(buff = malloc(sizeof(buff) * (len_s1 + len_s2 + 1))))
		return (NULL);
	buff[len_s1 + len_s2] = '\0';
	while (len_s2-- > 0)
		buff[--i] = s2[len_s2];
	if (s1)
		while (len_s1-- > 0)
			buff[--i] = s1[len_s1];
#ifdef DEBUG
printf(B_YEL "╠  ╚  =strjoin= buff return = " B_WHT "|%s|\n╠" RESET, buff);
#endif
	free(s1);
	return (buff);
}

/*
**
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	char	*s1;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)s;
	if (!(buff = malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	buff[len] = '\0';
	if (start >= eol_len(s, 2))
		return (buff);
	while (start--)
		s1++;
	while (i < len)
	{
		buff[i++] = *s1++;
	}
	return (buff);
}