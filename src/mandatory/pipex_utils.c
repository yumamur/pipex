/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:10:28 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/02 14:58:58 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	handle_error(char errmsg[])
{
	if (!errmsg)
		write(2, "Error: Invalid argument count", 29);
	else
		perror(errmsg);
	exit(1);
}

void	add_cmd(char *allpaths[], char *cmd)
{
	char	*tmp1;
	char	*tmp2;

	while (*allpaths)
	{
		tmp1 = ft_strjoin(*(const char **)allpaths, "/");
		tmp2 = ft_strjoin((const char *)tmp1, (const char *)cmd);
		free(tmp1);
		free(*allpaths);
		*allpaths = tmp2;
		tmp2 = NULL;
		allpaths++;
	}
}

const char	*get_path(char *cmd, char *envp[])
{
	char	**allpaths;
	char	*ret;

	allpaths = ft_split(ft_getenv((const char **)envp, "PATH"), ':');
	add_cmd(allpaths, cmd);
	ret = *allpaths;
	while (ret)
	{
		if (access((const char *)ret, F_OK))
		{
			ret = ft_strdup(ret);
			ft_freesplit(allpaths);
			return ((const char *)ret);
		}
		ret++;
	}
	return (NULL);
}
