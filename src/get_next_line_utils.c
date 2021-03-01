/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/01 11:04:45 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*
**   If `mode` == 1 Will return `len` of the string and will ignore `c`.
**   If `mode` == 2 Will return the number of characters preceding
**   `c` and itself.
**
**   @param `str`   The srting we're looking for the `c` caracter.
**   @param `c`     The caratere we're looking for.
**   @param `mode`  The count type.
**
**   @return `len` or -1 if NULL string.
*/
ssize_t		diyStrLen(char *str, char c, int mode)
{
	ssize_t	len;

	len = -1;
	if (!str)
		return (-1);
	if (mode == 1)
	{
		(void)c;
		while (str[++len])
			;
		return (len);
	}
	else if (mode == 2)
	{
		while (str[++len])
			if (str[len] == c)
				return (len);
//		if (str[len] == c)
//			return (++len);
		return (0);
	}
		return (0);
}

/*
**
**   Will free the adresse pointed by `addr` and return `ret`.
**
**   @param `addr`  Pointer to adresse.
**   @param `ret`   What we will return.
**
**   @return `ret`.
*/
int		retFree(char **addr, int ret)
{
	free(*addr);
	return (ret);
}

/*
**   Will contanenate `dest` en `s1` (malloc, free).
**
**   @param `dest`  The destination.
**   @param `s1`    The string to add @ `dest`.
**
**   @return  1 or -1 if malloc fail.
*/
int		joinStr(char **dest, char *s1)
{
	char	*ret;
	ssize_t	lS1;
	ssize_t	lDest;

	lS1 = diyStrLen(s1, '\0', 1);
	if ((lDest = diyStrLen(*dest, '\0', 1)) < 0)
		lDest = 0;
	printf("lDest: %lu, lS1: %lu\n", lDest, lS1);
	if (!(ret = (char*)malloc(lS1 + lDest + 1)))
		return (-1);
	ret[lS1 + lDest] = '\0';
	while (--lS1 >= 0)
		ret[lS1 + lDest] = s1[lS1];
	while (--lDest >= 0)
		ret[lDest] = (*dest)[lDest];
	free(*dest);
	*dest = ret;
	return (1);
}

/*
**
**
**   @param `tmp`
**
**   @return 1 or -1 if malloc fail / `tmp` = NULL.
char	*tmpClean(char **tmp)
{

	return (ret);
}
*/

/*
**   Will return a string of all character preceding '\n' (malloc).
**
**
**   @param `tmp`
*/
char	*retNextLine(char **tmp)
{
	char	*ret;
	ssize_t	len;

	len = diyStrLen(*tmp, '\n', 2);
	if (!(ret = (char*)malloc(len + 1)))
		return (NULL);
	ret[len] = '\0';
	while (--len >= 0 && (*tmp)[len])
		ret[len] = (*tmp)[len];
	return (ret);
}