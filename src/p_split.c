/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:50:59 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/25 01:30:58 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static size_t	arrcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c && *(s - 1) != c)
			break ;
		if (*s != c)
			i++;
		s++;
	}
	return (i);
}

static char	**splinter(const char *str, char c, char **pt, size_t count)
{
	size_t	n;

	n = 0;
	if (count != 0)
	{
		while (*str != '\0')
		{
			count = 0;
			pt[n] = malloc((ft_wordlen(str, c) + 2) * sizeof(*str));
			if (!pt[n])
				return (NULL);
			while (*str != c && *str != '\0')
				pt[n][count++] = *(str++);
			if (*str == '\0')
				str--;
			pt[n][count++] = '/';
			pt[n][count] = '\0';
			str++;
			while (*str == c && *str != '\0')
				str++;
			n++;
		}
	}
	pt[n] = NULL;
	return (pt);
}

char	**p_split(const char *str, char c)
{
	size_t	count;
	char	**pt;

	if (!str || str[0] == 0)
	{
		pt = malloc(sizeof(pt));
		if (!pt)
			return (NULL);
		pt[0] = NULL;
		return (pt);
	}
	while (*str == c)
		str++;
	count = arrcount(str, c);
	pt = malloc((count + 1) * sizeof(str));
	if (!pt)
		return (NULL);
	splinter(str, c, pt, count);
	return (pt);
}
