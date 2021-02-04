/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/01/25 18:11:10 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#ifdef DEBUG
# include <stdio.h>
#endif

/*
**   eol_len();
**
** DESCRIPTION
**   If set == 1, the fonction will return (1) if find character '\n' else (0).
**   If set == 2, the fonction will return the number of characters that
**     precede the '\n'.
**   If set == 3, the fonction will return the number
**     of characters that precede the '\0'.
**
**   RETURN
**      The number of characters.
*/

size_t	eol_len(const char *s, int set)
{
	ssize_t	i;

	i = -1;
	if (!s)
		return (0);
	if (set == 1)
	{
		while (s[++i])
			if (s[i] == '\n')
				return (1);
		return (0);
	}
	if (set == 2)
	{
		while (s[++i])
			if (s[i] == '\n')
				return (i);
		return (0);
	}
	if (set == 3)
		while (s[++i])
			;
	return (i);
}

/*
**   ft_strjoin();
**
** DESCRIPTION
**   Allocates and returns a new string,
**     which is the result of the concatenation of `s1` and `s2`.
**
** PARAMETERS
**   @param `s1`   The prefix string.
**   @param `s2`   The suffix string.
**
** RETURN
**   The new string. NULL if the allocation fails.
*/

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
		len_s1 = eol_len(s1, 3);
	len_s2 = eol_len(s2, 3);
	i = len_s1 + len_s2;
	if (!(buff = malloc(sizeof(buff) * (len_s1 + len_s2 + 1))))
		return (NULL);
	ft_bzero(buff, (sizeof(buff) * (len_s1 + len_s2 + 1)));
	while (len_s2-- > 0)
		buff[--i] = s2[len_s2];
	if (s1)
		while (len_s1-- > 0)
			buff[--i] = s1[len_s1];
	free(s1);
	return (buff);
}

/*
**   ft_substr();
**
** DESCRIPTION
**   Allocates and returns a substring from the string `s`.
**   The substring begins at index ’start’ and is of
**     maximum size `len`.
**
** PARAMETERS
**   @param `s`       The string from which to create the substring.
**   @param `start`   The start index of the substring in the string `s`.
**   @param `len`     The maximum length of the substring.
**
** RETURN
**   The substring. NULL if the allocation fails.
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
	ft_bzero(buff, (sizeof(char) * len + 1));
	if (start >= eol_len(s, 3))
		return (buff);
	while (start--)
		s1++;
	while (i < len)
	{
		buff[i] = *s1;
		i++;
		s1++;
	}
	return (buff);
}

/*
**   ft_bzero();
**
** DESCRIPTION
**   The function erases the data in the n bytes of the memory
**     starting at the location pointed to by s, by writing
**     zeros(bytes containing '\0') to that area.
**
** PARAMETERS
**   @param `s`   An existing object that you want to fill with zeroes.
**   @param `n`   The number of bytes to fill.
**
** RETURN
**   None.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char *s1;

	s1 = s;
	if (n)
		while (n--)
			s1[n] = 0;
}

/*
**   clean_tmp();
**
** DESCRIPTION
**   Will remove all charater precede the first '\n' find and.
**
** PARAMETERS
**   @param `tmp`   Pointer to a string.
**
** RETURN
**   1 if successful.
**   0 if failed.
*/

int			clean_tmp(char **tmp)
{
	size_t	len;
	size_t	start;
	char	*buff;

	start = eol_len(*tmp, 2);
	len = eol_len(*tmp, 3) - start;
	if (!(buff = ft_substr(*tmp, start + 1, len)))
		return (0);
	free(*tmp);
	*tmp = buff;
	return (1);
}
