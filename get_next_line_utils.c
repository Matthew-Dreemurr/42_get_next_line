/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhadad <mhadad@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:18:40 by mhadad            #+#    #+#             */
/*   Updated: 2021/03/06 16:27:10 by mhadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
**
**
*/

int		freeRetun(void **addr, int ret)
{
	if (*addr)
		free (*addr);
	return (ret);
}

/*
**
**
*/
ssize_t		lenStr(const char *str, int c, int mode)//TODO return 0 if `c` not found
{
	ssize_t	len;

#ifdef DEBUG
	printf("call lenStr mode: %d\n", mode);
#endif
	if (!str)
	{
#ifdef DEBUG
		printf("lenStr NULL ret: 0\n");
#endif
		return (0);
	}
	if (mode == 1)
	{
		len = -1;
		while (str[++len])
			if (str[len] == (char)c)
				break;
		if (str[len] != (char)c)
		{
#ifdef DEBUG
			printf("lenStr ret: 0\n");
#endif
			return (0);
		}
	}
	if (mode == 2)
	{
		len = -1;
		while (str[++len])
			if (str[len] == (char)c)
			{
#ifdef DEBUG
				printf("lenStr ret: 1\n");
#endif
				return (1);
			}
#ifdef DEBUG
		printf("lenStr ret: 0\n");
#endif
		return (0);
	}
#ifdef DEBUG
	printf("lenStr ret: %lu\n", len);
#endif
	return (len);
}
/*
**
**
*/

char	*joinStr(char *s1, const char *s2)
{
	ssize_t	len_s1;
	ssize_t	len_s2;
	char	*ret;

	len_s1 = lenStr(s1, '\0', 1);
	len_s2 = lenStr(s2, '\0', 1);
	if (!(ret = malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	ret[len_s1 + len_s2] = '\0';
	while (len_s2 > 0 && s2[--len_s2])
		ret[len_s1 + len_s2] = s2[len_s2];
	while (len_s1 > 0 && s1[--len_s1])
		ret[len_s1] = s1[len_s1];
	free(s1);
	return (ret);
}

/*
**
**
*/

char	*nextLine(char	**str)
{
	ssize_t	len;
	ssize_t	i;
	char	*ret;
	char	*str_cpy;

	i = 0;
	len = lenStr(*str, '\n', 1);
	if (!(lenStr(*str, '\n', 2)))
		return (*str);
	if (!(ret = malloc(len + 1)))
		return (NULL);
	str_cpy = *str;
	ret[len] = '\0';
	while (len > i)
	{
		ret[i++] = *str_cpy;
		str_cpy++;
	}
	str_cpy++;
	len = 0;
	while (*str_cpy)
	{
		(*str)[len] = *str_cpy;
		str_cpy++;
		len++;
	}
	(*str)[len] = '\0';
#ifdef DEBUG
	printf("nextLine **str: |%s| ret: |%s|\n", *str, ret);
#endif
	return (ret);
}