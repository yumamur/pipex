/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:45:49 by yumamur           #+#    #+#             */
/*   Updated: 2023/02/13 18:50:36 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

static char	*get_to_second_line(char *keep)
{
	char	*ret;
	int		i1;
	int		i2;

	i1 = 0;
	while (keep[i1] && keep[i1] != '\n')
		i1++;
	if (!keep[i1])
	{
		free(keep);
		return (NULL);
	}
	ret = malloc(ft_strlen(keep) - i1);
	if (!ret)
		return (NULL);
	i2 = 0;
	i1++;
	while (keep[i1])
		ret[i2++] = keep[i1++];
	ret[i2] = '\0';
	ft_free_pt(keep);
	return (ret);
}

char	*get_first_line(t_c_char *keep)
{
	int		i;
	char	*ret;

	i = 0;
	if (!keep[i])
		return (NULL);
	while (keep[i] && keep[i] != '\n')
		i++;
	ret = malloc(i + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (keep[i] && keep[i] != '\n')
	{
		ret[i] = keep[i];
		i++;
	}
	if (keep[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*read_line(char *keep, int fd)
{
	char	*concat;
	int		bytes_readed;

	concat = malloc(BUFFER_SIZE + 1);
	if (!concat)
		return (NULL);
	bytes_readed = 1;
	while (bytes_readed != 0 && !ft_strctrl(keep, '\n'))
	{
		bytes_readed = read(fd, concat, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			ft_free_pt(keep);
			ft_free_pt(concat);
			return (NULL);
		}
		concat[bytes_readed] = '\0';
		keep = ft_strjoin_to_s1(keep, concat);
	}
	ft_free_pt(concat);
	return (keep);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*keep;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	keep = read_line(keep, fd);
	if (!keep)
		return (NULL);
	ret = get_first_line(keep);
	keep = get_to_second_line(keep);
	return (ret);
}
