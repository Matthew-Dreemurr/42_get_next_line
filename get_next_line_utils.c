/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:38:31 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/11 16:51:29 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**   Will return the pointed adresse en return `ret`. (Free)
**
**   @param  `addr`   Pointer to the adresse to free.
**   @param  `ret`    Value will be return.
**
**   @return  `ret`.
*/

int			free_return(void **addr, int ret)
{
	if (addr && *addr)
	{
		free(*addr);
		*addr = NULL;
	}
	return (ret);
}

/*
**   If `mode` == 1 will return the number of caracter predece the first
**   `c` encountered.
**   If `mode` == 2 Will return bool if the `c` exist in the sting.
**
**   @param `str`    The string.
**   @param `c`      Ascii caracter.
**   @param `mode`   If 1: strlen to `c`, if 2: bool (`c` exist) ? 1 : 0.
**
**   @return
*/

ssize_t		lentochar(const char *str, int c, int mode)
{
	ssize_t	len;

	if (!str)
		return (FALSE);
	if (mode == 1)
	{
		len = -1;
		while (str[++len])
			if (str[len] == (char)c)
				break ;
		if (str[len] != (char)c)
			return (FALSE);
	}
	if (mode == 2)
	{
		len = -1;
		while (str[++len])
			if (str[len] == (char)c)
				return (TRUE);
		return (FALSE);
	}
	return (len);
}

/*
**   Will join s1 & s2, before return will free `s1` or `s2` if `freeS1`
**    is true. (Malloc, Free)
**
**   @param   `s1`  Fisrt string.
**   @param   `s2`  Secound strin.
**
**   @return  A string with the contatenate of s1 and s2
*/

char		*join_str(char *s1, char *s2, char **tofree)
{
	ssize_t	len_s1;
	ssize_t	len_s2;
	char	*ret;

	len_s1 = lentochar(s1, '\0', 1);
	len_s2 = lentochar(s2, '\0', 1);
	if (!(ret = (char*)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	ret[len_s1 + len_s2] = '\0';
	while (len_s2 > 0 && s2[--len_s2])
		ret[len_s1 + len_s2] = s2[len_s2];
	while (len_s1 > 0 && s1[--len_s1])
		ret[len_s1] = s1[len_s1];
	if (tofree && *tofree)
	{
		free(*tofree);
		*tofree = NULL;
	}
	return (ret);
}

/*
**   Will return a string with all caractere precede the first newline occured
**    and will remove those character form `str`. (Malloc)
**
**   @param  `str`  Pointer of adresse.
*/

char		*next_line(char **str)
{
	ssize_t	len;
	ssize_t	i;
	char	*ret;
	char	*str_cpy;

	i = 0;
	len = lentochar(*str, '\n', 1);
	if (!(lentochar(*str, '\n', 2)))
		return (join_str(*str, NULL, NULL));
	if (!(ret = (char*)malloc(len + 1)))
		return (NULL);
	str_cpy = *str;
	ret[len] = '\0';
	while (len > i)
		ret[i++] = *str_cpy++;
	str_cpy++;
	len = 0;
	while (*str_cpy)
		(*str)[len++] = *str_cpy++;
	(*str)[len] = '\0';
	return (ret);
}
